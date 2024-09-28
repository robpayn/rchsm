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
      initConc,
      upstreamConc,
      velocity,
      dispCoeff,
      trackCell,
      soluteName = "Salt"
    )
    {
      super$initialize(depManager = C_DepManInstallOrder$new(numPhases = 3))

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
      self$matrix$createVariable(
        name = paste0(soluteName, "Conc"),
        value = C_Object$new(
          className = "StateDoubleDefined",
          timeHolon = timeBound$.external,
          timeStepName = "TimeStep",
          iterationName = "Iteration",
          values = upstreamConc,
          phase = 2,
          mfDouble = mfDouble$.external,
          regFinalizer = FALSE
        ),
        holon = lastcell
      )
      self$reporter$trackVariable(
        variable = lastcell$getVariablePointer(
          name = paste0(soluteName, "Conc")
        )
      )
      
      stateName <- paste0(soluteName, "Conc")
      velocityName <- "WaterVelocity"
      dispCoeffName <- paste0(soluteName, "DispCoeff")
      for(cellCount in 1:numCells) {
      
        cell <- self$matrix$createCell(name = sprintf("Cell%02d", cellCount))
        self$matrix$createVariable(
          name = paste0(soluteName, "Conc"),
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
        if(cellCount == trackCell) {
          self$reporter$trackVariable(
            variable = cell$getVariablePointer(
              name = stateName
            )
          )
        }
        
        bound <- self$matrix$createBound(
          name = sprintf("Bound%02d", cellCount), 
          cellFrom = lastcell, 
          cellTo = cell
        )
        self$matrix$createVariable(
          name = paste0(soluteName, "Advection"),
          value = C_Object$new(
            className = "RateAdvection", 
            initValue = 0, 
            stateName = stateName, 
            velocityName = velocityName,
            phase = 1,
            regFinalizer = FALSE
          ),
          holon = bound
        )
        self$matrix$createVariable(
          name = velocityName,
          value = C_ValueDouble$new(initValue = velocity),
          holon = bound
        )
        
        self$matrix$createVariable(
          name = paste0(soluteName, "Dispersion"),
          value = C_Object$new(
            className = "RateDispersion",
            initValue = 0,
            stateName = stateName,
            coeffName = dispCoeffName,
            phase = 1,
            regFinalizer = FALSE
          ),
          holon = bound
        )
        self$matrix$createVariable(
          name = dispCoeffName,
          value = C_ValueDouble$new(initValue = dispCoeff),
          holon = bound
        )
        
        self$matrix$createVariable(
          name = "SpaceLength",
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