#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Install order dependency manager object
#'
#' @description
#'   An R reference to a install order dependency manager.
#'
#'   Implementation is provided by C++ objects.
#'
C_DepManInstallOrder <- R6Class(
  classname = "C_DepManInstallOrder",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Create an instance of the dependency manager
    #' @param numPhases
    #'   Number of phases for dynamic value updates
    #' @param className
    #'   (Optional) Character string with the name of the class.
    #'     Defaults to "DepManInstallOrder".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      numPhases, 
      className = "DepManInstallOrder", 
      regFinalizer = FALSE
    ) 
    {
      super$initialize(
        className = className, 
        numPhases, 
        regFinalizer = regFinalizer
      )
    }
    
  )
)
