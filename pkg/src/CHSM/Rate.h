/*
 * Rate.h
 */

#ifndef CHSM_RATE_H_
#define CHSM_RATE_H_

/*!
  \brief
    Abstraction for a CHSM rate that determines the change in a state
*/
class Rate
{
  public:
    /*!
      \brief
        Attach the states on the to and from side of the bound in which the
        rate is installed
     
      \return
        No return value
    */
    virtual void attachStates() = 0;
    
};

#endif /* CHSM_RATE_H_ */
