#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM iteration interval reporter object
#'
#' @description
#'   An R reference to an iteration interval reporter object
#'
#'   Implementation is provided by C++ objects.
#'
C_ReporterInterval <- R6Class(
  classname = "C_ReporterInterval",
  inherit = C_Object,
  public = list(
    #' @description
    #'   Create an instance of the reporter
    #'   
    #' @param className
    #'   Character string with the name of the class.
    #' @param interval
    #'   Integer defining the iteration interval for reporting
    #' @param iterationVariable
    #'   Variable with the iteration counter value
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      className,
      interval,
      iterationVariable,
      regFinalizer = FALSE
    )
    {
      super$initialize(
        className = className, 
        interval, 
        if (typeof(iterationVariable) == "externalptr")
          iterationVariable
        else
          if (any(class(iterationVariable) == "C_Variable"))
            iterationVariable$.external
          else
            stop(
              "Invalid iteration variable argument for an interval reporter."
            ),
        regFinalizer = regFinalizer
      )
    }
  )
)

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
  inherit = C_ReporterInterval,
  public = list(
    
    #' @description
    #'   Create an instance of the reporter
    #'   
    #' @param interval
    #'   Integer defining the iteration interval for reporting
    #' @param iterationVariable
    #'   Variable with the iteration counter value
    #' @param className
    #'   (Optional) Character string with the name of the class.
    #'   Defaults to "ReporterTable".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      interval,
      iterationVariable,
      className = "ReporterTable",
      regFinalizer = FALSE
    ) 
    {
      super$initialize(
        className = className,
        interval = interval,
        iterationVariable = iterationVariable,
        regFinalizer = regFinalizer
      )
    },
    
    getDataFrame = function()
    {
      self$callFunction(fun = "getDataFrame")
    },
    
    #' @description 
    #'   Designate a rate variable with value(s) to be tracked by the reporter
    #'   
    #' @param variable
    #'   Either an external pointer or an R6 object referring to the rate 
    #'   variable to be tracked.
    #' @param from
    #'   Logical TRUE if the rate value on the to side should be added, 
    #'   FALSE if not.
    #' @param to
    #'   Logical TRUE if the rate value on the from side should be added,
    #'   FALSE if not.
    #'   
    trackRate = function(variable, from = TRUE, to = TRUE)
    {
      self$callFunction(
        fun = "trackRate", 
        if (typeof(variable) == "externalptr")
          variable
        else
          if (any(class(variable) == "C_Variable"))
            variable$.external
          else
            stop(
              "Invalid variable argument to the track rate method."
            ),
        from, 
        to
      )
      invisible(NULL)
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
      self$callFunction(
        fun = "trackVariable", 
        if (typeof(variable) == "externalptr")
          variable
        else
          if (any(class(variable) == "C_Variable"))
            variable$.external
          else
            stop(
              "Invalid variable argument to the track variable method."
            )
      )
      invisible(NULL)
    }
    
  )
)
