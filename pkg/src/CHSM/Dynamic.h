/*
 * Dynamic.h
 */

#ifndef CHSM_DYNAMIC_H_
#define CHSM_DYNAMIC_H_

class DepManager;

/*! 
  \brief
    CHSM abstraction for defining an object that can be updated
  \details
    The composite hierarchy state machine objects may be updated during
    a state machine simulation execution.
    Objects that need to updated will need to inherit from dynamic, allowing
    their dependencies to be tracked and their update method to be called
    in the proper order.
*/
class Dynamic
{
  public:
    
    // Attributes ///////////////////////
    
    /*! 
      \brief
        The calculation phase of the variable
    */
    int phase_ = -1;

    
    // Methods //////////////////////////
    
    Dynamic(int);
    
    /*! 
      \brief
        Get the variables upon which the update method depends
      \return 
        No return value
    */
    virtual void setDependencies(DepManager*) = 0;
    
    /*! 
      \brief
        Update the value based on calculation from other variable values
      \return 
        No return value
    */
    virtual void update() = 0;
};

#endif /* CHSM_DYNAMIC_H_ */
