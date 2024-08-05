/*
 * Holon.h
 */

#ifndef RCHSM_HOLON_H_
#define RCHSM_HOLON_H_

#include "Variable.h"
#include "ValueVarmap.h"

//! A CHSM Holon
/*!
  A holon in a Composite Hierarchy State Machine is a type of CHSM Variable 
  where the value of the variable is defined by a collection of other 
  Variables. 
  The composition relationship is implemented by the value of the holon 
  variable being of type ValueVarmap. 
  Hierarchies emerge from holons being variables within other holons.
  This is an adaptation of the composite pattern.
*/
class Holon : public Variable
{
  public:
    // Constructors /////////////////////
    
    //! Constructor based on a provided name
    //!   \param std::string The name for the new holon object.
    Holon(std::string);
    
    
    // Methods //////////////////////////
    
    //! Add a Variable to the holon
    //!   \param Variable* A pointer to a variable
    //! \return No return value
    /*!
      Note that the holon will assume ownership of the Variable referenced
      by the pointer.
      The Variable will be deleted if the holon's destructor is called.
    */
    void addVariable(Variable*);
    
    Variable* getVariable(std::string);
};

#endif /* RCHSM_HOLON_H_ */
