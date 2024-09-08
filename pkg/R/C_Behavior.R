# Dependencies for ROxygen ####
#' @importFrom R6 R6Class
#' @useDynLib rchsm

#' @export
#'
#' @title
#'   A CHSM Behavior
#'
#' @description
#'   An R6 class mapping to a C++ composite Hierarchy State Machine object
#'
#'   Implementation is provided by C++ objects.
#'
C_Behavior <- R6Class(
  classname = "C_Behavior",
  inherit = C_Object,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #' 
    #' @param className
    #'   The name of the associated C class
    #' @param ...
    #'   Generic arguments that will be passed on to the C constructor
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should 
    #'   be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to TRUE.
    #'   See super class C_Object for more information.
    #'
    initialize = function(className, ..., regFinalizer = TRUE) 
    {
      super$initialize(className = className, ..., regFinalizer = regFinalizer)
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon.
    #'
    #' @param matrix
    #'   The matrix object where the variables should be installed
    #' @param holon
    #'   The holon object where the variables should be installed
    #' @param ...
    #'   Further arguments to be passed on to the associated C function.
    #'   These are often initial values for the variable being created.
    #'   
    createVariables = function(matrix, holon, ...) 
    {
      vargs = list(...)
      if(any(names(vargs) == "mfDouble")) {
        if (is.null(vargs$mfDouble) || (typeof(vargs$mfDouble) == "externalptr")) {
        } else if (any(class(vargs$mfDouble) == "C_MemoryDoubleFactory")) {
          vargs$mfDouble <- vargs$mfDouble$.external
        } else {
          stop("Invalid memory factory provided.")
        }
      }
      return(
        do.call(
          what = self$callFunction,
          args = c(
            fun = "createVariables",
            matrix$.external,
            holon$.external,
            vargs
          )
        )
      )
    }
    
  )
)

#' @export
#'
#' @title
#'   A CHSM Behavior for simulating time
#'
#' @description
#'   An R6 class mapping to a C++ composite Hierarchy State Machine object
#'
#'   Implementation is provided by C++ objects.
#'
C_BehCellTime <- R6Class(
  classname = "C_BehCellTime",
  inherit = C_Behavior,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #' 
    #' @param className
    #'   (Optional) The name of the class for the behavior.
    #'   Defaults to "BehCellTime".
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to TRUE.
    #'   See super class C_Object for more information.
    #'
    initialize = function(
      className = "BehCellTime", 
      regFinalizer = TRUE
    )
    {
      super$initialize(
        className = className, 
        regFinalizer = regFinalizer
      )
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon.
    #'
    #' @param matrix
    #'   The matrix object where the variables should be installed
    #' @param holon
    #'   The holon object where the variables should be installed
    #' @param initTime
    #'   Numeric for initial value of time
    #' @param initIteration
    #'   Integer for initial value of the iteration counter
    #' @param initTimeValid
    #'   Logical for initial value of the valid time indicator
    #'   
    createVariables = function(
      matrix, 
      holon,       
      initTime,
      initIteration,
      initTimeValid
    ) 
    {
      return(
        super$createVariables(
          matrix,
          holon,
          initTime,
          initIteration,
          initTimeValid
        )
      )
    }
    
  )
)

#' @export
#'
#' @title
#'   A CHSM Behavior for simulating solute concentrations in a cell
#'
#' @description
#'   An R6 class mapping to a C++ composite Hierarchy State Machine object
#'
#'   Implementation is provided by C++ objects.
#'
C_BehCellSolute <- R6Class(
  classname = "C_BehCellSolute",
  inherit = C_Behavior,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #' 
    #' @param soluteName
    #'   Character string with the name of the solute
    #' @param mfDouble
    #'   (Optional) Memory factory used for the state phase values.
    #'   Default value is NULL, which may not be compatible with solvers
    #'   that require memory.
    #' @param className
    #'   The name of the associated C class
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to TRUE.
    #'   See super class C_Object for more information.
    #'
    initialize = function(
      soluteName, 
      className = "BehCellSolute", 
      regFinalizer = TRUE
    )
    {
      super$initialize(
        className = className, 
        soluteName,
        regFinalizer = regFinalizer
      )
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon.
    #'
    #' @param matrix
    #'   The matrix object where the variables should be installed.
    #' @param holon
    #'   The holon object where the variables should be installed.
    #' @param timeHolon
    #'   The holon containing the time step variable.
    #' @param timeStepName
    #'   The name of the time step variable.
    #' @param initConc
    #'   Numeric for initial concentration of solute.
    #' @param mfDouble
    #'   (Optional) The memory factory for constructing the appropriate
    #'   memory for the concentration value.
    #'   
    createVariables = function(
      matrix, 
      holon,
      timeHolon,
      timeStepName,
      initConc,
      mfDouble = NULL
    ) 
    {
      return(
        super$createVariables(
          matrix,
          holon,
          if (is.null(timeHolon) || (typeof(timeHolon) == "externalptr"))
            timeHolon
          else if (any(class(timeHolon) == "C_Bound"))
            timeHolon$.external
          else
            stop("Invalid time holon provided."),
          timeStepName,
          initConc,
          mfDouble = mfDouble
        )
      )
    }
    
  )
)

#' @export
#'
#' @title
#'   A CHSM Behavior for simulating first order solute reactions
#'
#' @description
#'   An R6 class mapping to a C++ composite Hierarchy State Machine object
#'
#'   Implementation is provided by C++ objects.
#'
C_BehBoundFirstOrder <- R6Class(
  classname = "C_BehBoundFirstOrder",
  inherit = C_Behavior,
  public = list(
    
    #' @description
    #'   Constructs an object that is a new instance of the class
    #' 
    #' @param soluteName
    #'   Character string with the name of the solute
    #' @param className
    #'   The name of the associated C class
    #' @param regFinalizer
    #'   (Optional) Logical to indicate if a finalizer should be registered (TRUE)
    #'   or not (FALSE).
    #'   Defaults to TRUE.
    #'   See super class C_Object for more information.
    #'
    initialize = function(
      soluteName, 
      className = "BehBoundFirstOrder", 
      regFinalizer = TRUE
    )
    {
      super$initialize(
        className = className, 
        soluteName, 
        regFinalizer = regFinalizer
      )
    },
    
    #' @description
    #'   Create the variables controlling the behavior in the provided holon.
    #'
    #' @param matrix
    #'   The matrix object where the variables should be installed
    #' @param holon
    #'   The holon object where the variables should be installed
    #' @param initRate
    #'   Numeric for initial rate of reaction
    #'   
    createVariables = function(
      matrix, 
      holon,       
      initRate
    ) 
    {
      return(
        super$createVariables(
          matrix,
          holon,
          initRate
        )
      )
    }
    
  )
)
