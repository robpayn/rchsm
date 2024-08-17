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
  ValueLong* val_ = nullptr;
  
  long* m_ = nullptr;
  
  MemoryLong(int);
  
  MemoryLong(ValueLong*, int);
  
  virtual ~MemoryLong();
  
  Value* getValue() override;
  
  void recall(int) override; 
  
  void setValue(Value*) override;
  
  void store(int) override;
  
private:
  
  void allocateMemory();
  
};

#endif /* CHSM_VALUES_MEMORYLONG_H_ */
