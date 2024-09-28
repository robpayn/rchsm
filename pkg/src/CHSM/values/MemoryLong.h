/*
 * MemoryLong.h
 */

#ifndef CHSM_VALUES_MEMORYLONG_H_
#define CHSM_VALUES_MEMORYLONG_H_

#include "../Memory.h"
#include <string>

class ValueLong;

class MemoryLong : public Memory
{
  public:
    
    long* v_ = nullptr;
    
    long* m_ = nullptr;
    
    MemoryLong(int);
    
    virtual ~MemoryLong();
    
    virtual void attachDynamicValue(DynamicMemory*) override;
    
    void recall(int) override; 
    
    void store(int) override;
    
  private:
    
    void allocateMemory();
  
};

#endif /* CHSM_VALUES_MEMORYLONG_H_ */
