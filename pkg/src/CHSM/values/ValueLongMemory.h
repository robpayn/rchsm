/*
 * ValueLongMemory.h
 */

#ifndef CHSM_VALUES_VALUELONGMEMORY_H_
#define CHSM_VALUES_VALUELONGMEMORY_H_

#include "ValueLong.h"
#include "../DynamicMemory.h"

class ValueLongMemory : public ValueLong, public DynamicMemory
{
public:
  
  ValueLongMemory(int);
  
  ValueLongMemory(int, long);
  
  Memory* createMemory(int) override;
  
};


#endif /* CHSM_VALUES_VALUELONGMEMORY_H_ */
