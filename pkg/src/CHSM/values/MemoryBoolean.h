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
        Pointer to the boolean value for which memory is provided
    */
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
    
    /*!
      \brief
        Attach the dynamic boolean value for which memory is provided
     
      \param DynamicMemory*
        Pointer to the dynamic boolean value to which the memory 
          should be attached.
        The dynamic memory object provided must also extend type ValueBoolean.
     
      \return
        No return value
    */
    virtual void attachDynamicValue(DynamicMemory*) override;
    
    void recall(int) override; 
    
    void store(int) override;
    
  private:
    
    void allocateMemory();
  
};


#endif /* CHSM_VALUES_MEMORYBOOLEAN_H_ */
