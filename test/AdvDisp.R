library(R6)
library(rchsm, lib.loc = "./build")

AdvDisp <- R6Class(
  classname = "AdvDisp",
  inherit = C_Model,
  public = list(
    
    reporter = NULL,
    
    initialize = function(
      timeMax,
      timeStep,
      numCells,
      boundLength,
      repInterval,
      upstreamConc,
      velocity,
      dispCoeff,
      trackCell,
      soluteName = "Salt"
    )
    {
      super$initialize(depManager = C_DepManInstallOrder$new(numPhases = 3))

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
        value = C_ValueDouble$new(initValue = timeMax),
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
      
      # self$matrix$installSolver(
      #   solver = C_SolverForwardEuler$new(timeStep = timeStepVar)
      # )
      # mfDouble <- NULL
      
      self$matrix$installSolver(
        solver = C_SolverRKTwo$new(timeStep = timeStepVar)
      )
      mfDouble <- C_MemoryDoubleFactory$new(size = 1)
      
      lastcell <- self$matrix$createCell(name = "CellUp")
      beh <- C_Behavior$new(
        className = "BehCellConcDefined", 
        soluteName = soluteName
      )
      beh$createVariables( 
        matrix = self$matrix,
        holon = lastcell, 
        timeHolon = timeBound$.external,
        timeStepName = "TimeStep",
        iterationName = "Iteration",
        conc = upstreamConc,
        mfDouble = mfDouble
      )
      self$reporter$trackVariable(
        variable = lastcell$getVariablePointer(
          name = paste0(soluteName, "Conc")
        )
      )
      
      behCell <- C_BehCellSolute$new(soluteName = soluteName)
      behAdv <- C_Behavior$new(
        className = "BehBoundAdvection", 
        soluteName = soluteName
      )
      behDisp <- C_Behavior$new(
        className = "BehBoundDispersion", 
        soluteName = soluteName,
        regFinalizer = TRUE
      )

      for(cellCount in 1:numCells) {
      
        cell <- self$matrix$createCell(name = sprintf("Cell%02d", cellCount))
        behCell$createVariables( 
          matrix = self$matrix,
          holon = cell, 
          timeHolon = timeBound,
          timeStepName = "TimeStep",
          initConc = 0,
          mfDouble = mfDouble
        )
        if(cellCount == trackCell) {
          self$reporter$trackVariable(
            variable = cell$getVariablePointer(
              name = paste0(soluteName, "Conc")
            )
          )
        }
        
        bound <- self$matrix$createBound(
          name = sprintf("Bound%02d", cellCount), 
          cellFrom = lastcell, 
          cellTo = cell
        )
        
        behAdv$createVariables(
          matrix = self$matrix,
          holon = bound,
          initRate = 0
        )
        self$matrix$createVariable(
          name = "WaterVelocity",
          value = C_ValueDouble$new(initValue = velocity),
          holon = bound
        )
        
        behDisp$createVariables(
          matrix = self$matrix,
          holon = bound,
          initRate = 0
        )
        self$matrix$createVariable(
          name = paste0(soluteName, "DispCoeff"),
          value = C_ValueDouble$new(initValue = dispCoeff),
          holon = bound
        )
        
        self$matrix$createVariable(
          name = "length",
          value = C_ValueDouble$new(
            initValue = ifelse(
              test = cellCount == 1,
              yes = boundLength / 2,
              no = boundLength
            )
          ),
          holon = bound
        )
        
        lastcell <- cell
        
      }      
    }
    
  )
)