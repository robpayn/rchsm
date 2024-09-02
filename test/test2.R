rm(list = ls())

source(file = "./BatchReactor.R")

initConc = 10
rateCoeff = 0.15
timeStep = 4
maxTime = 40

batchReactor <- BatchReactor$new(
  initConc = initConc,
  rateCoeff = rateCoeff,
  timeStep = timeStep / 2,
  maxTime = maxTime
)

# cat(batchReactor$getValueString())

batchReactor$run()

output <- batchReactor$getOutput()

plot(output$CellTime.Time, output$Cell01.NitrateConc)

batchReactor <- BatchReactor$new(
  initConc = initConc,
  rateCoeff = rateCoeff,
  timeStep = timeStep,
  maxTime = maxTime,
  solver = "RKTwo"
)

batchReactor$run()

output <- batchReactor$getOutput()

points(output$CellTime.Time, output$Cell01.NitrateConc, col = "red")

t = seq.default(from = 0, to = maxTime, length.out = 50)
lines(x = t, y = initConc * exp(-rateCoeff * t))
