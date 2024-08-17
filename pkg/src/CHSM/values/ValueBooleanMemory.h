/*
 * ValueBooleanMemory.h
 */

#ifndef CHSM_VALUES_VALUEBOOLEANMEMORY_H_
#define CHSM_VALUES_VALUEBOOLEANMEMORY_H_

#include "ValueBoolean.h"
#include "../DynamicMemory.h"

class ValueBooleanMemory : public ValueBoolean, public DynamicMemory
{
public:
  
  ValueBooleanMemory(int);
  
  ValueBooleanMemory(int, bool);
  
  Memory* createMemory(int) override;
  
};

#endif /* CHSM_VALUES_VALUEBOOLEANMEMORY_H_ */
