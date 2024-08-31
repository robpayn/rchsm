/*
 * Matrix.h
 */

#ifndef CHSM_MATRIX_H_
#define CHSM_MATRIX_H_

#include "CHSM/values/ValueVarmap.h"
#include "CHSM/Dynamic.h"

class DepManager;
class Cell;
class Bound;
class Holon;
class Solver;

/*!
  \brief
    A dynamic variable map value for storing a matrix of cells and bounds
  \details
    A matrix is a variable map for a state machine (e.g., Machine) designed 
      to track the state of a system based on variables quantifying the 
      behavior of Cell and Bound holons.
    A Cell Holon generally contains variables that maintain the state of the
      system, and a Bound Holon contains variables that determine the rate at
      which the state of the system is changing.
    Bound holons either connect to two adjacent cells to allow constituent 
      variables to simulate cell interactions, or Bound holons connect to a 
      single cell to allow constituent variables to simulate the interaction
      of that cell with external entities.
    The resulting network of bounds and cells are the matrix within which
      constituent variables are installed for tracking the state of a system.
    The matrix requires definition of a dependency manager (derivative of 
      DepManager) that is used to determine the order in which constituent
      variables with dynamic values are updated.
    Before the matrix can be used to update the state of the system, a Solver 
      must be installed to determine the solution strategy 
      used to update the values of constituent variables.
    Also, the dependencies must be set, which will propagate to setting and
      managing the dependencies of constituent variables to determine the
      order in which values are updated by the Solver.
*/
class Matrix : public ValueVarmap, public Dynamic
{
  public:
    
    /*!
      \brief
        The dependency manager to determine order of dynamic value updates
    */
    DepManager* dm_ = nullptr;
    
    /*!
      \brief
        The solver to use for managing the solution algorithm for each
          time step.
    */
    Solver* solver_ = nullptr;
    
    /*!
      \brief
        Create a new instance of the matrix with the provided dependency
        manager.
     
      \param DepManager*
        Pointer to the dependency manager to install in the matrix
    */
    Matrix(DepManager*);
    
    virtual ~Matrix();
    
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
        Reference to the holon in which the bound should be created.
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
        Pointer to a value for the new Variable
      \param Holon&
        Reference to a holon in which the new Variable should be installed
     
      \return
        Pointer to the variable that was created
    */
    Variable* createVariable(std::string, Value*, Holon&);
    
    /*!
      \brief
        Install a solver for updating values during a time step
      
      \param Solver*
        Pointer to a solver.
        The matrix will take ownership of the solver and its deconstructor
          will delete the associated memory.
     
      \return
        No return value
    */
    void installSolver(Solver*);
    
    /*!
      \brief
        Install a variable in the matrix
     
      \param Variable*
        Pointer to the variable to be installed
      \param Holon&
        Reference to the holon in which the variable should be installed
     
      \return
        No return value
    */
    void installVariable(Variable*, Holon&);
    
    /*!
      \brief
        Set the dependencies of dynamic values in the matrix using the 
          member dependency manager.
     
      \return
        No return value
     */
    void setDependencies();
    
    /*!
      \brief
        Set the dependencies of the matrix using the provided dependency
        manager.
     
      \param DepManager&
        Reference to the dependency manager that should be notified of
          critical dependencies.
     
      \return
        No return value
    */
    void setDependencies(DepManager&) override;
    
    /*!
      \brief
        Update the dynamic values of the variables in the matrix
     
      \return
        No return value
    */
    void update() override;
    
};

#endif /* CHSM_MATRIX_H_ */
