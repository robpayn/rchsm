/*
 * Variable.h
 */

#ifndef RCHSM_VARIABLE_H_
#define RCHSM_VARIABLE_H_

#include <string>
#include <sstream>
#include <memory>
#include "Value.h"

class Holon;

//! A CHSM Variable
/*!
  A variable is the atomic unit of organization in the Composite Hierarchy 
  State Machine architecture. 
  A variable is evaluated by a value, which can wrap arbitrary data types. 
  The variable will generally be a member of a Holon, which is a special kind 
  of variable that has a value composed of other variables. 
  The holon pointer for the root holon variable will be 
  a null pointer. 
  This is an adaptation of the composite pattern.
*/
class Variable
{
  public:
    // Attributes ///////////////////////
    
    //! The name of the variable
    std::string name_ = std::string("");
    
    //! The value of the variable
    Value* value_ = nullptr;
    
    //! The holon containing the variable
    Holon* holon_ = nullptr;
    
    
    // Constructors /////////////////////
    
    //! Constructor based on a provided name
    //!   \param std::string The name for the new variable object.
    Variable(std::string);
    

    // Destructor ///////////////////////
    
    virtual ~Variable();

        
    // Methods //////////////////////////
    
    //! Generic template for a method to get the value as the derived type
    //! \return A pointer to the value cast to the provided derived type
    //! \throw std::string An error message if the value of the variable
    //!   cannot be cast to the provided class
    /*!
      The T_VALUE provided to this function template should be the 
      class of the derived type extending Value 
      (e.g., ValueVarmap or ValueDouble) for this variable. 
    */ 
    template <class T_VALUE>
    T_VALUE* getValue()
    {
      T_VALUE* valuePointer = dynamic_cast <T_VALUE*> (value_);
      if (valuePointer != nullptr) {
        return valuePointer;
      } else {
        std::ostringstream error;
        error << "Type requested is not valid for the value in variable" 
              << name_;
        throw error.str();
      }
    }

    //! Get the current value as a character string
    //! \return The value represented as a string
    std::string getValueString();
    
    //! Set the pointer to the containing holon
    //! \return No return value
    void setHolon(Holon*);
    
    // void setValueFromString(std::string stringValue);
    
};

#endif /* RCHSM_VARIABLE_H_ */
