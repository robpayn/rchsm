/*
 * MemoryDouble.h
 */

#ifndef CHSM_VALUES_MEMORYDOUBLE_H_
#define CHSM_VALUES_MEMORYDOUBLE_H_

#include "../Memory.h"
#include <string>

class ValueDouble;

/*!
  \brief
    Memory for a double precision floating point dynamic value
*/
class MemoryDouble : public Memory
{
  public:
    
    /*!
      \brief
        Pointer to the double precision floating point value 
          for which memory is provided.
    */
    double* v_ = nullptr;
    
    /*!
      \brief
        Array of double precision floating point values providing the memory
    */
    double* m_ = nullptr;
    
    /*!
      \brief
        Create a new instance of the memory
     
      \param int
        Number of elements in the memory
    */
    MemoryDouble(int);
    
    virtual ~MemoryDouble();
    
    /*!
      \brief
        Attach the dynamic double precision floating point value 
          for which memory is provided.
     
      \param DynamicMemory*
        Pointer to the dynamic double precision floating point value 
          to which the memory should be attached.
        The dynamic memory object provided must also extend type ValueDouble.
     
      \return
        No return value
    */
    virtual void attachDynamicValue(DynamicMemory*) override;
    
    void recall(int) override; 
    
    void store(int) override;
    
  private:
    
    void allocateMemory();
    
};

#endif /* CHSM_VALUES_MEMORYDOUBLE_H_ */
