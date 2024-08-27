/**
 * ValueBoolean.cpp
 */

#ifndef CHSM_VALUES_VALUEBOOLEAN_H_
#define CHSM_VALUES_VALUEBOOLEAN_H_

#include "ValueBoolean.h"
#include "../Value.h"

/*!
 \brief
   A CHSM value quantified by a boolean (true/false) state
*/
class ValueBoolean : public Value
{
public:
  // Attributes
  
  /*!
    \brief
      The boolean (true/false) value
  */
  bool v_ = false;
  
  /*!
    \brief
      A boolean flag indicating if the value has been defined
  */
  bool isDefined_ = false;
  
  // Constructors
  
  /*!
    \brief
      Create a new instance of the boolean Value
  */
  ValueBoolean();
  
  /*!
    \brief
      Create a new instance of a boolean Value with the provided value
   
    \param bool
      Initial boolean value
  */
  ValueBoolean(bool);
  
  /*!
    \brief
      Create a new instance of a boolean Value with the provided string
      representation of the value
   
    \param std::string
      A string representation of the value
  */
  ValueBoolean(std::string);
  
  // Methods
  
  /*! 
    \brief
      Set the boolean value from a string representation
   
    \param std::string 
      The string representation of the boolean value.
   
    \return 
      No return value
  */
  void fromString(std::string valueString) override;
  
  /*! 
    \brief
      Query if the value is currently defined (as indicated by the flag)
   
    \return
      Boolean true if value is defined, false otherwise
  */
  bool isDefined() override;
  
  /*!
    \brief
      Set the value
   
    \param bool
      The new value for the ValueBoolean
   
    \return
      No return value
  */
  void setValue(bool);
  
  /*! 
    \brief
      Convert the boolean value to a string
   
    \return 
      A string representing the boolean value
  */
  std::string toString() override;
};

#endif /* CHSM_VALUES_VALUEBOOLEAN_H_ */
