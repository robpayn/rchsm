rm(list = ls())

source("./AdvDisp.R")

analytical <- function(x, t, conc, velocity, dispCoeff)
{
  return(
    ((conc * x) / (4 * pi * dispCoeff * t^3)^0.5) *
    exp(-(x - velocity * t)^2 / (4 * dispCoeff * t))
  )
}

reachLength <- 200
trackCell <- 40
boundLength <- reachLength / (trackCell - 0.5)

model <- AdvDisp$new(
  timeMax = 1200,
  timeStep = 1,
  numCells = 50,
  boundLength = boundLength,
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

t <- seq(1, 1200, 20)
analSol <- analytical(reachLength, t, 5000 * 1, 0.4, 2)
points(x = t, y = analSol)

model <- AdvDisp$new(
  timeMax = 1200,
  timeStep = 1,
  numCells = 50,
  boundLength = boundLength,
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

analSol <- analytical(reachLength, t, 5000 * 1, 0.4, 5)
points(x = t, y = analSol, col = "red")
