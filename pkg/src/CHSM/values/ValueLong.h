/*
 * ValueLong.h
 */

#ifndef CHSM_VALUES_VALUELONG_H_
#define CHSM_VALUES_VALUELONG_H_

#include "../Value.h"
#include <climits>
#include <cmath>

/*!
  \brief
    A CHSM value quantified by an integer number
*/
class ValueLong : public Value
{
  public:
    // Attributes
    
    /*!
      \brief
        The long integer value
    */
    long v_ = LONG_MIN;
    
    // Constructors
    
    /*!
      \brief
        Create a new instance of an integer Value with the provided value
     
      \param long
        Initial integer value
    */
    ValueLong(long);
    
    /*!
      \brief
        Create a new instance of an integer Value with the provided string
        representation of the value
     
      \param std::string
        A string representation of the value
    */
    ValueLong(std::string);
    
    // Methods
    
    /*! 
      \brief
        Set the integer value from a string representation
     
      \param std::string 
        The string representation of the integer value.
     
      \return 
        No return value
    */
    void fromString(std::string valueString) override;
    
    /*! 
      \brief
        Convert the integer value to a string
   
      \return 
        A string representing the integer value
    */
    std::string toString() override;
  
};

#endif /* CHSM_VALUES_VALUELONG_H_ */
