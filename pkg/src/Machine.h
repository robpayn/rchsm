/*
 * Machine.h
 */

#ifndef CHSM_MACHINE_H_
#define CHSM_MACHINE_H_

#include "CHSM/Holon.h"

class Matrix;
class Cell;
class Bound;
class DepManager;
class Solver;

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
    Machine(std::string, DepManager*, Solver*);
    
    virtual ~Machine();
    
    // Methods
    
    /*!
      \brief
        Initialize the state machine.
      \details
        Initialization is mostly setting up the time behavior and setting
        the dependencies of variables.
      \return
        No return value.
    */
    void init();
    
    /*!
      \brief
        Install a variable in the machine
      \param Variable*
        Pointer to the variable to be installed
      \param Holon*
        Pointer to the holon in which the variable should be installed
      \return
        No return value
    */
    void installVariable(Variable*, Holon*);
    
    /*!
      \brief
        Create a bound holon in the matrix
      \param std::string
        Character string with the name of the new bound
      \param Cell*
        Pointer to the "from" cell attached to the bound
      \param Cell*
        Pointer to the "to" cell attached to the bound
      \param Holon*
        Pointer to the holon in which the bound should be created.
        If this is a null pointer, the bound will be created in the Machine
        holon.
      \return
        Pointer to the bound holon that was created.
    */
    Bound* createBound(std::string, Cell*, Cell*, Holon*);
    
    /*!
      \brief
        Create a cell holon in the matrix
      \param std::string
        Name of the new cell
      \param Holon*
        Pointer to the holon in which the cell should be created.
        If this is a null pointer, the cell will be created in the Machine
        holon.
      \return
        Pointer to the cell holon that was created.
        
    */
    Cell* createCell(std::string, Holon*);
    
    /*!
      \brief
        Create a variable in the matrix
      \param std::string
        Name of the new Variable
      \param Value*
        Value for the new Variable
      \param Holon*
        Holon in which the new Variable should be installed
      \return
        Pointer to the variable that was created
    */
    Variable* createVariable(std::string, Value*, Holon*);
    
    /*!
      \brief
        Run the state machine
      \return
        No return value
    */
    void run();
    
};

#endif /* CHSM_MACHINE_H_ */
