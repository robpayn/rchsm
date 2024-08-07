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
    ValueDouble* val_ = nullptr;
    
    double* realm_ = nullptr;
    
    MemoryDouble(int);
    
    MemoryDouble(ValueDouble*, int);
    
    virtual ~MemoryDouble();
    
    void recall(int) override; 
    
    void setValue(Value*) override;
    
    void store(int) override;
    
  private:
    
    void allocateMemory();
    
    void throwIndexError(int, std::string);
    
};

#endif /* CHSM_VALUES_MEMORYDOUBLE_H_ */
