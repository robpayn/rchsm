/*
 * DepManager.h
 */

#ifndef CHSM_DEPMANAGER_H_
#define CHSM_DEPMANAGER_H_

#include "Value.h"
#include "Holon.h"
#include <string>
#include <sstream>
#include <list>
#include <vector>

class Dynamic;

class DepManager 
{
  public:
    
    int numPhases_;
    
    std::list<Dynamic*>* dynamics_;
    
    DepManager(int);
    
    virtual ~DepManager();
    
    virtual void addDynamic(Dynamic*);
    
    virtual void createDependency(Value*, Value*) = 0;
    
    virtual void manageDependencies();
    
    template<class T_VALUE>
    T_VALUE* setDependency(Value* depValue, Holon* holon, std::string varName)
    {
      Variable* neededVar = holon->getVariable(varName);
      if(!neededVar) {
        std::ostringstream error;
        error << "The needed variable could not be found" 
          << " in attempt to create dependency of"
          << " variable " << depValue->var_->name_ 
          << " in holon " << depValue->var_->holon_->name_
          << " on variable " << varName
          << " in holon " << holon->name_;
        throw std::runtime_error(error.str());
      }
      return setDependency<T_VALUE>(depValue, neededVar);
    }
    
    template<class T_VALUE>
    T_VALUE* setDependency(Value* depValue, Variable* neededVar)
    {
      T_VALUE* neededValue = dynamic_cast<T_VALUE*>(neededVar->value_);
      if (!neededValue) {
        std::ostringstream error;
        error << "Value type could not be cast to the value of the" 
          << " needed variable in attempt to create dependency of"
          << " variable " << depValue->var_->name_ 
          << " in holon " << depValue->var_->holon_->name_
          << " on variable " << neededVar->name_
          << " in holon " << neededVar->holon_->name_;
        throw std::runtime_error(error.str());
      }
      
      createDependency(depValue, neededVar->value_);
      
      return neededValue;
    }
    
    virtual unsigned int size(int);
    
    virtual std::vector<Dynamic*> sort(int) = 0;
    
};

#endif /* CHSM_DEPMANAGER_H_ */
