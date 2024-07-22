# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   Cell Object
#'
#' @description
#'   An R6 class mapping to a C++ Cell object
#'
#'   Implementation is provided by C++ objects.
#'
C_Cell <- R6Class(
  classname = "C_Cell",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param name
    #'   Name of the cell
    initialize = function(name) {
      super$initialize("Cell", name)
    }
    
  )
)