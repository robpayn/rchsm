
library(rchsm, lib.loc = "./build")


model <- C_Model$new()

cell <- C_Cell$new(
  model$createCell(name = "Cell01")
)

beh <- C_BehCellDOConc$new()

beh$createVariables(.holon = cell$.external)


cell2 <- C_Cell$new(
  model$createCell(name = "Cell02")
)

bound <- C_Bound$new(
  model$createBound(
    name = "Bound01", 
    .cellFrom = cell$externalPointer, 
    .cellTo = cell2$externalPointer
  )
)

cat(model$getValueString())
