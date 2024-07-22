
library(rchsm, lib.loc = "./build")

blah <- C_Cell$new("blah")

beh <- C_BehCellDOConc$new()

beh$createVariables(holon = blah)
