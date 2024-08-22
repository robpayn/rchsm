# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   Value Object
#'
#' @description
#'   An R6 class mapping to a C++ Value object
#'
#'   Implementation is provided by C++ objects.
#'
C_Value <- R6Class(
  classname = "C_Value",
  inherit = C_Object,
  public = list(
    
    #' @description 
    #'   Create a new instance of a Value class
    #'   
    #' @param type
    #'   Character string with the name of the type of value to be created
    #' @param initValue
    #'   Initial value of the new Value object. The type of this argument
    #'   must be consistent with the type of the value created.
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered 
    #'   (TRUE) or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(type, initValue, regFinalizer = FALSE)
    {
      super$initialize(
        className = type, 
        initValue = initValue, 
        regFinalizer = regFinalizer
      )
    }
    
  )
)
    