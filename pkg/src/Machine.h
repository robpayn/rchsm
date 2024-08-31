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
  \details
    The state machine object is the entry point for creating a CHSM simulator.
    Once a state machine is created with an appropriate variable map value,
      (e.g., a Matrix) the variable map can be populated with holons and 
      variables that define the state of the machine and how that 
      state changes.
    Generally, at least one Reporter is configured and installed to track the 
      values of select variables in the variable map throughout the execution 
      of a simulation.
    Before execution, this time-stepping state machine requires a pointer
      to a valid time variable.
    The boolean value of this valid time variable will determine when the 
      simulation will terminate by changing from a true to a false value.
    Once the machine and its corresponding variable map are configured, the
      simulation is executed using the run method.
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
        Pointer to the reporter to be installed
     
      \return
        No return value
    */
    void installReporter(Reporter*);
    
    /*!
      \brief
        Run the state machine
     
      \return
        No return value
    */
    void run();
    
    /*!
      \brief
        Set the valid time variable with the boolean value that determines
          when the simulation will terminate
     
      \param Variable*
        Pointer to the variable with the boolean value that determines if 
          the current simulation time is valid (true) or not (false).
     
      \return
        No return value
    */
    void setTimeValidVariable(Variable*);
    
};

#endif /* CHSM_MACHINE_H_ */
