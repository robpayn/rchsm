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
    #' @param className
    #'   Character string with the name of the type of value to be created
    #' @param ...
    #'   Generic arguments passed on to the value constructor.
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered 
    #'   (TRUE) or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(className, ..., regFinalizer = FALSE)
    {
      super$initialize(
        className = className, 
        ..., 
        regFinalizer = regFinalizer
      )
    }
    
  )
)

#' @export
#'
#' @title
#'   A double precision floating point value
#'
#' @description
#'   An R6 class mapping to a C++ Value object
#'
#'   Implementation is provided by C++ objects.
#'
C_ValueDouble <- R6Class(
  classname = "C_ValueDouble",
  inherit = C_Value,
  public = list(
    
    #' @description 
    #'   Create a new instance of a ValueDouble class
    #'   
    #' @param initValue
    #'   A numeric for the initial value of the variable
    #' @param className
    #'   (Optional) Character string with the name of the type of value 
    #'   to be created.
    #'   Default value is "ValueDouble".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered 
    #'   (TRUE) or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      initValue, 
      className = "ValueDouble", 
      regFinalizer = FALSE
    )
    {
      super$initialize(
        className = className, 
        initValue, 
        regFinalizer = regFinalizer
      )
    }
    
  )
)