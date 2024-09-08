/*
 * MemoryDouble.h
 */

#ifndef CHSM_VALUES_MEMORYDOUBLE_H_
#define CHSM_VALUES_MEMORYDOUBLE_H_

#include "../Memory.h"
#include <string>

class ValueDoubleMemory;

class MemoryDouble : public Memory
{
  public:
    ValueDoubleMemory* val_ = nullptr;
    
    double* m_ = nullptr;
    
    MemoryDouble(int);
    
    MemoryDouble(ValueDoubleMemory*, int);
    
    virtual ~MemoryDouble();
    
    Value* getValue() override;
    
    void recall(int) override; 
    
    void setValue(Value*) override;
    
    void store(int) override;
    
  private:
    
    void allocateMemory();
    
};

#endif /* CHSM_VALUES_MEMORYDOUBLE_H_ */
