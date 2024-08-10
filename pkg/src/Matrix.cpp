/*
 * Matrix.cpp
 */

#include "Matrix.h"

Matrix::Matrix() {}

void Matrix::setDependencies() {
  
  time_->setDependencies();
  
}

void Matrix::setTime(Dynamic* time)
{
  time_ = time;
}

void Matrix::update() {
  
  time_->update();
  
}
