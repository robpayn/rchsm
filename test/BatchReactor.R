library(R6)
library(rchsm, lib.loc = "./build")

BatchReactor <- R6Class(
  classname = "BatchReactor",
  inherit = C_Model,
  public = list(
    
    reporter = NULL,
    
    initialize = function(
      initConc, 
      rateCoeff, 
      timeStep, 
      maxTime, 
      repInterval = 1,
      solver = "ForwardEuler"
    )
    {
      super$initialize(
        depManager = C_DepManInstallOrder$new(numPhases = 3)
      )
      
      cell <- self$matrix$createCell(name = "CellTime")
      self$matrix$createVariable(
        name = "Time",
        value = C_Object$new(
          className = "Time",
          initValue = 0,
          phase = 0,
          regFinalizer = FALSE
        ),
        holon = cell
      )
      self$matrix$createVariable(
        name = "Iteration",
        value = C_Object$new(
          className = "Iteration",
          initValue = 0,
          phase = 0,
          regFinalizer = FALSE
        ),
        holon = cell
      )
      self$matrix$createVariable(
        name = "TimeValid",
        value = C_Object$new(
          className = "TimeValid",
          initValue = TRUE,
          phase = 0,
          regFinalizer = FALSE
        ),
        holon = cell
      )
      self$matrix$createVariable(
        name = "TimeMax",
        value = C_ValueDouble$new(initValue = maxTime),
        holon = cell
      )
      
      self$setTimeValidVariable(
        variable = cell$getVariablePointer(name = "TimeValid")
      )
      
      self$reporter <- C_ReporterTable$new(
        interval = repInterval, 
        iterationVariable = cell$getVariablePointer(name = "Iteration")
      )
      self$installReporter(reporter = self$reporter)
      self$reporter$trackVariable(
        variable = cell$getVariablePointer(name = "Iteration")
      )
      self$reporter$trackVariable(
        variable = cell$getVariablePointer(name = "Time")
      )
      
      timeBound <- self$matrix$createBound(
        name = "BoundTime", 
        cellFrom = NULL, 
        cellTo = cell
      )
      timeStepVar <- self$matrix$createVariable(
        name = "TimeStep",
        value = C_ValueDouble$new(initValue = timeStep),
        holon = timeBound
      )
      
      if (solver == "ForwardEuler") {
        self$matrix$installSolver(
          solver = C_SolverForwardEuler$new(timeStep = timeStepVar)
        )
        mfDouble <- NULL
      } else if (solver == "RKTwo") {
        self$matrix$installSolver(
          solver = C_SolverRKTwo$new(timeStep = timeStepVar)
        )
        mfDouble <- C_MemoryDoubleFactory$new(size = 1)
      } else {
        if(is.character(solver)) {
          stop(paste("Solver argument", solver, "is not a valid solver name."))
        } else {
          stop(paste("Solver argument type", typeof(solver), "is invalid."))
        }
      }
      
      cell <-self$matrix$createCell(name = "Cell01")
      self$matrix$createVariable(
        name = "NitrateConc",
        value = C_Object$new(
          className = "StateDouble",
          timeHolon = timeBound$.external,
          timeStepName = "TimeStep",
          initConc = initConc,
          phase = 2,
          mfDouble = mfDouble$.external,
          regFinalizer = FALSE
        ),
        holon = cell
      )
      self$reporter$trackVariable(
        variable = cell$getVariablePointer(name = "NitrateConc")
      )
      
      bound <- self$matrix$createBound(
        name = "Bound01", 
        cellFrom = NULL, 
        cellTo = cell
      )
      self$matrix$createVariable(
        name = "NitrateRate",
        value = C_Object$new(
          className = "RateFirstOrder",
          initValue = 0,
          stateName = "NitrateConc",
          coeffName = "NitrateRateCoeff",
          phase = 1,
          regFinalizer = FALSE
        ),
        holon = bound
      )
      self$matrix$createVariable(
        name = "NitrateRateCoeff",
        value = C_ValueDouble$new(initValue = rateCoeff),
        holon = bound
      )
      
      self$reporter$trackRate(
        variable = bound$getVariablePointer(name = "NitrateRate"),
        from = FALSE
      )
    },
    
    getOutput = function()
    {
      self$reporter$getDataFrame()
    }
    
  )
)
