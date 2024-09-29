/*
 * Updater.cpp
 */

#include "Updater.h"
#include "Value.h"
#include "Dynamic.h"
#include <sstream>

#include "./values/ValueBoolean.h"
#include "./values/ValueDouble.h"
#include "./values/ValueLong.h"

Updater::Updater(int phase) :
  phase_(phase)
{}

void Updater::attachDynamicValue(Dynamic* dynamic)
{
  val_ = dynamic_cast<Value*>(dynamic);
}

UpdaterBoolean::UpdaterBoolean(int phase) :
  Updater(phase)
{}

void UpdaterBoolean::attachDynamicValue(Dynamic* dynamic)
{
  ValueBoolean* value = dynamic_cast<ValueBoolean*>(dynamic);
  if(!value) {
    std::ostringstream error;
    error << "An UpdaterBoolean object must be attached to a Dynamic "
      << "value that extends ValueBoolean.";
    throw std::runtime_error(error.str());
  }
  val_ = value;
  v_ = &(value->v_);
}

UpdaterDouble::UpdaterDouble(int phase) :
  Updater(phase)
{}

void UpdaterDouble::attachDynamicValue(Dynamic* dynamic)
{
  ValueDouble* value = dynamic_cast<ValueDouble*>(dynamic);
  if(!value) {
    std::ostringstream error;
    error << "An UpdaterDouble object must be attached to a Dynamic "
      << "value that extends ValueDouble.";
    throw std::runtime_error(error.str());
  }
  val_ = value;
  v_ = &(value->v_);
}

UpdaterLong::UpdaterLong(int phase) :
  Updater(phase)
{}

void UpdaterLong::attachDynamicValue(Dynamic* dynamic)
{
  ValueLong* value = dynamic_cast<ValueLong*>(dynamic);
  if(!value) {
    std::ostringstream error;
    error << "An UpdaterLong object must be attached to a Dynamic "
      << "value that extends ValueLong.";
    throw std::runtime_error(error.str());
  }
  val_ = value;
  v_ = &(value->v_);
}
