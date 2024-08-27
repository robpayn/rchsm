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
        The solver to use for managing the solution algorithm for each time step
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
        Set the dependencies of the matrix using the internal dependency
        manager member
     
      \return
        No return value
     */
    void setDependencies();
    
    /*!
      \brief
        Set the dependencies of the matrix using the provided dependency
        manager
     
      \param DepManager&
        Reference for the dependency manager to notify of dependencies
     
      \return
        No return value
    */
    void setDependencies(DepManager&) override;
    
    /*!
      \brief
        Update the values of the matrix
     
      \return
        No return value
    */
    void update() override;
    
};

#endif /* CHSM_MATRIX_H_ */
