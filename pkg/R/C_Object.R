# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Object
#'
#' @description
#'   An R6 class mapping to a C++ object
#'
#'   Implementation is provided by C++ objects.
#'
C_Object <- R6Class(
  classname = "C_Object",
  public = list(
    
    #' @field .external
    #'   The external pointer to the associated C++ Cell object
    .external = NULL,
    
    #' @field cClassName
    #'   The name of the C class
    cClassName = NULL,
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'   
    #' @param className
    #'   The name of the of the C class being mapped
    #' @param .external
    #'   (Optional) If an external pointer is provided instead of the default
    #'   NULL value, then the new R6 object will be associated with the 
    #'   existing C++ Object referenced by the pointer.
    #' @param ...
    #'   Abstract arguments to be passed to the C++ constructor
    #'   
    initialize = function(className, .external = NULL, ...)
    {
      self$cClassName <- className
      if (is.null(.external)) {
        
        return <- .Call(
          sprintf("%s_constructor", self$cClassName),
          ...
        )
        if(is.character(return)) {
          stop(return)
        } else {
          self$.external <- return;
        }
        
      } else if (typeof(.external) == "externalptr") {
        
        self$.external <- .external
        
      } else {
        
        stop("The external pointer provided is invalid.")
        
      }
    },
    
    #' @description
    #'   Calls the wrapper of the destructor of the C object to release memory.
    #'   Do not call this manually unless you really know what you are doing.
    #'
    #' @return
    #'   SEXP object returned by the destructor method
    #'
    finalize = function()
    {
      .Call(
        sprintf("%s_destructor", self$cClassName), 
        self$.external
      )
      invisible(NULL)
    }
    
  )
)