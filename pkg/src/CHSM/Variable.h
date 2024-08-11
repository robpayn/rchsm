/*
 * Variable.h
 */

#ifndef CHSM_VARIABLE_H_
#define CHSM_VARIABLE_H_

#include <string>
#include <sstream>

class Value;
class Holon;

/*! 
  \brief
    A CHSM Variable
  \details
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
    
    /*! 
      \brief
        The name of the variable
    */
    std::string name_ = std::string("");
    
    /*! 
      \brief
        The value of the variable
    */
    Value* value_ = nullptr;
    
    /*! 
      \brief
        The holon containing the variable
    */
    Holon* holon_ = nullptr;
    
    
    // Constructors /////////////////////
    
    /*! 
      \brief
        Constructor based on a provided name and value object
      \param std::string 
        The name for the new variable object.
      \param Value* 
        Pointer to the value composing the Variable.
      \details
        Note that the Variable will take ownership of the Value provided,
        and the Value will be deleted if the variable destructor is called.
    */
    Variable(std::string, Value*);
    

    // Destructor ///////////////////////
    
    /*! 
      \brief
        Destructor deletes the memory used for the value
    */
    virtual ~Variable();

        
    // Methods //////////////////////////
    
    /*! 
      \brief
        Generic template for a method to get the value as the derived type
      \return 
        A pointer to the value cast to the provided derived type
      \throw std::runtime_error 
        An error message if the value of the variable
        cannot be cast to the provided class
      \details
        The T_VALUE provided to this function template should be the 
        class of the derived type extending Value 
        (e.g., ValueVarmap or ValueDouble) for this variable. 
    */ 
    template <class T_VALUE>
    T_VALUE* getValue()
    {
      T_VALUE* valuePointer = dynamic_cast <T_VALUE*> (value_);
      if (valuePointer) {
        return valuePointer;
      } else {
        std::ostringstream error;
        error << "Type requested is not valid for the value in variable " 
              << name_;
        throw std::runtime_error(error.str());
      }
    }
    
    /*! 
      \brief
        Set the pointer to the containing holon
      \param Holon* 
        Pointer to the holon containing the variable.
      \return 
        No return value
    */
    void setHolon(Holon*);
    
    /*! 
      \brief
        Set the pointer to the value object for the variable
      \param Value* 
        Pointer to the value to be assigned to the variable
      \return 
        No return value
      \details
        Note that the Variable will take ownership of the Value provided,
        and the Value will be deleted if the variable destructor is called.
    */
    void setValue(Value*);
      
  protected:
    
    // Constructors /////////////////////
    
    /*! 
      \brief
        Constructor based on a provided name
      \param std::string 
        The name for the new variable object.
    */
    Variable(std::string);

};

#endif /* CHSM_VARIABLE_H_ */
