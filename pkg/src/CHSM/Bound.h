/*
 * Bound.h
 */

#ifndef CHSM_BOUND_H_
#define CHSM_BOUND_H_

#include "Holon.h"

class Cell;

//! A bound holon for a CHSM
/*!
  A bound holds variables responsible for calculating how the state 
  of a composite hierarchy state machine should change.
  A bound is attached to one or two cells, providing information to
  those cells about how their state should change.
  Together, cells and bounds define a network of pathways by which
  variables communicate for calculations.
*/
class Bound : public Holon
{
  public:
    // Attributes
    
    //! Cell attached to the "from" site of the bound.
    /*!
      "From" and "to" specifiers are references for managing
      the sign conventions for calculations.
    */
    Cell* cellFrom_;

    //! Cell attached to the "to" site of the bound.
    /*!
     "From" and "to" specifiers are references for managing
     the sign conventions for calculations.
     */
    Cell* cellTo_;
    
    // Constructors/Destructor
    
    //! Construct a new instance by name
    //!   \param std::string Name for the new bound.
    Bound(std::string);
    
    //! Construct a new instance attached to cells
    //!   \param Cell* Pointer to "from" cell
    //!   \param Cell* Pointer to "to" cell
    /*!
      Passing null pointers for cells is valid if the bound functions
      as an external edge of the state machine.
    */
    Bound(std::string, Cell*, Cell*);
    
};

#endif /* CHSM_BOUND_H_ */
