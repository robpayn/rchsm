rm(list = ls())

library(rchsm, lib.loc = "./build")

initConc = 10
rateCoeff = 0.1
timeStep = 2
maxTime = 40

model <- C_Model$new(depManager = C_DepManInstallOrder$new(numPhases = 3))
matrix <- model$matrix;

cell <- matrix$createCell(name = "CellTime")
beh <- C_BehCellTime$new()
beh$createVariables(
  matrix = matrix, 
  holon = cell,
  initTime = 0,
  initIteration = 0,
  initTimeValid = TRUE
)
matrix$createVariable(
  name = "TimeMax",
  value = C_ValueDouble$new(initValue = maxTime),
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

bound <- matrix$createBound(name = "BoundTime", cellFrom = NULL, cellTo = cell)
timeStepVar <- matrix$createVariable(
  name = "TimeStep",
  value = C_ValueDouble$new(initValue = timeStep),
  holon = bound
)

matrix$installSolver(
  solver = C_SolverForwardEuler$new(timeStep = timeStepVar)
)


cell <- matrix$createCell(name = "Cell01")
beh <- C_BehCellSolute$new(soluteName = "Nitrate")
beh$createVariables( 
  matrix = matrix,
  holon = cell, 
  initConc = initConc
)

reporter$trackVariable(
  variable = cell$getVariablePointer(name = "NitrateConc")
)

bound <- matrix$createBound(name = "Bound01", cellFrom = NULL, cellTo = cell)
beh <- C_BehBoundFirstOrder$new(soluteName = "Nitrate")
beh$createVariables(
  matrix = matrix,
  holon = bound,
  initRate = 0
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
