/*
 * DynamicMemory.h
 */

#ifndef CHSM_DYNAMICMEMORY_H_
#define CHSM_DYNAMICMEMORY_H_

#include "Dynamic.h"

class Memory;

/*!
  \brief
    A dynamic value that can be updated and can have memory attached
  \details
    Value classes should extend DynamicMemory if the values will change
      during a state machine simulation and the solver requires some
      kind of memory within individual time steps.
    The type of the Memory attached to a DynamicMemory must be compatible 
      with the type of the Value extending DynamicMemory.
    Some solvers (e.g., Runge Kutta solvers) require memory of previous 
      states of the machine with the calculations of a single time step.
    Different types of memory may be installed to provide that feature and
      the appropriate type and size of memory must be compatible with the
      solver being used.
*/
class DynamicMemory : public Dynamic
{
  public:
    
    /*!
      \brief
        Pointer to the attached memory object
    */
    Memory* memory_ = nullptr;
    
    virtual ~DynamicMemory();
    
    /*!
      \brief
        Attach a memory object to the dynamic value.
     
      \param Memory*
        Pointer to the memory object to be attached.
        The type of the Memory must be compatible with the type of the
          Value extending DynamicMemory.
     
      \return 
        No return value.
    */
    virtual void attachMemory(Memory*);
    
};

#endif /* CHSM_DYNAMICMEMORY_H_ */
