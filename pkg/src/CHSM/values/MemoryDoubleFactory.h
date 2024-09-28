/*
 * MemoryDoubleFactory.h
 */

#ifndef CHSM_MEMORYDOUBLEFACTORY_H_
#define CHSM_MEMORYDOUBLEFACTORY_H_

#include "../MemoryFactory.h"

class MemoryDoubleFactory : public MemoryFactory
{
  public:
    
    MemoryDoubleFactory(int);
    
    Memory* createMemory(DynamicMemory*) override;
};

#endif /* CHSM_MEMORYDOUBLEFACTORY_H_ */
