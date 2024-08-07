
library(rchsm, lib.loc = "./build")


model <- C_Model$new()

.cell <- model$createCell(name = "CellTime")
beh <- C_Behavior$new("BehCellTime")
beh$createVariables(.machine = model$.external, .holon = .cell)

.bound <- model$createBound(
  name = "BoundTime",
  .cellFrom = NULL,
  .cellTo = .cell
)
beh <- C_Behavior$new("BehBoundTime")
beh$createVariables(.machine = model$.external, .holon = .bound)

.cell <- model$createCell(name = "Cell01")
.cell2 <- model$createCell(name = "Cell02")

.bound <- model$createBound(
  name = "Bound01",
  .cellFrom = .cell,
  .cellTo = .cell2
)
beh <- C_Behavior$new("BehCellDOConc")
beh$createVariables(.machine = model$.external, .holon = .bound)

cat(model$getValueString())

