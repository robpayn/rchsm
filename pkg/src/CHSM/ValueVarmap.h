/*
 * VariableVarmap.h
 */

#ifndef RCHSM_VALUEVARMAP_H_
#define RCHSM_VALUEVARMAP_H_

#include <string>
#include <unordered_map>
#include "Variable.h"
#include "Value.h"

class ValueVarmap : virtual public Value
{
  public:
    // Attributes
    
    std::unordered_map<std::string, Variable*> map_;
    
    // Constructors/Destructor
    
    ValueVarmap();
    
    virtual ~ValueVarmap();
    
    // Methods
    
    void fromString(std::string valueString) override;
    
    std::string toString() override;
    
    void addVariable(Variable* var);
};

#endif /* RCHSM_VALUEVARMAP_H_ */
