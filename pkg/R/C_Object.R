# Dependencies for ROxygen ####

#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM object reference
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
    #' @param ...
    #'   Abstract arguments to be passed to the C++ constructor for the
    #'   provided class name
    #' @param regFinalizer
    #'   Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Registering a finalizer will cause the C deconstructor to be called
    #'   when the object goes out of scope in R.
    #'   A finalizer should not be registered unless R is considered to own
    #'   the object, rather than the object being owned by another object in
    #'   C.
    #' @param .external
    #'   (Optional) If an external pointer is provided instead of the default
    #'   NULL value, then the new R6 object will be associated with the 
    #'   existing C++ Object referenced by the pointer.
    #'   
    initialize = function(className, ..., regFinalizer = NULL, .external = NULL)
    {
      self$cClassName <- className
      if (is.null(.external)) {
        
        if (is.null(regFinalizer)) {
          stop(
            paste(
              "Error in initializing C_Object:",
              "The regFinalizer argument must be provided if an external",
              "pointer is not provided."
            )
          )
        }
        return <- .Call(
          sprintf("%s_constructor", self$cClassName),
          ...,
          regFinalizer
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
    #' @param fun
    #'   Character string with the name of the method to be called
    #' @param ...
    #'   SEXP arguments to be passed on to the C function
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
    #'   
    callFunction = function(fun, ..., cClassName = self$cClassName) 
    {
      returnVal <- .Call(
        paste0(cClassName, "_", fun),
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
    }

  )
)