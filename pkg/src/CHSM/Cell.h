/*
 * Cell.h
 */

#ifndef CHSM_CELL_H_
#define CHSM_CELL_H_

#include "Holon.h"
#include <string>
#include <unordered_map>

class Bound;

/*! 
  \brief 
    A cell holon for a CHSM
  \details
    A cell holds variables for calculating and holding the state of the
    composite hierarchy state machine.
    A cell is connected to bounds that holds variables responsible for
    calculating how the state of the machine should change.
    Together, cells and bounds define a network of pathways by which
    variables communicate for calculations.
*/
class Cell : public Holon
{
  public:
    
    // Attributes
    
    /*! 
      \brief
        A map of pointers to bound holons attached to this cell holon
    */
    std::unordered_map<std::string, Bound*> bounds_;
    
    // Constructors 
    
    /*! 
      \brief
        Constructs a new instance by name
     
      \param std::string 
        The name for the new cell
    */
    Cell(std::string);
    
    // Methods
    
    /*! 
      \brief
        Attach a bound to the cell
     
      \param Bound* 
        Pointer to the bound to attach
     
      \return 
        No return value
    */
    void attachBound(Bound*);
    
    /*! 
      \brief
        Get variables of a given name in attached bounds
     
      \param std::string 
        The variable name to seek in attached bounds
     
      \return 
        A map of pointers to bound variables with the given name
    */
    std::unordered_map<std::string, Variable*> getBoundVariables(std::string);
    
};

#endif /* CHSM_CELL_H_ */
