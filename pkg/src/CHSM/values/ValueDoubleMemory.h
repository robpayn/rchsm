/*
 * ValueDoubleMemory.h
 */

#ifndef CHSM_VALUES_VALUEDOUBLEMEMORY_H_
#define CHSM_VALUES_VALUEDOUBLEMEMORY_H_

#include "ValueDouble.h"
#include "../DynamicMemory.h"

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
        in the provided dynamic phase
     
      \param int
        Phase of the dynamic value
    */
    ValueDoubleMemory(int);
    
    /*!
      \brief
        Create a new instance of the real number Value with memory
        with an initial value

      \param int
        Phase of the dynamic value
      \param double
        Initial double precision floating point value
    */
    ValueDoubleMemory(int, double);
    
    /*!
      \brief
        Create real number memory for the value
     
      \param int
        The size of the memory to be created
     
      \return
        The MemoryDouble that was created
    */
    Memory* createMemory(int) override;
    
};

#endif /* CHSM_VALUES_VALUEDOUBLEMEMORY_H_ */
