/*
 * Memory.h
 */

#ifndef CHSM_MEMORY_H_
#define CHSM_MEMORY_H_

#include <string>

class Value;

/*!
  \brief
    A CHSM abstraction for memory that can be attached to a value
*/
class Memory
{
  public:
    
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
    
    /*!
      \brief
        Get the value to which the memory is attached
     
      \return
        Pointer to the value to which the memory is attached
    */
    virtual Value* getValue() = 0;
    
    /*!
      \brief
        Recall the provided element of the memory to the value
     
      \param int
        The element of the memory to be recalled to the value
     
      \return
        No return value
    */
    virtual void recall(int) = 0;
    
    /*!
      \brief
        Set the value to which the memory is attached
     
      \param Value*
        Pointer to the value to which the memory should be attached
     
      \return
        No return value
    */
    virtual void setValue(Value*) = 0;
    
    /*!
      \brief
        Store the current value in the provided element of the memory
     
      \param int
        The element of memory in which the current value should be stored
     
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
