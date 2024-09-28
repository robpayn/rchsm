rm(list = ls())

library(rchsm, lib.loc = "./build")

model <- C_Model$new(depManager = C_DepManInstallOrder$new(numPhases = 3))
matrix <- model$matrix;

cell <- matrix$createCell(name = "CellTime")
matrix$createVariable(
  name = "Time",
  value = C_Object$new(
    className = "Time",
    initValue = 0,
    phase = 0,
    regFinalizer = FALSE
  ),
  holon = cell
)
matrix$createVariable(
  name = "Iteration",
  value = C_Object$new(
    className = "Iteration",
    initValue = 0,
    phase = 0,
    regFinalizer = FALSE
  ),
  holon = cell
)
matrix$createVariable(
  name = "TimeValid",
  value = C_Object$new(
    className = "TimeValid",
    initValue = TRUE,
    phase = 0,
    regFinalizer = FALSE
  ),
  holon = cell
)
matrix$createVariable(
  name = "TimeMax",
  value = C_ValueDouble$new(initValue = 50),
  holon = cell
)

model$setTimeValidVariable(
  variable = cell$getVariablePointer(name = "TimeValid")
)

reporter <- C_ReporterTable$new(
  interval = 1, 
  iterationVariable = cell$getVariablePointer(name = "Iteration")
)
model$installReporter(reporter = reporter)
reporter$trackVariable(variable = cell$getVariablePointer(name = "Iteration"))
reporter$trackVariable(variable = cell$getVariablePointer(name = "Time"))

timeBound <- matrix$createBound(
  name = "BoundTime", 
  cellFrom = NULL, 
  cellTo = cell
)
timeStepVar <- matrix$createVariable(
  name = "TimeStep",
  value = C_ValueDouble$new(initValue = 1),
  holon = timeBound
)

# matrix$installSolver(
#   solver = C_SolverForwardEuler$new(timeStep = timeStepVar)
# )
# mfDouble <- NULL

matrix$installSolver(
  solver = C_SolverRKTwo$new(timeStep = timeStepVar)
)
mfDouble <- C_MemoryDoubleFactory$new(size = 1)

cell1 <- matrix$createCell(name = "Cell01")
matrix$createVariable(
  name = "SaltConc",
  value = C_Object$new(
    className = "StateDoubleDefined",
    timeHolon = timeBound$.external,
    timeStepName = "TimeStep",
    iterationName = "Iteration",
    values = c(0, 100, rep(0, times = 49)),
    phase = 2,
    mfDouble = mfDouble$.external,
    regFinalizer = FALSE
  ),
  holon = cell1
)
reporter$trackVariable(
  variable = cell1$getVariablePointer(name = "SaltConc")
)

cell2 <- matrix$createCell(name = "Cell02")
matrix$createVariable(
  name = "SaltConc",
  value = C_Object$new(
    className = "StateDouble",
    timeHolon = timeBound$.external,
    timeStepName = "TimeStep",
    initConc = 0,
    phase = 2,
    mfDouble = mfDouble$.external,
    regFinalizer = FALSE
  ),
  holon = cell2
)
reporter$trackVariable(
  variable = cell2$getVariablePointer(name = "SaltConc")
)

bound <- matrix$createBound(name = "Bound01", cellFrom = cell1, cellTo = cell2)
velocityName <- "WaterVelocity"
matrix$createVariable(
  name = "SaltAdvection",
  value = C_Object$new(
    className = "RateAdvection", 
    initValue = 0, 
    stateName = "SaltConc", 
    velocityName = velocityName,
    phase = 1,
    regFinalizer = FALSE
  ),
  holon = bound
)
matrix$createVariable(
  name = velocityName,
  value = C_ValueDouble$new(initValue = 1),
  holon = bound
)
matrix$createVariable(
  name = "SpaceLength",
  value = C_ValueDouble$new(initValue = 10),
  holon = bound
)

reporter$trackRate(
  variable = bound$getVariablePointer(name = "SaltAdvection"),
  from = FALSE
)

cat(model$getValueString())

model$run()

cat(model$getValueString())

output <- reporter$getDataFrame()

windows(width = 8, height = 10)
par(mfrow = c(2, 1), mai = c(1, 0.8, 0.1, 0.1))
plot(
  x = output$CellTime.Time, 
  y = output$Cell01.SaltConc, 
  type = "l"
)
plot(
  x = output$CellTime.Time, 
  y = output$Cell02.SaltConc, 
  type = "l",
  lty = "dashed"
)
