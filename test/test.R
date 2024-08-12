
library(rchsm, lib.loc = "./build")

model <- C_Model$new()

.cell <- model$createCell(name = "CellTime")
beh <- C_Behavior$new("BehCellTime")
beh$createVariables(
  .machine = model$.external, 
  .holon = .cell,
  initTime = 0,
  initIteration = 0,
  initTimeValid = TRUE,
  initTimeMax = 10
)

.bound <- model$createBound(
  name = "BoundTime",
  .cellFrom = NULL,
  .cellTo = .cell
)
beh <- C_Behavior$new("BehBoundTime")
beh$createVariables(
  .machine = model$.external, 
  .holon = .bound, 
  initTimeStep = 2
)

.cell <- model$createCell(name = "Cell01")
.cell2 <- model$createCell(name = "Cell02")

.bound <- model$createBound(
  name = "Bound01",
  .cellFrom = .cell,
  .cellTo = .cell2
)

beh <- C_Behavior$new("BehCellDOConc")
beh$createVariables(.machine = model$.external, .holon = .cell, initDOConc = 8)

model$callFunction("init")

cat(model$getValueString())

model$callFunction("run")

cat(model$getValueString())
