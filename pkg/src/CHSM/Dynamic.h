/*
 * Dynamic.h
 */

#ifndef CHSM_DYNAMIC_H_
#define CHSM_DYNAMIC_H_

class Updater;

/*! 
  \brief
    CHSM abstraction for defining a value that can be updated
  \details
    The composite hierarchy state machine values may be updated during
      a state machine simulation execution.
    Values that need to updated will should extend Dynamic,
      which provides the feature of allowing an updater to be attached
      to the value.
*/
class Dynamic
{
  public:
    
    /*!
      \brief
        Pointer to the attached updater that changes the dynamic value.
    */
    Updater* updater_ = nullptr;

    virtual ~Dynamic();
    
    /*!
      \brief
        Attach an updater to the dynamic value.
     
      \param Updater*
        Pointer to the updater to be attached.
        The updater must be compatible with the type of the Value that is
          extending Dynamic.
    */
    virtual void attachUpdater(Updater* updater);
    
};

#endif /* CHSM_DYNAMIC_H_ */
