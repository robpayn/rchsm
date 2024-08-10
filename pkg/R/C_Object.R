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
    #'   Call a C function representing one of the methods of the class
    #'
    #' @param name
    #'   Character string with the name of the method to be called
    #' @param ...
    #'   Further arguments to be passed on to the C function
    #' @param cClassName
    #'   (Optional) A character string representing the C class name for the
    #'     function to be called.
    #'   Defaults to the C class name associated with the derived class.
    #'   This should be changed if the function associated with a base class
    #'     needs to be called.
    #' 
    #' @return 
    #'   SEXP object returned by the function.
    #'   If the object is a character string starting with "<CERROR>", the
    #'     program will be stopped with the error message provided from C.
    #'   A null return value will be returned invisibly.
    callFunction = function(name, ..., cClassName = self$cClassName) {
      returnVal <- .Call(
        paste0(cClassName, "_", name),
        self$.external,
        ...
      )
      if (is.character(returnVal)) {
        if (grepl(pattern = "^<CERROR>", x = returnVal)) {
          stop(returnVal);
        }
      }
      if (is.null(returnVal)) {
        invisible(NULL)
      } else {
        return(returnVal)
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