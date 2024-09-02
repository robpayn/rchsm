#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   CHSM Solver object
#'
#' @description
#'   An R reference to a solver object
#'
#'   Implementation is provided by C++ objects.
#'
C_Solver <- R6Class(
  classname = "C_Solver",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Create an instance of the solver
    #' 
    #' @param className
    #'   Character string with the name of the class.
    #' @param timeStep
    #'   Variable object for the time step
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered 
    #'   (TRUE) or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      className, 
      timeStep,
      regFinalizer = FALSE
    ) 
    {
      super$initialize(
        className = className,
        if (typeof(timeStep) == "externalptr")
          timeStep
        else 
          if (any(class(timeStep) == "C_Variable"))
            timeStep$.external
          else
            stop(
              "Invalid iteration variable argument for an interval reporter."
            ),
        regFinalizer = regFinalizer
      )
    }
    
  )
)

#' @export
#'
#' @title
#'   CHSM Forward Euler Solver object
#'
#' @description
#'   An R reference to a solver object
#'
#'   Implementation is provided by C++ objects.
#'
C_SolverForwardEuler <- R6Class(
  classname = "C_SolverForwardEuler",
  inherit = C_Solver,
  public = list(
    
    #' @description
    #'   Create an instance of the solver
    #' 
    #' @param timeStep
    #'   Variable object for the time step
    #' @param className
    #'   (Optional) Character string with the name of the class.
    #'   Defaults to "SolverForwardEuler".
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
        timeStep,
        regFinalizer = regFinalizer
      )
    }
    
  )
)

#' @export
#'
#' @title
#'   CHSM Second Order Runge Kutta Solver object
#'
#' @description
#'   An R reference to a solver object
#'
#'   Implementation is provided by C++ objects.
#'
C_SolverRKTwo <- R6Class(
  classname = "C_SolverRKTwo",
  inherit = C_Solver,
  public = list(
    
    #' @description
    #'   Create an instance of the solver
    #' 
    #' @param timeStep
    #'   Variable object for the time step
    #' @param className
    #'   (Optional) Character string with the name of the class.
    #'   Defaults to "SolverRKTwo".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered 
    #'   (TRUE) or not (FALSE).
    #'   Defaults to FALSE.
    #'   See super class C_Object for more information.
    #'   
    initialize = function(
      timeStep,
      className = "SolverRKTwo", 
      regFinalizer = FALSE
    ) 
    {
      super$initialize(
        className = className,
        timeStep,
        regFinalizer = regFinalizer
      )
    }
    
  )
)
