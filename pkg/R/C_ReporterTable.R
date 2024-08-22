#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Table reporter object
#'
#' @description
#'   An R reference to a table reporter object
#'
#'   Implementation is provided by C++ objects.
#'
C_ReporterTable <- R6Class(
  classname = "C_ReporterTable",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Create an instance of the solver
    #'   
    #' @param interval
    #'   Integer defining the iteration interval for reporting
    #' @param className
    #'   (Optional) Character string with the name of the class.
    #'     Defaults to "ReporterTable".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      interval,
      className = "ReporterTable",
      regFinalizer = FALSE
    ) 
    {
      super$initialize(
        className = className,
        interval,
        regFinalizer = regFinalizer
      )
    },
    
    #' @description 
    #'   Designate a variable with a value to be tracked by the reporter
    #'   
    #' @param variable
    #'   Either an external pointer or an R6 object referring to the variable
    #'   to be tracked.
    #'   
    trackVariable = function(variable)
    {
      if(typeof(variable) == "externalptr") {
        self$callFunction(fun = "trackVariable", variable)
      } else if (is.R6(variable)) {
        self$callFunction(fun = "trackVariable", variable$.external)
      } else {
        stop("Provided variable is an invalid type.")
      }
      invisible(NULL)
    }
    
  )
)
