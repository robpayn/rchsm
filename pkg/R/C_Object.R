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
  inherit = C_ObjectRef,
  public = list(
    
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