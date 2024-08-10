# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   A CHSM Behavior
#'
#' @description
#'   An R6 class mapping to a C++ composite Hierarchy State Machine object
#'
#'   Implementation is provided by C++ objects.
#'
C_Behavior <- R6Class(
  classname = "C_Behavior",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #' 
    #' @param className
    #'   The name of the associated C class
    #'
    initialize = function(className) {
      super$initialize(className = className)
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon.
    #'
    #' @param .machine
    #'   The machine object where the variables should be registered.
    #' @param .holon
    #'   The holon object where the variables should be created.
    #' @param ...
    #'   Initial value arguments to be passed on to the associated C function.
    #'   
    createVariables = function(.machine, .holon, ...) {
      
      return(
        self$callFunction(
          name = "createVariables",
          .machine,
          .holon,
          ...
        )
      )
      
    }
    
  )
)