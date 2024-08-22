library(rchsm, lib.loc = "./build")

model <- C_Model$new(
  depManager = C_DepManInstallOrder$new(numPhases = 3), 
  solver = C_SolverForwardEuler$new()
)

cell <- model$createCell("CellTime")
beh <- C_Behavior$new(className = "BehCellTime")
beh$createVariables(
  machine = model, 
  holon = cell,
  initTime = 0,
  initIteration = 0,
  initTimeValid = TRUE
)
model$createVariable(
  name = "TimeMax",
  value = C_Value$new(type = "ValueDouble", initValue = 40),
  holon = cell
)

bound <-model$createBound("BoundTime", NULL, cell)
model$createVariable(
  name = "TimeStep",
  value = C_Value$new(type = "ValueDouble", initValue = 1),
  holon = bound
)

reporter <- C_ReporterTable$new(interval = 1)
model$installReporter(reporter)
reporter$trackVariable(variable = cell$getVariablePointer("Iteration"))
reporter$trackVariable(variable = cell$getVariablePointer("Time"))


cell <-model$createCell("Cell01")
beh <- C_Behavior$new(className = "BehCellSolute", "Nitrate")
beh$createVariables( 
  machine = model, 
  holon = cell, 
  initNitrate = 10
)
reporter$trackVariable(variable = cell$getVariablePointer("NitrateConc"))

bound <- model$createBound("Bound01", NULL, cell)
beh <- C_Behavior$new(className = "BehBoundFirstOrder", "Nitrate")
beh$createVariables(
  machine = model,
  holon = bound,
  initRate = 0
)
model$createVariable(
  name = "NitrateRateCoeff",
  value = C_Value$new(type = "ValueDouble", initValue = 0.2),
  holon = bound
)
reporter$trackVariable(variable = bound$getVariablePointer("NitrateUptake"))

model$init()

cat(model$getValueString())

model$run()

cat(model$getValueString())

output <- reporter$callFunction("getDataFrame")

plot(output$CellTime.Time, output$Cell01.NitrateConc)
