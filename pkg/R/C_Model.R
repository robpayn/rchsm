# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Model Object
#'
#' @description
#'   A Composite Hierarchy State Machine model.
#'
#'   Implementation is provided by C++ objects.
#'
C_Model <- R6Class(
  classname = "C_Model",
  inherit = C_Holon,
  public = list(
    
    #' @field matrix
    #'   The matrix evaluating the state machine
    #'   
    matrix = NULL,
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param depManager
    #'   The dependency manager for the matrix
    #' @param matrix
    #'   (Optional) The matrix value C object for the machine.
    #'   Defaults to a new matrix object with the provided dependency manager
    #' @param name
    #'   (Optional) Name of the model.
    #'   Default value is "Model".
    #' @param className
    #'   (Optional) Name of the class used in accessing c++ functions.
    #'   Default value is "Machine"
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be 
    #'   registered (TRUE) or not (FALSE).
    #'   Defaults to TRUE.
    #'   See super class C_Object for more information.
    #' 
    initialize = function(
      depManager,
      matrix = C_Matrix$new(depManager),
      name = "Model", 
      className = "Machine", 
      regFinalizer = TRUE
    ) 
    {
      super$initialize(
        className = className, 
        name, 
        matrix$.external,
        regFinalizer = regFinalizer
      )
      self$matrix = matrix;
    },
    
    #' @description
    #'   Install a reporter in the state machine
    #'   
    #' @param reporter
    #'   The reporter object to install
    #'   
    installReporter = function(reporter) 
    {
      self$callFunction(fun = "installReporter", reporter$.external)
      invisible(NULL)
    },
    
    #' @description
    #'   Run the state machine simulation
    #'   
    run = function()
    {
      self$callFunction(fun = "run")
      invisible(NULL)
    },
    
    #' @description
    #'   Set the pointer to the value of the time valid variable
    #'   
    #' @param variable
    #'   The variable with the time valid value
    #'   
    setTimeValidVariable = function(variable)
    {
      self$callFunction(
        fun = "setTimeValidVariable", 
        ifelse(
          test = typeof(variable) == "externalptr",
          yes = variable,
          no = ifelse(
            test = any(class(variable) == "C_Variable"),
            yes = variable$.external,
            no = stop(
              "The valid time variable provided to the model is invalid."
            )
          )
        )
      )
      invisible(NULL)
    }
    
  )
)