# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Holon Object
#'
#' @description
#'   A holon in a composite Hierarchy State Machine
#'
#'   Implementation is provided by C++ objects.
#'
C_Holon <- R6Class(
  classname = "C_Holon",
  inherit = C_Variable,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param className
    #'   (Optional) Name of the class used in accessing c++ functions.
    #'   Default value is "Holon"
    #' @param ...
    #'   Abstract arguments passed to the constructor of the super class
    #' @param regFinalizer
    #'   Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   See super class C_Object for more information.
    #' @param .external
    #'   (Optional) If an external pointer is provided instead of the default
    #'   NULL value, then the new R6 object will be associated with the 
    #'   existing C++ Object referenced by the pointer.
    #' 
    initialize = function(className, ..., regFinalizer, .external = NULL) 
    {
      super$initialize(
        className = className, 
        ...,
        regFinalizer = regFinalizer,
        .external = .external
      )
    },
    
    #' @description
    #'   Get an external pointer to the named variable
    #'   
    #' @param name
    #'   Character string with the name of the variable to retrieve
    #'   
    #' @return 
    #'   An external pointer to the variable
    getVariablePointer = function(name) 
    {
      return(
        self$callFunction(fun = "getVariable", name, cClassName = "Holon")
      )
    }
    
  )
)
