/*
 * RateDouble.h
 */

#ifndef CHSM_VALUES_RATEDOUBLE_H_
#define CHSM_VALUES_RATEDOUBLE_H_

#include "ValueDoubleMemory.h"
#include "../Rate.h"

/*!
  \brief
    A rate quantified by a real number
*/
class RateDouble : public ValueDoubleMemory, public Rate
{
  public:
    
    /*!
      \brief
        Rate affecting the state on the from side of the bound
    */
    double vf_ = nan("");
    
    /*!
      \brief
        The name of the state to which the rate should be attached
    */
    std::string stateName_;
    
    /*!
      \brief
        Create a new instance in the provided phase and attached the 
        given state name.
     
      \param int
        Phase in which the rate should be updated
      \param std::string
        Name of states to which the rate should be attached
    */
    RateDouble(int, std::string);
    
    /*!
      \brief
        Create a new instance with the provided initial value.
     
      \param int
        Phase in which the rate should be updated
      \param double
        Initial value of the state
      \param std::string
        Name of states to which the rate should be attached
     */
    RateDouble(int, double, std::string);
    
    /*!
      \brief
        Attach the states on either side of the bound in which the rate
        is installed
     
      \return
        No return value
    */
    void attachStates() override;
    
};

#endif /* CHSM_VALUES_RATEDOUBLE_H_ */
