
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
  initTimeMax = 10
)

bound <- C_Bound$new(source = model$createBound("BoundTime", NULL, cell))
beh <- C_Behavior$new(className = "BehBoundTime")
beh$createVariables(
  machine = model, 
  holon = bound, 
  initTimeStep = 2
)

cell <- C_Cell$new(model$createCell("Cell01"))
beh <- C_Behavior$new(className = "BehCellDOConc")
beh$createVariables( 
  machine = model, 
  holon = cell, 
  initDOConc = 8
)

bound <- C_Bound$new(model$createBound("Bound01", NULL, cell))
beh <- C_Behavior$new(className = "BehBoundDOMetab")
beh$createVariables(
  machine = model,
  holon = bound,
  initDOGPP = 0.5,
  initDOER = 0.5
)

model$callFunction("init")

cat(model$getValueString())

model$callFunction("run")

cat(model$getValueString())
