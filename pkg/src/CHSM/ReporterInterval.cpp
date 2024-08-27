/*
 * ReporterInterval.cpp
 */

#include "ReporterInterval.h"
#include "../Matrix.h"
#include "Cell.h"
#include "values/ValueLong.h"

ReporterInterval::ReporterInterval(int interval, Variable& var) :
  interval_(interval)
{
  ValueLong* value = dynamic_cast<ValueLong*>(var.value_);
  if(!value) {
    std::ostringstream error;
    error << "Reporter could not cast the value of " << var.name_ 
      << " to a long integer type. Type of variable provided is invalid for an"
      << " iteration counter.";
    throw std::runtime_error(error.str());
  }
  
  iteration_ = &(value->v_);
}

bool ReporterInterval::isActive()
{
  return (*iteration_ == 0) || (*iteration_ % interval_ == 0);
}
