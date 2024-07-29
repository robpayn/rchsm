/*
 * Holon.h
 */

#ifndef RCHSM_HOLON_H_
#define RCHSM_HOLON_H_

#include "Variable.h"
#include "ValueVarmap.h"

class Holon : virtual public Variable
{
public:
  // Constructors
  
  Holon(std::string name);
  
  // Destructor
  
  virtual ~Holon();
  
  // Methods
  
  void addVariable(Variable* var);
};

#endif /* RCHSM_HOLON_H_ */
