/*
 * Value.h
 */

#ifndef CHSM_VALUE_H_
#define CHSM_VALUE_H_

#include <string>

class Variable;

/*! 
  \brief
    An abstract value of a CHSM variable
  \details
    This describes the methods that must be implemented for full
    functionality of a value of a composite hierarchy state machine variable.
*/

class Value
{
  public:
    
    // Attributes ///////////////////////
    
    /*! 
      \brief
        The variable containing this value.
    */
    Variable* var_ = nullptr;
    
    
    // Constructors /////////////////////
    
    /*! 
      \brief
        Constructs a new instance of the Value.
    */
    Value();
    

    // Destructor ///////////////////////
    
    virtual ~Value();
    
    
    // Methods //////////////////////////
    
    /*! 
      \brief
        Set the value from a string representation
      \param std::string 
        The string representation of the value.
      \return 
        No return value
    */
    virtual void fromString(std::string) = 0;
    
    /*! 
      \brief
        Query if the value is currently defined
      \return
        Boolean true if value is defined, false otherwise
    */
    virtual bool isDefined() = 0;
    
    /*! 
      \brief
        Set the pointer to the variable containing this value
      \param Variable* 
        Pointer to the variable containing this value.
      \return 
        No return value
    */
    void setVariable(Variable*);
    
    /*! 
      \brief
        Convert the value to a string
      \return 
        A string representing the value
    */
    virtual std::string toString() = 0;
    
};

#endif /* CHSM_VALUE_H_ */