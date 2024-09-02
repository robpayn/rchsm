# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Matrix Object
#'
#' @description
#'   A Composite Hierarchy State Machine matrix value.
#'
#'   Implementation is provided by C++ objects.
#'
C_Matrix <- R6Class(
  classname = "C_Matrix",
  inherit = C_Value,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param depManager
    #'   The dependency manager C object the matrix should use
    #' @param className
    #'   (Optional) Name of the class used in accessing c++ functions.
    #'   Default value is "Matrix"
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be 
    #'   registered (TRUE) or not (FALSE).
    #'   Defaults to TRUE.
    #'   See super class C_Object for more information.
    #' 
    initialize = function(
      depManager,
      className = "Matrix", 
      regFinalizer = FALSE
    ) 
    {
      super$initialize(
        className = className, 
        depManager$.external,
        regFinalizer = regFinalizer
      )
    },
    
    #' @description
    #'   Creates a new bound in the matrix
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
    #'   Creates a new cell in the matrix
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
    #'   Creates a new variable in the matrix
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
        C_Variable$new(
          .external = self$callFunction(
            fun = "createVariable",
            name,
            value$.external,
            holon$.external
          )
        )
      )
    },
    
    #' @description
    #'   Install a solver for the matrix updater
    #'
    #' @param solver
    #'   R6 Solver object to use in the matrix updater
    #'
    #' @return
    #'   Invisibly returns a NULL value
    #'   
    installSolver = function(solver)
    {
      self$callFunction(fun = "installSolver", solver$.external)
      invisible(NULL)
    }

  )
)