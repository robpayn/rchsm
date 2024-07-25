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
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param name
    #'   Name of the model
    #' 
    initialize = function(name = "Model") {
      super$initialize(className = "Model", name = name)
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
    #'   
    createCell = function(name, holon = NULL) {
      
      cCell = .Call(
        "Model_createCell", 
        self$externalPointer, 
        name, 
        holon$externalPointer
      )
      return(C_Cell$new(source = cCell))
      
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
    #'   
    createBound = function(name, cellFrom, cellTo, holon = NULL) {
      
      cBound = .Call(
        "Model_createBound", 
        self$externalPointer, 
        name,
        cellFrom$externalPointer,
        cellTo$externalPointer,
        holon$externalPointer
      )
      if (is.null(cBound)) {
        return(NULL)
      } else {
        return(C_Bound$new(source = cBound))
      }
    }
    
  )
)