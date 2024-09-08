/*
 * ValueDoubleMemory.h
 */

#ifndef CHSM_VALUES_VALUEDOUBLEMEMORY_H_
#define CHSM_VALUES_VALUEDOUBLEMEMORY_H_

#include "ValueDouble.h"
#include "../DynamicMemory.h"

class MemoryDoubleFactory;

/*!
  \brief
    A real number CHSM value that can add memory
*/
class ValueDoubleMemory : public ValueDouble, public DynamicMemory
{
  public:
    
    /*!
      \brief
        Create a new instance of the real number Value with memory
        with an initial value

      \param double
        Initial double precision floating point value
      \param int
        Phase of the dynamic value
     */
    ValueDoubleMemory(double, int);
    
};

#endif /* CHSM_VALUES_VALUEDOUBLEMEMORY_H_ */
