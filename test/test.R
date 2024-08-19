
library(rchsm, lib.loc = "./build")

model <- C_Model$new(
  depManager = C_Object$new(
    className = "DepManInstallOrder", 
    numPhases = 3,
    regFinalizer = FALSE
  ), 
  solver = C_Object$new(
    className = "SolverForwardEuler", 
    regFinalizer = FALSE
  )
)

cell <- C_Cell$new(source = model$createCell("CellTime"))
beh <- C_Behavior$new(className = "BehCellTime")
beh$createVariables(
  machine = model, 
  holon = cell,
  initTime = 0,
  initIteration = 0,
  initTimeValid = TRUE,
  initTimeMax = 50
)

bound <- C_Bound$new(source = model$createBound("BoundTime", NULL, cell))
beh <- C_Behavior$new(className = "BehBoundTime")
beh$createVariables(
  machine = model, 
  holon = bound, 
  initTimeStep = 2
)

reporter <- C_Object$new(
  className = "ReporterTable", 
  interval = 1, 
  regFinalizer = FALSE
)
model$callFunction(fun = "installReporter", reporter$.external)
reporter$callFunction(
  "trackVariable", 
  cell$callFunction("getVariable", "Iteration", cClassName = "Holon")
)
reporter$callFunction(
  "trackVariable", 
  cell$callFunction("getVariable", "Time", cClassName = "Holon")
)


cell <- C_Cell$new(model$createCell("Cell01"))
beh <- C_Behavior$new(className = "BehCellSolute", "Nitrate")
beh$createVariables( 
  machine = model, 
  holon = cell, 
  initNitrate = 10
)
reporter$callFunction(
  "trackVariable", 
  cell$callFunction("getVariable", "NitrateConc", cClassName = "Holon")
)

bound <- C_Bound$new(model$createBound("Bound01", NULL, cell))
beh <- C_Behavior$new(className = "BehBoundFirstOrder", "Nitrate")
beh$createVariables(
  machine = model,
  holon = bound,
  initRate = 0,
  initCoeff = 0.15
)
reporter$callFunction(
  "trackVariable", 
  bound$callFunction("getVariable", "NitrateUptake", cClassName = "Holon")
)

model$callFunction("init")

cat(model$getValueString())

model$callFunction("run")

cat(model$getValueString())

output <- reporter$callFunction("getDataFrame")

plot(output$CellTime.Time, output$Cell01.NitrateConc)
