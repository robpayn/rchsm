/*
 * Matrix.cpp
 */

#include "Matrix.h"

//DEBUG CODE
// #include <iostream>

Matrix::Matrix() :
  ValueVarmap(),
  Dynamic(-1),
  dm_(new DepManager(2))
{}

Matrix::~Matrix()
{
  delete dm_;
}

void Matrix::regDynamic(Dynamic* dynamic) {
  if (dynamic->phase_ >= 0) {
    dm_->addDynamic(dynamic);
    // DEBUG CODE
    // std::cerr << dynamic->phase_ << ":" << dm_->size(dynamic->phase_) << ",";
  }
}

void Matrix::setDependencies(DepManager*) {
  
  time_->setDependencies(dm_);
  dm_->manageDependencies();
  
}

void Matrix::setTime(Dynamic* time)
{
  time_ = time;
}

void Matrix::update() {
  
  time_->update();
  
}
