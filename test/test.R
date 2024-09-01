library(rchsm, lib.loc = "./build")

initConc = 10
rateCoeff = 0.1
timeStep = 2
maxTime = 40

model <- C_Model$new(depManager = C_DepManInstallOrder$new(numPhases = 3))
matrix <- model$matrix;

cell <- matrix$createCell("CellTime")
beh <- C_Behavior$new(className = "BehCellTime")
beh$createVariables(
  matrix = matrix, 
  holon = cell,
  initTime = 0,
  initIteration = 0,
  initTimeValid = TRUE
)
matrix$createVariable(
  name = "TimeMax",
  value = C_Value$new(type = "ValueDouble", initValue = maxTime),
  holon = cell
)

model$setTimeValidVariable(variable = cell$getVariablePointer("TimeValid"))

reporter <- C_ReporterTable$new(
  interval = 1, 
  .iterationVariable = cell$getVariablePointer("Iteration")
)
model$installReporter(reporter)
reporter$trackVariable(variable = cell$getVariablePointer("Iteration"))
reporter$trackVariable(variable = cell$getVariablePointer("Time"))

bound <- matrix$createBound("BoundTime", NULL, cell)
timeStepVar <- matrix$createVariable(
  name = "TimeStep",
  value = C_Value$new(type = "ValueDouble", initValue = timeStep),
  holon = bound
)

matrix$installSolver(C_SolverForwardEuler$new(timeStep = timeStepVar))


cell <-matrix$createCell("Cell01")
beh <- C_Behavior$new(className = "BehCellSolute", "Nitrate")
beh$createVariables( 
  matrix = matrix, 
  holon = cell, 
  initNitrate = initConc
)

reporter$trackVariable(variable = cell$getVariablePointer("NitrateConc"))

bound <- matrix$createBound("Bound01", NULL, cell)
beh <- C_Behavior$new(className = "BehBoundFirstOrder", "Nitrate")
beh$createVariables(
  matrix = matrix,
  holon = bound,
  initRate = 0
)
matrix$createVariable(
  name = "NitrateRateCoeff",
  value = C_Value$new(type = "ValueDouble", initValue = rateCoeff),
  holon = bound
)

reporter$trackRate(
  variable = bound$getVariablePointer("NitrateRate"),
  from = FALSE
)

cat(model$getValueString())

model$run()

cat(model$getValueString())

output <- reporter$callFunction("getDataFrame")

plot(output$CellTime.Time, output$Cell01.NitrateConc)

t = seq.default(from = 0, to = maxTime, by = 0.5)
lines(x = t, y = initConc * exp(-rateCoeff * t))
