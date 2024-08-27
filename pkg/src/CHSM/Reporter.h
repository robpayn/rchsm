/*
 * Reporter.h
 */

class Matrix;
class Holon;
class Variable;

/*!
  \brief
    An abstraction for a reporter that tracks values over a CHSM simulation
*/
class Reporter
{
  public:
    
    virtual ~Reporter() {};
    
    /*!
      \brief
        Close the reporter's memory
     
      \return
        No return value
    */
    virtual void close() = 0;
    
    /*!
      \brief
        Collect data from the CHSM model for later reporting
     
      \return
        No return value
    */
    virtual void collectData() = 0;
    
    /*!
      \brief
        Determine if the reporter is currently active
     
      \return
        Boolean true if the reporter is active, false if not.
        Data are not collected from inactive reporters.
    */
    virtual bool isActive() = 0;
    
    /*!
      \brief
        Open the reporter's memory
     
      \return
        No return value
    */
    virtual void open() = 0;
    
    /*!
      \brief
        Save the collected data
     
      \return
        No return value
    */
    virtual void saveData() = 0;

};