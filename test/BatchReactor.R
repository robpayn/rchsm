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
      beh <- C_BehCellTime$new()
      beh$createVariables(
        matrix = self$matrix,
        holon = cell,
        initTime = 0,
        initIteration = 0,
        initTimeValid = TRUE
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
      beh <- C_BehCellSolute$new(soluteName = "Nitrate")
      beh$createVariables(
        matrix = self$matrix, 
        holon = cell,
        timeHolon = timeBound,
        timeStepName = "TimeStep",
        initConc = initConc,
        mfDouble = mfDouble
      )
      
      self$reporter$trackVariable(
        variable = cell$getVariablePointer(name = "NitrateConc")
      )
      
      bound <- self$matrix$createBound(
        name = "Bound01", 
        cellFrom = NULL, 
        cellTo = cell
      )
      beh <- C_BehBoundFirstOrder$new(soluteName = "Nitrate")
      beh$createVariables(
        matrix = self$matrix,
        holon = bound,
        initRate = 0
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
