/*
 * MemoryDouble.h
 */

#ifndef CHSM_VALUES_MEMORYDOUBLE_H_
#define CHSM_VALUES_MEMORYDOUBLE_H_

#include "../Memory.h"
#include <string>

class ValueDouble;

class MemoryDouble : public Memory
{
  public:
    
    double* v_ = nullptr;
    
    double* m_ = nullptr;
    
    MemoryDouble(int);
    
    virtual ~MemoryDouble();
    
    virtual void attachDynamicValue(DynamicMemory*) override;
    
    void recall(int) override; 
    
    void store(int) override;
    
  private:
    
    void allocateMemory();
    
};

#endif /* CHSM_VALUES_MEMORYDOUBLE_H_ */
