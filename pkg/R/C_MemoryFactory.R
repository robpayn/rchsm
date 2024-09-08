# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   A memory factory for a value
#'
#' @description
#'   An R6 class mapping to a C++ Value object
#'
#'   Implementation is provided by C++ objects.
#'
C_MemoryFactory <- R6Class(
  classname = "C_MemoryFactory",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Create a new instance of a memory factory
    #'   
    #' @param className
    #'   The name of the C class for the memory factory
    #' @param size
    #'   The size of the memory the factory should create
    #' @param ...
    #'   Generic arguments to be passed on to the constructor
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be 
    #'   registered (TRUE) or not (FALSE).
    #'   Defaults to FALSE
    #'   See super class C_Object for more information.
    #' 
    initialize = function(className, size, ..., regFinalizer = TRUE)
    {
      super$initialize(
        className = className, 
        size,
        ..., 
        regFinalizer = regFinalizer
      )
    }
    
  )
)

#' @export
#'
#' @title
#'   A memory factory for a double precision floating point value
#'
#' @description
#'   An R6 class mapping to a C++ Value object
#'
#'   Implementation is provided by C++ objects.
#'
C_MemoryDoubleFactory <- R6Class(
  classname = "C_MemoryDoubleFactory",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Create a new instance of a memory factory
    #'   
    #' @param size
    #'   The size of the memory the factory should create
    #' @param className
    #'   (Optional) The name of the C class for the memory factory.
    #'   Default value is "MemoryDoubleFactory".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be 
    #'   registered (TRUE) or not (FALSE).
    #'   Defaults to FALSE
    #'   See super class C_Object for more information.
    #' 
    initialize = function(
      size, 
      className = "MemoryDoubleFactory", 
      regFinalizer = TRUE
    )
    {
      super$initialize(
        className = className, 
        size,
        regFinalizer = regFinalizer
      )
    }
    
  )
)
