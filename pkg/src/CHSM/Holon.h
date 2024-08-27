/*
 * Holon.h
 */

#ifndef CHSM_HOLON_H_
#define CHSM_HOLON_H_

#include "Variable.h"

class ValueVarmap;

/*! 
  \brief 
    A CHSM Holon
  \details
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
    
    /*! 
      \brief 
        Constructor based on a provided name
     
      \param std::string 
        The name for the new holon object.
    */
    Holon(std::string);
    
    /*! 
      \brief
        Construct a new instance based on the name and value provided
     
      \param std::string 
        The name for the new holon object.
      \param ValueVarmap* 
        Pointer to the variable map value for this holon
    */
    Holon(std::string, ValueVarmap*);
    
    
    // Methods //////////////////////////
    
    /*! 
      \brief 
        Add a Variable to the holon
      \details
        Note that the holon will assume ownership of the Variable referenced
        by the pointer.
        The Variable will be deleted if the holon's destructor is called.
     
      \param Variable* 
        Pointer to the variable to be added
     
      \return 
        No return value
    */
    void addVariable(Variable*);
    
    /*! 
      \brief
        Get a variable with the provided name
     
      \param std::string 
        Name of the variable to retrieve.
     
      \return 
        Pointer to the variable with the provided name. 
        Returns a null pointer if the variable name is not found.
    */
    Variable* getVariable(std::string);
    
    /*!
      \brief
        Template for a method for getting the value of a variable in the
        holon cast to the value type provided
      \tparam T_VALUE
        Class of the value for the requested variable
     
      \param std::string
        The name of the variable for which the value is being requested
     
      \return
        The value of the variable requested cast to the value type provided
    */
    template<class T_VALUE>
    T_VALUE* getVarValue(std::string name)
    {
      Variable* variable = getVariable(name);
      if(variable) {
        return variable->getValue<T_VALUE>();
      } else {
        return nullptr;
      }
    }
    
};

#endif /* CHSM_HOLON_H_ */
