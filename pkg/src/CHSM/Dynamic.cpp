/**
 * Dynamic.cpp
 */

#include "Dynamic.h"
#include "Updater.h"
#include "Value.h"

Dynamic::Dynamic()
{}

Dynamic::~Dynamic()
{
  delete updater_;
}

void Dynamic::attachUpdater(Updater* updater)
{
  updater_ = updater;
  updater_->attachDynamicValue(this);
}
