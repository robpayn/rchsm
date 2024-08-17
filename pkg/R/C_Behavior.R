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
    #' @param ...
    #'   Generic arguments that will be passed on to the C constructor
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to TRUE.
    #'   See super class C_Object for more information.
    #'
    initialize = function(className, ..., regFinalizer = TRUE) {
      super$initialize(
        className = className,
        ...,
        regFinalizer = regFinalizer
      )
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon.
    #'
    #' @param machine
    #'   The machine object where the variables should be registered.
    #' @param holon
    #'   The holon object where the variables should be created.
    #' @param ...
    #'   Further arguments to be passed on to the associated C function.
    #'   These are often initial values for the variable being created.
    #'   
    createVariables = function(machine, holon, ...) {
      
      return(
        self$callFunction(
          fun = "createVariables",
          machine$.external,
          holon$.external,
          ...
        )
      )
      
    }
    
  )
)