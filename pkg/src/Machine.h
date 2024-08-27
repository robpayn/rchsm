/*
 * Machine.h
 */

#ifndef CHSM_MACHINE_H_
#define CHSM_MACHINE_H_

#include "CHSM/Holon.h"
#include <list>

class Matrix;
class Solver;
class Reporter;

/*!
  \brief
    A simple composite hierarchy state machine
*/
class Machine : public Holon
{
  public:
    
    // Attributes
    
    /*!
      \brief
        A list of reporters that record values through a simulation
    */
    std::list<Reporter*> reporters_;
    
    /*!
      \brief
        A pointer to the valid time variable value
    */
    bool* timeValid_ = nullptr;
    
    // Constructors/Destructor
    
    /*!
      \brief
        Create a new machine with the given name
     
      \param std::string
        Character string with the name of the machine
    */
    Machine(std::string, Matrix*);
    
    virtual ~Machine();
    
    // Methods
    
    /*!
      \brief
        Install a reporter that tracks values during a state machine simulation
      
      \param Reporter*
        A pointer to the reporter to be installed
    */
    void installReporter(Reporter*);
    
    /*!
      \brief
        Run the state machine
     
      \return
        No return value
    */
    void run();
    
    void setTimeValidVariable(Variable*);
    
};

#endif /* CHSM_MACHINE_H_ */
