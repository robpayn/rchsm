/*
 * ValueBooleanMemory.h
 */

#ifndef CHSM_VALUES_VALUEBOOLEANMEMORY_H_
#define CHSM_VALUES_VALUEBOOLEANMEMORY_H_

#include "ValueBoolean.h"
#include "../DynamicMemory.h"

/*!
  \brief
    A boolean CHSM value that can add memory
*/
class ValueBooleanMemory : public ValueBoolean, public DynamicMemory
{
public:
  
  /*!
    \brief
      Create a new instance of the boolean Value with memory
      in the provided dynamic phase
   
    \param int
      Phase of the dynamic value
  */
  ValueBooleanMemory(int);
  
  /*!
    \brief
      Create a new instance of the boolean Value with memory
      with an initial value
   
    \param int
      Phase of the dynamic value
    \param double
      Initial boolean value
  */
  ValueBooleanMemory(int, bool);
  
  /*!
    \brief
      Create boolean memory for the value
   
    \param int
      The size of the memory to be created
   
    \return
      The MemoryBoolean that was created
  */
  Memory* createMemory(int) override;
  
};

#endif /* CHSM_VALUES_VALUEBOOLEANMEMORY_H_ */
