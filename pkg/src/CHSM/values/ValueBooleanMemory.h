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
        with an initial value
     
      \param bool
        Initial boolean value
      \param int
        Phase of the dynamic value
     */
    ValueBooleanMemory(bool, int);
  
};

#endif /* CHSM_VALUES_VALUEBOOLEANMEMORY_H_ */
