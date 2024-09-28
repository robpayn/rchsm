/*
 * MemoryBoolean.h
 */

#ifndef CHSM_VALUES_MEMORYBOOLEAN_H_
#define CHSM_VALUES_MEMORYBOOLEAN_H_

#include "../Memory.h"

class ValueBoolean;

/*!
  \brief
    Memory for a boolean dynamic value
*/
class MemoryBoolean : public Memory
{
  public:
    
    bool* v_ = nullptr;
    
    /*!
      \brief
        Array of boolean values providing the memory
    */
    bool* m_ = nullptr;
    
    /*!
      \brief
        Create a new instance of the memory
     
      \param int
        Size of the memory
    */
    MemoryBoolean(int);
    
    virtual ~MemoryBoolean();
    
    virtual void attachDynamicValue(DynamicMemory*) override;
    
    /*!
      \brief
        Recall a given value from the memory.
     
      \param int
        The index of the memory to recall.
     
      \return
        No return value.
    */
    void recall(int) override; 
    
    /*!
      \brief
        Store a value to a given index of the memory.
     
      \param int
        Index of the memory where the value should be saved.
     
      \return
        No return value.
    */
    void store(int) override;
    
  private:
    
    void allocateMemory();
  
};


#endif /* CHSM_VALUES_MEMORYBOOLEAN_H_ */
