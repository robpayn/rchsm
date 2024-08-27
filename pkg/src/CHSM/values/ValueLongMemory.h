/*
 * ValueLongMemory.h
 */

#ifndef CHSM_VALUES_VALUELONGMEMORY_H_
#define CHSM_VALUES_VALUELONGMEMORY_H_

#include "ValueLong.h"
#include "../DynamicMemory.h"

/*!
  \brief
    An integer CHSM value that can add memory
*/
class ValueLongMemory : public ValueLong, public DynamicMemory
{
public:
  
  /*!
    \brief
      Create a new instance of the integer Value with memory
      updated in the provided dynamic phase
   
    \param int
      Phase in which the dynamic value is updated
   */
  ValueLongMemory(int);
  
  /*!
    \brief
      Create a new instance of the integer Value with memory
      updated in the provided dynamic phase
   
    \param int
      Phase in which the dynamic value is updated
    \param long
      Initial integer value
   */
  ValueLongMemory(int, long);
  
  /*!
    \brief
      Create integer memory for the value
   
    \param int
      The size of the memory to be created
   
    \return
      The MemoryLong that was created
   */
  Memory* createMemory(int) override;
  
};


#endif /* CHSM_VALUES_VALUELONGMEMORY_H_ */
