/*
 * DynamicMemory.h
 */

#ifndef CHSM_DYNAMICMEMORY_H_
#define CHSM_DYNAMICMEMORY_H_

#include "Dynamic.h"
#include <memory>

class MemoryFactory;

/*!
  \brief
    An object that can be updated and can have memory attached
*/
class DynamicMemory : public Dynamic
{
  public:
    
    /*!
      \brief
        The factory for creating a memory object if needed for the solver
    */
    std::shared_ptr<MemoryFactory> memoryFactory_;
    
    /*!
      \brief
        Initialize a dynamic memory object
     
      \param int
        The phase in which the dynamic object should be updated
      \param std::shared_ptr<MemoryFactory>
        A smart pointer to the factory to use for creating memory
    */
    DynamicMemory(int, std::shared_ptr<MemoryFactory>);
    
};

#endif /* CHSM_DYNAMICMEMORY_H_ */
