# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Holon Object
#'
#' @description
#'   A holon in a composite Hierarchy State Machine
#'
#'   Implementation is provided by C++ objects.
#'
C_Holon <- R6Class(
  classname = "C_Holon",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param className
    #'   (Optional) Name of the class used in accessing c++ functions.
    #'   Default value is "Holon"
    #' @param .external
    #'   (Optional) If an external pointer is provided instead of the default
    #'   NULL value, then the new R6 object will be associated with the 
    #'   existing C++ Object referenced by the pointer.
    #' @param ...
    #'   Abstract arguments passed to the constructor of the super class
    #'
    #' 
    initialize = function(className = "Holon", .external = NULL, ...) {
      super$initialize(
        className = className, 
        .external = .external, 
        ...
      )
    },
    
    #' @description
    #'   Constructs an object that is a new instance of the class.
    #'
    #' @return 
    #'   A single element character vector representing the contents of the
    #'   holon.
    getValueString = function() {
      
      return(
        self$callFunction(
          name = "getValueString",
          cClassName = "Holon"
        )
      )
      
    }
    
  )
)
