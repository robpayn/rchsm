/*
 * Bound.h
 */

#ifndef CHSM_BOUND_H_
#define CHSM_BOUND_H_

#include "Holon.h"

class Cell;

/*! 
  \brief
    A bound holon for a CHSM
  \details
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
    
    /*! 
      \brief
        Cell attached to the "from" site of the bound.
      \details
        "From" and "to" specifiers are references for managing
        the sign conventions for calculations.
    */
    Cell* cellFrom_;

    /*! 
      \brief
        Cell attached to the "to" site of the bound.
      \details
       "From" and "to" specifiers are references for managing
       the sign conventions for calculations.
    */
    Cell* cellTo_;
    
    // Constructors/Destructor
    
    /*! 
      \brief
        Construct a new instance by name
     
      \param std::string 
        Name for the new bound.
    */
    Bound(std::string);
    
    /*! 
      \brief
        Construct a new instance attached to cells
      \details
        Passing null pointers for cells is valid if the bound functions
        as an external edge of the state machine.
     
      \param std::string
        Name for the new bound
      \param Cell* 
        Pointer to "from" cell
      \param Cell* 
        Pointer to "to" cell
    */
    Bound(std::string, Cell*, Cell*);
    
};

#endif /* CHSM_BOUND_H_ */
