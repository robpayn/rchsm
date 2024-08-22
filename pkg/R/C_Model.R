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
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param depManager
    #'   The dependency manager C object the machine should use
    #' @param solver
    #'   The solver C object the machine should use
    #' @param name
    #'   (Optional) Name of the model.
    #'     Default value is "Model".
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
      solver,
      name = "Model", 
      className = "Machine", 
      regFinalizer = TRUE
    ) 
    {
      super$initialize(
        className = className, 
        name = name, 
        .depManager = depManager$.external,
        .solver = solver$.external,
        regFinalizer = regFinalizer
      )
    },
    
    #' @description
    #'   Creates a new bound in the model
    #'   
    #' @param name 
    #'   The name of the bound to be created
    #' @param cellFrom
    #'   R6 bound object for the from cell
    #' @param cellTo
    #'   R6 bound object for the to cell
    #' @param holon
    #'   (Optional) R6 holon object where the bound should be created.
    #'   Default NULL value results in creation of the bound in the model holon
    #' 
    #' @return 
    #'   A new R6 bound object mapped to the C++ bound object that was created.
    #'   The function will cause a fatal error in R if the c object returns
    #'     an error message.
    #'   
    createBound = function(name, cellFrom, cellTo, holon = NULL) 
    {
      return(
        C_Bound$new(
          self$callFunction(
            fun = "createBound",
            name,
            cellFrom$.external,
            cellTo$.external,
            holon$.external
          )
        )
      )
    },
    
    #' @description
    #'   Creates a new cell in the model
    #'   
    #' @param name 
    #'   The name of the cell to be created
    #' @param holon
    #'   (Optional) R6 holon object where the cell should be created.
    #'   Default NULL value results in creation of the cell in the model holon
    #' 
    #' @return 
    #'   A new R6 cell object mapped to the C++ cell object that was created.
    #'   The function will cause a fatal error in R if the c object returns
    #'     an error message.
    #'   
    createCell = function(name, holon = NULL) 
    {
      return(
        C_Cell$new(
          self$callFunction(fun = "createCell", name, holon$.external)
        )
      )
    },
    
    #' @description
    #'   Creates a new variable in the model
    #'
    #' @param name
    #'   Character string with the name of the variable
    #' @param value
    #'   Value object of the new variable 
    #' @param holon
    #'   Holon object containing the new variable
    #'   
    #' @return
    #'   External pointer to the variable that was created
    #'   
    createVariable = function(name, value, holon) 
    {
      return(
        self$callFunction(
          fun = "createVariable",
          name,
          value$.external,
          holon$.external
        )
      )
    },
    
    #' @description
    #'   Initialize the state machine
    #'   
    init = function()
    {
      self$callFunction(fun = "init")
      invisible(NULL)
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
    }
    
  )
)