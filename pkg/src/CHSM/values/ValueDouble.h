/*
 * ValueDouble.h
 */

#ifndef CHSM_VALUES_VALUEDOUBLE_H_
#define CHSM_VALUES_VALUEDOUBLE_H_

#include "../Value.h"
#include <cmath>

/*!
  \brief
    A CHSM value quantified by a single real number
*/
class ValueDouble : public Value
{
  public:
    
    /*!
      \brief
        The double precision floating point value
    */
    double v_ = nan("");
    
    /*!
      \brief
        Create a new instance of the class using the provided initial value
     
      \param double
        Initial double precision floating point value
    */
    ValueDouble(double);
    
    /*!
      \brief
        Create a new instance of the class using the provided string
        representation of the initial value
     
      \param std::string
        A string representation of the initial value
    */
    ValueDouble(std::string);
    
    virtual ~ValueDouble() {};
    
    /*! 
     \brief
       Set the real number value from a string representation
     
     \param std::string 
       The string representation of the real number value.
     
     \return 
       No return value
    */
    void fromString(std::string) override;
    
    /*! 
      \brief
        Convert the real number value to a string
     
      \return 
        A string representing the real number value
    */
    virtual std::string toString() override;
    
};

#endif /* CHSM_VALUES_VALUEDOUBLE_H_ */
