/*
 * Memory.h
 */

#ifndef CHSM_MEMORY_H_
#define CHSM_MEMORY_H_

#include <string>

class Value;

class Memory
{
  public:
    
    int memSize_;
    
    Memory(int);
    
    virtual Value* getValue() = 0;
    
    virtual void recall(int) = 0;
    
    virtual void setValue(Value*) = 0;
    
    virtual void store(int) = 0;
    
  protected:
    
    void throwIndexError(int, std::string);
    
};

#endif /* CHSM_MEMORY_H_ */
