rm(list = ls())

source("./AdvDisp.R")

trackCell <- 40

model <- AdvDisp$new(
  timeMax = 1200,
  timeStep = 1,
  numCells = 50,
  boundLength = 5,
  repInterval = 5,
  upstreamConc = c(0, 5000, 0),
  velocity = 0.4,
  dispCoeff = 2,
  trackCell = trackCell
)
write(x = model$getValueString(), file = "test.txt")
model$run()
output <- model$reporter$getDataFrame()

windows(width = 10, height = 7)
par(
  mai = c(1, 0.8, 0.1, 0.1)
)
plot(
  x = output$CellTime.Time,
  y = output[[sprintf("Cell%02d.SaltConc", trackCell)]],
  type = "l"
)

model <- AdvDisp$new(
  timeMax = 1200,
  timeStep = 1,
  numCells = 50,
  boundLength = 5,
  repInterval = 5,
  upstreamConc = c(0, 5000, 0),
  velocity = 0.4,
  dispCoeff = 5,
  trackCell = trackCell
)
model$run()
output <- model$reporter$getDataFrame()
lines(
  x = output$CellTime.Time,
  y = output[[sprintf("Cell%02d.SaltConc", trackCell)]],
  lty = "dashed",
  col = "red"
)
