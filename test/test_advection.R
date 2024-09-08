rm(list = ls())

library(rchsm, lib.loc = "./build")

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
beh <- C_Behavior$new(className = "BehCellConcDefined", soluteName = "Salt")
beh$createVariables( 
  matrix = matrix,
  holon = cell1, 
  timeHolon = timeBound$.external,
  timeStepName = "TimeStep",
  iterationName = "Iteration",
  initConc = c(
    0,
    100,
    rep(0, times = 49)
  ),
  mfDouble = mfDouble
)
reporter$trackVariable(
  variable = cell1$getVariablePointer(name = "SaltConc")
)

cell2 <- matrix$createCell(name = "Cell02")
beh <- C_BehCellSolute$new(soluteName = "Salt")
beh$createVariables( 
  matrix = matrix,
  holon = cell2, 
  timeHolon = timeBound,
  timeStepName = "TimeStep",
  initConc = 0,
  mfDouble = mfDouble
)
reporter$trackVariable(
  variable = cell2$getVariablePointer(name = "SaltConc")
)

bound <- matrix$createBound(name = "Bound01", cellFrom = cell1, cellTo = cell2)
beh <- C_Behavior$new(
  className = "BehBoundAdvection", 
  soluteName = "Salt"
)
beh$createVariables(
  matrix = matrix,
  holon = bound,
  initRate = 0
)
matrix$createVariable(
  name = "SaltVelocity",
  value = C_ValueDouble$new(initValue = 1),
  holon = bound
)
matrix$createVariable(
  name = "length",
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
