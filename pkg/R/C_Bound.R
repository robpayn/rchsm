# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   Bound Object
#'
#' @description
#'   An R6 class mapping to a C++ Bound object
#'
#'   Implementation is provided by C++ objects.
#'
C_Bound <- R6Class(
  classname = "C_Bound",
  inherit = C_Holon,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'
    #' @param source
    #'   Source data for creating the bound.
    #'   Providing a character string will result in a new bound object
    #'     being created in both C and R.
    #'   Providing an external pointer will result in a new bound object
    #'     in R that is mapped to the C object referenced by the pointer.
    #' @param className
    #'   (Optional) Name of the class used in accessing c++ functions.
    #'   Default value is "Bound"
    #'     
    initialize = function(source, className = "Bound") {
      
      if (typeof(source) == "externalptr") {
        super$initialize(className = className, .external = source)
      } else if (is.character(source)) {
        super$initialize(className = className, name = source)
      } else {
        stop("Provided source is not a valid bound name or external pointer.")
      }

    }
    
  )
)