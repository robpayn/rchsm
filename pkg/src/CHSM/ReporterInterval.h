/*
 * ReporterInterval.h
 */

#include "Reporter.h"
#include <string>

/*!
  \brief
    A reporter that operates at a prescribed iteration interval
*/
class ReporterInterval : Reporter
{
  public:
    
    /*!
      \brief
        The interval of iterations for reporting
    */
    int interval_;
    
    /*!
      \brief
        Pointer to the CHSM simulation iteration value
    */
    long* iteration_;
    
    /*!
      \brief
        Name to use to find the time cell in the matrix
    */
    std::string cellTimeName_ = "CellTime";
    
    /*!
      \brief
        Name to use to find the iteration variable in the time cell
    */
    std::string varNameIter_ = "Iteration";
    
    /*!
      \brief
        Create a new instance of the reporter with the provided interval
     
      \param int
        Interval between iterations for data collection
    */
    ReporterInterval(int, Variable&);
    
    /*!
      \brief
        Determine if the reporter is currently on an active iteration
     
      \return
        Boolean true if the current iteration is on an active iteration
        between intervals, false otherwise.
    */
    virtual bool isActive() override;

};