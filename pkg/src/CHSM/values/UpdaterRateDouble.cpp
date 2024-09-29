/*
 * UpdaterRateDouble.cpp
 */

#include "UpdaterRateDouble.h"
#include "RateDouble.h"
#include <sstream>

UpdaterRateDouble::UpdaterRateDouble(int phase) :
  Updater(phase)
{}

void UpdaterRateDouble::attachDynamicValue(Dynamic* dynamic)
{
  RateDouble* value = dynamic_cast<RateDouble*>(dynamic);
  if(!value) {
    std::ostringstream error;
    error << "An UpdaterRateDouble object must be attached to a Dynamic "
      << "value that extends RateDouble.";
    throw std::runtime_error(error.str());
  }
  val_ = value;
  v_ = &(value->v_);
  vf_ = &(value->vf_);
}
