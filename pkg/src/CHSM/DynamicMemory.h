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
        Initialize a dynamic memory object
     
      \param int
        The phase in which the dynamic object should be updated
    */
    DynamicMemory(int);
    
    /*!
      \brief
        Create memory to be attached to the object
     
      \param int
        The number of slots of memory required
    */
    virtual Memory* createMemory(int) = 0;
    
};

#endif /* CHSM_DYNAMICMEMORY_H_ */
