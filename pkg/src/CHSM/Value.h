/*
 * Value.h
 */

#ifndef RCHSM_VALUE_H_
#define RCHSM_VALUE_H_

#include <sstream>
#include <string>

class Variable;

//! An abstract value of a CHSM variable
/*!
  This describes the methods that must be implemented for full
  functionality of a value of a composite hierarchy state machine variable.
*/

class Value
{
  public:
    // Attributes ///////////////////////
    
    //! The variable containing this value.
    Variable* var_ = nullptr;
    
    
    // Constructors /////////////////////
    
    //! Constructs a new instance of the Value.
    Value();
    

    // Destructor ///////////////////////
    
    virtual ~Value();
    
    
    // Methods //////////////////////////
    
    //! Set the value from a string representation
    //!   \param std::string The string representation of the value.
    //! \return No return value
    virtual void fromString(std::string) = 0;
    
    //! Set the pointer to the variable containing this value
    //!   \param Variable* Pointer to the variable containing this value.
    //! \return No return value
    void setVariable(Variable*);
    
    //! Convert the value to a string
    //! \return A string representing the value
    virtual std::string toString() = 0;
};

#endif /* RCHSM_VALUE_H_ */