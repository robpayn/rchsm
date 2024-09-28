/*
 * Updater.h
 */

#ifndef CHSM_UPDATER_H_
#define CHSM_UPDATER_H_

class DepManager;
class Value;
class Dynamic;

/*! 
  \brief
    CHSM abstraction for an updater of a dynamic value
  \details
    The composite hierarchy state machine values may be updated during
      a state machine simulation execution.
    Updaters are attached to dynamic values and provide the computational logic
      for calculating the new value when activated.
    For their calculations, updaters are likely to be dependent on other
      values in the state machine.
 */
class Updater
{
  public:
    
    Value* val_ = nullptr;
    
    /*! 
      \brief
        The calculations phase in which the updater should be operated
     */
    int phase_ = -1;
    
    /*!
      \brief
        Construct a new instance of the updater
     
      \param int
        The calculation phase in which the updater should be operated.
    */
    Updater(int);
    
    virtual ~Updater() {};
    
    /*!
      \brief
        Attach a dynamic value to the updater.
     
      \param Dynamic*
        A pointer to a value extending the dynamic class.
     
      \return
        No return value.
    */
    virtual void attachDynamicValue(Dynamic*);
    
    /*! 
      \brief
        Get the variables upon which the update method depends
     
      \param DepManager&
        Reference to the dependency manager handling dependencies 
     
      \return 
        No return value
     */
    virtual void setDependencies(DepManager&) = 0;
    
    /*! 
      \brief
        Update the attached dynamic value based on calculation from 
          other values.
     
      \return 
        No return value
     */
    virtual void update() = 0;

};

#endif /* CHSM_UPDATER_H_ */
