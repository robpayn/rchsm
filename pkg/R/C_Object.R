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
    
    #' @field externalPointer
    #'   The external pointer to the associated C++ Cell object
    externalPointer = NULL,
    
    #' @field cClassName
    #'   The name of the C class
    cClassName = NULL,
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #'   
    #' @param name
    #'   The name of the of the C class being mapped
    #' @param ...
    #'   Abstract arguments to be passed to the 
    #'   
    initialize = function(name, ...)
    {
      self$cClassName <- name
      self$externalPointer = .Call(
        sprintf("%s_constructor", self$cClassName),
        ...
      )
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
        self$externalPointer
      )
      invisible(NULL)
    }
    
  )
)