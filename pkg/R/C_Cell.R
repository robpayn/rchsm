# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   Cell Object
#'
#' @description
#'   An R6 class mapping to a C++ Cell object
#'
#'   Implementation is provided by C++ objects.
#'
C_Cell <- R6Class(
  classname = "C_Cell",
  inherit = C_Holon,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param source
    #'   Source data for creating the cell.
    #'   Providing a character string will result in a new cell object
    #'     being created in both C and R.
    #'   Providing an external pointer will result in a new cell object
    #'     in R that is mapped to the C object referenced by the pointer.
    #' @param className
    #'   (Optional) Name of the class used in accessing c++ functions.
    #'   Default value is "Cell"
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be 
    #'   registered (TRUE) or not (FALSE).
    #'   Defaults to TRUE.
    #'   Note this argument has no effect if the object is created from
    #'   an existing external pointer.
    #'   See super class C_Object for more information.
    #'     
    initialize = function(source, className = "Cell", regFinalizer = TRUE) {
      
      if (typeof(source) == "externalptr") {
        super$initialize(className = className, .external = source)
      } else if (is.character(source)) {
        super$initialize(
          className = className, 
          name = source, 
          regFinalizer = regFinalizer
        )
      } else {
        stop("Provided source is not a valid cell name or external pointer.")
      }
      
    }
    
  )
)