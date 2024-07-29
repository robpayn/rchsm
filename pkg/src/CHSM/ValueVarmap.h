/*
 * VariableVarmap.h
 */

#ifndef RCHSM_VALUEVARMAP_H_
#define RCHSM_VALUEVARMAP_H_

#include <string>
#include <unordered_map>
#include "Variable.h"
#include "Value.h"

class Formatter
{
  public:
    std::unordered_map<std::string, Variable*>* mapPtr_;
    
    Formatter(std::unordered_map<std::string, Variable*>* mapPtr);
    virtual ~Formatter();
    
    virtual std::string format() = 0;
};

class FormatterXML : public Formatter
{
  public:
    Variable* variable_;

    FormatterXML(std::unordered_map<std::string, Variable*>*, Variable*);
    virtual ~FormatterXML();
    
    std::string format() override;
};

class ValueVarmap : public Value
{
  public:
    // Attributes
    
    std::unordered_map<std::string, Variable*> map_;
    
    Formatter* formatter_;
    
    // Constructors/Destructor
    
    ValueVarmap(Variable*);
    
    virtual ~ValueVarmap();
    
    // Methods
    
    void fromString(std::string valueString) override;
    
    std::string toString() override;
    
    void addVariable(Variable* var);
    
    void deleteVariables();
};

#endif /* RCHSM_VALUEVARMAP_H_ */
