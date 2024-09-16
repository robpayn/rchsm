/*
 * StateDouble.h
 */

#ifndef CHSM_VALUES_STATEDOUBLE_H_
#define CHSM_VALUES_STATEDOUBLE_H_

#include "ValueDouble.h"
#include "../DynamicMemory.h"
#include <list>

class Holon;
class RateDouble;

/*!
  \brief
    A CHSM state with a double precision floating point value
*/
class StateDouble : public ValueDouble, public DynamicMemory
{
  public:
    /*!
      \brief
        A list of attached rates for calculating the net change in state
    */
    std::list<double*> rates_;
    
    /*!
      \brief
        A pointer to the time step
    */
    double* dt_ = nullptr;
    
    /*!
      \brief
        Create a new instance of the state with the given initial value
     
      \param Holon*
        Holon containing the time step variable
      \param std::string
        String with the name of the time step variable
      \param double
        The initial value of the state
      \param int
        The phase in which the state should be updated
    */
    StateDouble(Holon&, std::string, double, int);
    
    /*!
      \brief
        Attach a rate to the state
     
      \param double*
        A pointer to the value of the rate to be attached
     
      \return
        No return value
    */
    virtual void attachRate(double*);
    
    /*! 
      \brief
        Get the variables upon which the update method depends
     
      \param DepManager&
        Reference to the dependency manager handling dependencies 
     
      \return 
        No return value
    */
    virtual void setDependencies(DepManager&) override;
    
    /*! 
      \brief
        Update the value based on calculation from other variable values
     
      \return 
        No return value
    */
    virtual void update() override;
    
};

#endif /* CHSM_VALUES_STATEDOUBLE_H_ */
