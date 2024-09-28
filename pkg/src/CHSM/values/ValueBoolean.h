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

  /*!
    \brief
      The boolean (true/false) value
  */
  bool v_ = false;
  
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
      Convert the boolean value to a string
   
    \return 
      A string representing the boolean value
  */
  std::string toString() override;
  
};

#endif /* CHSM_VALUES_VALUEBOOLEAN_H_ */
