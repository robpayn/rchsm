# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   BehDOConcCell Object
#'
#' @description
#'   An R6 class mapping to a C++ BehDOConcCell object
#'
#'   Implementation is provided by C++ objects.
#'
C_BehDOConcCell <- R6Class(
  classname = "C_BehDOConcCell",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param name
    #'   Name of the cell
    #'   
    initialize = function() {
      super$initialize("BehDOConcCell")
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon
    #'
    #' @param holon
    #'   The holon object where the variables should be created
    #'   
    createVariables = function(holon) {
      .Call(
        "BehDOConcCell_createVariables",
        self$externalPointer,
        holon$externalPointer
      )
      invisible(NULL)
    }
    
  )
)