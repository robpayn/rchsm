/*
 * StateDouble.h
 */

#ifndef CHSM_VALUES_STATEDOUBLE_H_
#define CHSM_VALUES_STATEDOUBLE_H_

#include "ValueDoubleMemory.h"
#include <list>

class Bound;
class RateDouble;

/*!
  \brief
    A CHSM state with a double precision floating point value
*/
class StateDouble : public ValueDoubleMemory
{
  public:
    /*!
      \brief
        A list of attached rates for caculating the net change in state
    */
    std::list<double*> rates_;
    
    /*!
      \brief
        A pointer to the time step
    */
    double* dt_ = nullptr;
    
    /*!
      \brief
        Create a new instance of the state in the give dynamic phase
      
      \param int
        The phase in which the state should be updated
    */
    StateDouble(int);
    
    /*!
      \brief
        Create a new instance of the state with the given initial value
     
      \param int
        The phase in which the state should be updated
      \param double
        The initial value of the state
    */
    StateDouble(int, double);
    
    /*!
      \brief
        Attach a rate to the state
     
      \param double*
        A pointer to the value of the rate to be attached
     
      \return
        No return value
    */
    void attachRate(double*);
    
    /*! 
      \brief
        Get the variables upon which the update method depends
     
      \param DepManager*
        A pointer to the dependency manager handling dependencies 
     
      \return 
        No return value
    */
    void setDependencies(DepManager&) override;
    
    /*! 
      \brief
        Update the value based on calculation from other variable values
     
      \return 
        No return value
    */
    void update() override;
    
};

#endif /* CHSM_VALUES_STATEDOUBLE_H_ */
