/*
 * StateDouble.h
 */

#ifndef CHSM_VALUES_STATEDOUBLE_H_
#define CHSM_VALUES_STATEDOUBLE_H_

#include "../Updater.h"
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
        Create a new instance of the state with the given initial value
     
      \param Holon*
        Holon containing the time step variable
      \param std::string
        String with the name of the time step variable
      \param double
        The initial value of the state
      \param int
        The phase in which the state should be updated
      \param Updater*
        (Optional) An custom updater to attach to the state.
        Defaults to nullptr, which results in the standard updater being
          attached.
        Note that the timeHolon, timeStepName, and phase arguments will have
          no effect if a custom updater is provided.
    */
    StateDouble(Holon&, std::string, double, int, Updater* = nullptr);
    
    /*!
      \brief
        Attach a rate to the state
     
      \param double*
        A pointer to the value of the rate to be attached
     
      \return
        No return value
    */
    virtual void attachRate(double*);
    
};

class StateDoubleUpdater : public Updater
{
public:
  
  /*!
    \brief
      A pointer to the time step
  */
  double* dt_ = nullptr;
  
  /*!
    \brief
      A list of attached rates for calculating the net change in state
  */
  std::list<double*> rates_;
  
  /*!
    \brief
      Pointer to the value to be updated
  */
  double* v_ = nullptr;
  
  /*!
    \brief
      Construct a new instance of the updater
   
    \param Holon&
      Reference to the time holon
    \param std::string
      String with the name of the time step variable
    \int
      Calculation phase in which the updater should operate
  */
  StateDoubleUpdater(Holon&, std::string, int);
  
  /*!
    \brief
      Attach a rate to the state
   
    \param double*
      Pointer to the real value of the rate
   
    \return
      No return value.
  */
  virtual void attachRate(double*);
  
  /*! 
    \brief
      Get the variables upon which calculations in the update method depend
   
    \param DepManager&
      Reference to the dependency manager handling dependencies 
   
    \return 
      No return value
  */
  virtual void setDependencies(DepManager&) override;
  
  /*! 
    \brief
      Update the value based on calculation from other values
   
    \return 
      No return value
  */
  virtual void update() override;
  
};

#endif /* CHSM_VALUES_STATEDOUBLE_H_ */
