/*
 * MemoryBoolean.h
 */

#ifndef CHSM_VALUES_MEMORYBOOLEAN_H_
#define CHSM_VALUES_MEMORYBOOLEAN_H_

#include "../Memory.h"

class ValueBoolean;

class MemoryBoolean : public Memory
{
public:
  ValueBoolean* val_ = nullptr;
  
  bool* m_ = nullptr;
  
  MemoryBoolean(int);
  
  MemoryBoolean(ValueBoolean*, int);
  
  virtual ~MemoryBoolean();
  
  Value* getValue() override;
  
  void recall(int) override; 
  
  void setValue(Value*) override;
  
  void store(int) override;
  
private:
  
  void allocateMemory();
  
};


#endif /* CHSM_VALUES_MEMORYBOOLEAN_H_ */
