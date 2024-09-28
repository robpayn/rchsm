rm(list = ls())

library(rchsm, lib.loc = "./build")

initConc = 10
rateCoeff = 0.1
timeStep = 2
maxTime = 40

model <- C_Model$new(depManager = C_DepManInstallOrder$new(numPhases = 3))
matrix <- model$matrix;

timeCell <- matrix$createCell(name = "CellTime")
matrix$createVariable(
  name = "Time",
  value = C_Object$new(
    className = "Time",
    initValue = 0,
    phase = 0,
    regFinalizer = FALSE
  ),
  holon = timeCell
)
matrix$createVariable(
  name = "Iteration",
  value = C_Object$new(
    className = "Iteration",
    initValue = 0,
    phase = 0,
    regFinalizer = FALSE
  ),
  holon = timeCell
)
matrix$createVariable(
  name = "TimeValid",
  value = C_Object$new(
    className = "TimeValid",
    initValue = TRUE,
    phase = 0,
    regFinalizer = FALSE
  ),
  holon = timeCell
)
matrix$createVariable(
  name = "TimeMax",
  value = C_ValueDouble$new(initValue = maxTime),
  holon = timeCell
)

model$setTimeValidVariable(
  variable = timeCell$getVariablePointer(name = "TimeValid")
)
reporter <- C_ReporterTable$new(
  interval = 1, 
  iterationVariable = timeCell$getVariablePointer(name = "Iteration")
)
model$installReporter(reporter = reporter)

reporter$trackVariable(
  variable = timeCell$getVariablePointer(name = "Iteration")
)
reporter$trackVariable(
  variable = timeCell$getVariablePointer(name = "Time")
)

timeBound <- matrix$createBound(
  name = "BoundTime", 
  cellFrom = NULL, 
  cellTo = timeCell
)
timeStepVar <- matrix$createVariable(
  name = "TimeStep",
  value = C_ValueDouble$new(initValue = timeStep),
  holon = timeBound
)

matrix$installSolver(solver = C_SolverForwardEuler$new(timeStep = timeStepVar))


cell <- matrix$createCell(name = "Cell01")
matrix$createVariable(
  name = "NitrateConc",
  value = C_Object$new(
    className = "StateDouble",
    timeHolon = timeBound$.external,
    timeStepName = "TimeStep",
    initConc = initConc,
    phase = 2,
    mfDouble = NULL,
    regFinalizer = FALSE
  ),
  holon = cell
)
reporter$trackVariable(
  variable = cell$getVariablePointer(name = "NitrateConc")
)

bound <- matrix$createBound(name = "Bound01", cellFrom = NULL, cellTo = cell)
matrix$createVariable(
  name = "NitrateRate",
  value = C_Object$new(
    className = "RateFirstOrder",
    initValue = 0,
    stateName = "NitrateConc",
    coeffName = "NitrateRateCoeff",
    phase = 1,
    regFinalizer = FALSE
  ),
  holon = bound
)
matrix$createVariable(
  name = "NitrateRateCoeff",
  value = C_ValueDouble$new(initValue = rateCoeff),
  holon = bound
)

reporter$trackRate(
  variable = bound$getVariablePointer(name = "NitrateRate"),
  from = FALSE
)

cat(model$getValueString())

model$run()

cat(model$getValueString())

output <- reporter$getDataFrame()

plot(x = output$CellTime.Time, y = output$Cell01.NitrateConc)

t = seq.default(from = 0, to = maxTime, length.out = 50)
lines(x = t, y = initConc * exp(-rateCoeff * t))

