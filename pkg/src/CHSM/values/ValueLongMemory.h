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
   
    \param long
      Initial integer value
    \param int
      Phase in which the dynamic value is updated
    \param std::shared_ptr<MemoryFactory>
      A smart pointer to the factory to use for creating memory
   */
  ValueLongMemory(long, int, std::shared_ptr<MemoryFactory>);
  
};


#endif /* CHSM_VALUES_VALUELONGMEMORY_H_ */
