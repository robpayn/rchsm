# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   BehCellDOConc Object
#'
#' @description
#'   An R6 class mapping to a C++ BehCellDOConc object
#'
#'   Implementation is provided by C++ objects.
#'
C_BehCellDOConc <- R6Class(
  classname = "C_BehCellDOConc",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    initialize = function() {
      super$initialize("BehCellDOConc")
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon
    #'
    #' @param holon
    #'   The holon object where the variables should be created
    #'   
    createVariables = function(holon) {
      .Call(
        "BehCellDOConc_createVariables",
        self$externalPointer,
        holon$externalPointer
      )
      invisible(NULL)
    }
    
  )
)