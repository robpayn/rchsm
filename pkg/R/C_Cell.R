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
    #'     
    initialize = function(source, className = "Cell") {
      
      if (typeof(source) == "externalptr") {
        super$initialize(className = className, externalPointer = source)
      } else if (is.character(source)) {
        super$initialize(className = className, name = source)
      } else {
        stop("Provided source is not a valid cell name or external pointer.")
      }
      
    }
    
  )
)