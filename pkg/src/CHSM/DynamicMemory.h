/*
 * DynamicMemory.h
 */

#ifndef CHSM_DYNAMICMEMORY_H_
#define CHSM_DYNAMICMEMORY_H_

#include "Dynamic.h"

class Memory;

class DynamicMemory : public Dynamic
{
  public:
    
    DynamicMemory(int);
    
    virtual Memory* createMemory(int) = 0;
    
};

#endif /* CHSM_DYNAMICMEMORY_H_ */
