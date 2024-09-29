/*
 * Memory.h
 */

#ifndef CHSM_MEMORY_H_
#define CHSM_MEMORY_H_

#include <string>

class Value;
class DynamicMemory;

/*!
  \brief
    A CHSM abstraction for memory that can be attached to a value
*/
class Memory
{
  public:
    
    /*!
      \brief
        The value for which memory is provided
    */
    Value* val_ = nullptr;
    
    /*!
      \brief
        The number of elements in the memory
    */
    int memSize_;
    
    /*!
      \brief
        Create a new instance of memory of the provided size
     
      \param int
        The number of elements in the memory
    */
    Memory(int);
    
    virtual ~Memory() {};
    
    /*!
      \brief
        Attach the dynamic value for which memory is provided
     
      \param DynamicMemory*
        Pointer to the dynamic value to which the memory should be attached
     
      \return
        No return value
    */
    virtual void attachDynamicValue(DynamicMemory*);

    /*!
      \brief
        Recall the provided element of the memory to the dynamic value
     
      \param int
        The element of the memory to be recalled to the dynamic value
     
      \return
        No return value
    */
    virtual void recall(int) = 0;
    
    /*!
      \brief
        Store the current dynamic value in the provided element of the memory
     
      \param int
        The element of memory in which the current dynamic value 
          should be stored
     
      \return
        No return value
    */
    virtual void store(int) = 0;
    
  protected:
    
    /*!
      \brief
        Throw an index error in memory access
     
      \param int
        The memory index causing the problem
      \param std::string
        The mode of the memory throwing the error
     
      \return
        No return value
      \throws std::runtime_error
        Throws a runtime error when called with the provided message
    */
    void throwIndexError(int, std::string);
    
};

#endif /* CHSM_MEMORY_H_ */
