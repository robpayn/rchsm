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
    
    /*!
      \brief
        Pointer to the dynamic value associated with the memory
    */
    ValueBoolean* val_ = nullptr;
    
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
    
    /*!
      \brief
        Create a new instance of the memory
     
      \param ValueBoolean*
        Pointer to the value for which the memory is provided
      \param int
        Size of the memory
    */
    MemoryBoolean(ValueBoolean*, int);
    
    virtual ~MemoryBoolean();
    
    /*!
      \brief
        Get a pointer to the value for which the memory is provided
     
      \return
        Pointer to the associated value
    */
    Value* getValue() override;
    
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
        Set the pointer to the value associated with the memory.
     
      \param Value*
        Pointer to the Value to be associated with the memory.
     
      \return
        No return value.
    */
    void setValue(Value*) override;
    
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
