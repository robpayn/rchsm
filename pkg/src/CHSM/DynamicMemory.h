/*
 * DynamicMemory.h
 */

#ifndef CHSM_DYNAMICMEMORY_H_
#define CHSM_DYNAMICMEMORY_H_

#include "Dynamic.h"

class Memory;

/*!
  \brief
    An object that can be updated and can have memory attached
*/
class DynamicMemory : public Dynamic
{
  public:
    
    /*!
      \brief
        Pointer to the memory object if needed for the solver
    */
    Memory* memory_ = nullptr;
    
    /*!
      \brief
        Initialize a dynamic memory object
     
      \param int
        The phase in which the dynamic object should be updated
    */
    DynamicMemory(int);
    
    virtual ~DynamicMemory();
    
    /*!
      \brief
        Attach a memory object to the dynamic value.
     
      \param Memory*
        Pointer to the memory to be attached.
     
      \return 
        No return value.
    */
    virtual void attachMemory(Memory*);
    
};

#endif /* CHSM_DYNAMICMEMORY_H_ */
