/*
 * ValueDoubleMemory.h
 */

#ifndef CHSM_VALUES_VALUEDOUBLEMEMORY_H_
#define CHSM_VALUES_VALUEDOUBLEMEMORY_H_

#include "ValueDouble.h"
#include "../DynamicMemory.h"

class ValueDoubleMemory : public ValueDouble, public DynamicMemory
{
  public:
    
    ValueDoubleMemory(int);
    
    ValueDoubleMemory(int, double);
    
    Memory* createMemory(int) override;
    
};

#endif /* CHSM_VALUES_VALUEDOUBLEMEMORY_H_ */
