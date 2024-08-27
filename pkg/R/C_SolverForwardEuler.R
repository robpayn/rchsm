#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Forward Euler solver object
#'
#' @description
#'   An R reference to a forward Euler solver object
#'
#'   Implementation is provided by C++ objects.
#'
C_SolverForwardEuler <- R6Class(
  classname = "C_SolverForwardEuler",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Create an instance of the solver
    #' 
    #' @param timeStep
    #'   Variable object for the time step
    #' @param className
    #'   (Optional) Character string with the name of the class.
    #'     Defaults to "SolverForwardEuler".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered 
    #'   (TRUE) or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      timeStep,
      className = "SolverForwardEuler", 
      regFinalizer = FALSE
    ) 
    {
      super$initialize(
        className = className,
        timeStep$.external,
        regFinalizer = regFinalizer
      )
    }
    
  )
)
