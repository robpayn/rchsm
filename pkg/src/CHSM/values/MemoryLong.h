/*
 * MemoryLong.h
 */

#ifndef CHSM_VALUES_MEMORYLONG_H_
#define CHSM_VALUES_MEMORYLONG_H_

#include "../Memory.h"
#include <string>

class ValueLong;

/*!
  \brief
    Memory for a long integer dynamic value
*/
class MemoryLong : public Memory
{
  public:
    
    /*!
      \brief
        Pointer to the long integer value for which memory is provided.
    */
    long* v_ = nullptr;
    
    /*!
      \brief
        Array of long integer values providing the memory
    */
    long* m_ = nullptr;
    
    /*!
      \brief
        Create a new instance of the memory
     
      \param int
        Number of elements in the memory
    */
    MemoryLong(int);
    
    virtual ~MemoryLong();
    
    /*!
      \brief
        Attach the dynamic long integer value for which memory is provided.
     
      \param DynamicMemory*
        Pointer to the dynamic long integer value to which 
          the memory should be attached.
        The dynamic memory object provided must also extend type ValueLong.
     
      \return
        No return value
    */
    virtual void attachDynamicValue(DynamicMemory*) override;
    
    void recall(int) override; 
    
    void store(int) override;
    
  private:
    
    void allocateMemory();
  
};

#endif /* CHSM_VALUES_MEMORYLONG_H_ */
