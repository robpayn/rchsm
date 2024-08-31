/*
 * ValueDouble.h
 */

#ifndef CHSM_VALUES_VALUEDOUBLE_H_
#define CHSM_VALUES_VALUEDOUBLE_H_

#include "../Value.h"
#include <cmath>

/*!
  \brief
    A CHSM value quantified by a real number
*/
class ValueDouble : public Value
{
  public:
    // Attributes
    
    /*!
      \brief
        The double precision floating point value
    */
    double v_ = nan("");
    
    // Constructors
    
    /*!
      \brief
        Create a new instance of a real number Value with the provided value
     
      \param double
        Initial double precision floating point value
    */
    ValueDouble(double);
    
    /*!
      \brief
        Create a new instance of a real number Value with the provided string
        representation of the value
     
      \param std::string
        A string representation of the value
    */
    ValueDouble(std::string);
    
    // Destructor
    
    virtual ~ValueDouble();
    
    // Methods
    
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
