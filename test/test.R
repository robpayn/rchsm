
library(rchsm, lib.loc = "./build")

blah <- C_Cell$new("blah")

beh <- C_BehDOConcCell$new()

beh$createVariables(holon = blah)
