/*
 * Updater.cpp
 */

#include "Updater.h"
#include "Value.h"
#include "Dynamic.h"

Updater::Updater(int phase) :
  phase_(phase)
{}

void Updater::attachDynamicValue(Dynamic* dynamic)
{
  val_ = dynamic_cast<Value*>(dynamic);
}