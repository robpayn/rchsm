/*
 * ReporterInterval.cpp
 */

#include "ReporterInterval.h"
#include "../Matrix.h"
#include "Cell.h"
#include "values/ValueLong.h"

ReporterInterval::ReporterInterval(int interval) :
  interval_(interval)
{}

void ReporterInterval::init(Matrix* matrix)
{
  
  Cell* cell = dynamic_cast<Cell*>(matrix->getVariable(cellTimeName_));
  if(!cell) {
    std::ostringstream error;
    error << "Reporter could not find the " << cellTimeName_ 
      << " cell in the matrix.";
    throw std::runtime_error(error.str());
  }

  ValueLong* value = cell->getVarValue<ValueLong>(varNameIter_);
  if(!value) {
    std::ostringstream error;
    error << "Reporter could not find the " << varNameIter_ 
          << " variable in the time cell.";
    throw std::runtime_error(error.str());
  }
  
  iteration_ = &(value->v_);
  
}

bool ReporterInterval::isActive()
{
  return (*iteration_ == 0) || (*iteration_ % interval_ == 0);
}