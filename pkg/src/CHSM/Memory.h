/*
 * Memory.h
 */

#ifndef CHSM_MEMORY_H_
#define CHSM_MEMORY_H_

class Value;

class Memory
{
  public:
    
    int memSize_;
    
    Memory(int);
    
    virtual void recall(int) = 0;
    
    virtual void setValue(Value*) = 0;
    
    virtual void store(int) = 0;
    
};

#endif /* CHSM_MEMORY_H_ */
