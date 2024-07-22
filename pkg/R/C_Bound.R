# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   Bound Object
#'
#' @description
#'   An R6 class mapping to a C++ Bound object
#'
#'   Implementation is provided by C++ objects.
#'
C_Bound <- R6Class(
  classname = "C_Bound",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param name
    #'   Name of the bound
    initialize = function(name) {
      super$initialize("Bound", name)
    }
    
  )
)