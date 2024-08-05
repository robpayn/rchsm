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
    #' @param className
    #'   (Optional) Name of the class used in accessing c++ functions.
    #'   Default value is "Model"
    #' @param name
    #'   Name of the model
    #' 
    initialize = function(className = "Model", name = "Model") {
      super$initialize(className = className, name = name)
    },
    
    #' @description
    #'   Creates a new cell in the model
    #'   
    #' @param name 
    #'   The name of the cell to be created
    #' @param .holon
    #'   (Optional) R6 holon object where the cell should be created.
    #'   Default NULL value results in creation of the cell in the model holon
    #' 
    #' @return 
    #'   A new R6 cell object mapped to the C++ cell object that was created.
    #'   
    createCell = function(name, .holon = NULL) {
      
      cCell = .Call(
        "Model_createCell", 
        self$.external, 
        name, 
        .holon
      )
      return(cCell)
      
    },
    
    #' @description
    #'   Creates a new bound in the model
    #'   
    #' @param name 
    #'   The name of the bound to be created
    #' @param .cellFrom
    #'   R6 bound object for the from cell
    #' @param .cellTo
    #'   R6 bound object for the to cell
    #' @param .holon
    #'   (Optional) R6 holon object where the bound should be created.
    #'   Default NULL value results in creation of the bound in the model holon
    #' 
    #' @return 
    #'   A new R6 bound object mapped to the C++ bound object that was created.
    #'   
    createBound = function(name, .cellFrom, .cellTo, .holon = NULL) {
      
      cBound = .Call(
        "Model_createBound", 
        self$.external, 
        name,
        .cellFrom,
        .cellTo,
        .holon
      )
      if (is.character(cBound)) {
        stop(cBound);
      } else {
        return(cBound)
      }
      
    }
    
  )
)