
library(rchsm, lib.loc = "./build")

# blah <- C_Cell$new("blah")
# 
beh <- C_BehCellDOConc$new()
# 
# beh$createVariables(holon = blah)

model <- C_Model$new()

cell <- model$createCell(name = "Cell01")

cell2 <- model$createCell(name = "Cell02")

bound <- model$createBound(name = "Bound01", cellFrom = cell, cellTo = cell2)
