dir.create(path = "./build", showWarnings = FALSE)
install.packages(
  pkgs = "../pkg", 
  repos = NULL, 
  type = "source", 
  lib = "./build"
)
