/*
 * Dynamic.h
 */

#ifndef RCHSM_DYNAMIC_H_
#define RCHSM_DYNAMIC_H_

//! CHSM abstraction for defining an object that can be updated
/*!
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
    
    //! The calculation phase of the variable
    int phase_ = 0;

    
    // Methods //////////////////////////
    
    //! Get the variables upon which the update method depends
    //! \return Nothing returned
    virtual void setDependencies() = 0;
    
    //! Update the value based on calculation from other variable values
    //! \return Nothing returned
    virtual void update() = 0;
};

#endif /* RCHSM_DYNAMIC_H_ */
