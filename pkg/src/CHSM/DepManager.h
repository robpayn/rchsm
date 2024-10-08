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

/*!
  \brief
    A CHSM dependency manager for determining update order
*/
class DepManager 
{
  public:
    
    /*!
      \brief
        The number of update phases for the solution strategy
    */
    int numPhases_;
    
    /*!
      \brief
        List of dynamic values for which dependencies should be managed
    */
    std::list<Dynamic*>* dynamics_;
    
    /*!
      \brief
        Construct a new instance of dependency manager with the provided
        number of phases
     
      \param int
        The number of phases for the solution strategy
    */
    DepManager(int);
    
    virtual ~DepManager();
    
    /*!
      \brief
        Add a dynamic value for which dependencies should be managed
     
      \param Dynamic*
        Pointer to the dynamic value for which dependencies should be managed
     
      \return
        No return value
    */
    virtual void addDynamic(Dynamic*);
    
    /*!
      \brief
        Create a dependency between dynamic values
     
      \param Value*
        The dependent value
      \param Value*
        The value needed by the dependent value
     
      \return
        No return value
    */
    virtual void createDependency(Value*, Value*) = 0;
    
    /*!
      \brief
        Manage the dependencies of all the registered dynamic values
     
      \return
        No return value
    */
    virtual void manageDependencies();
    
    /*!
      \brief
        Template for a method that will return a value of a given type
        after setting a dependency
      \tparam T_VALUE
        Class representing the type of value to be returned
     
      \param Value*
        Pointer to the dependent value
      \param Holon*
        Pointer to the holon containing the needed value
      \param std::string
        Name of the variable with the needed value
     
      \return
        The value that is the target of the dependency cast to the template
        parameter type
    */
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
    
    /*!
      \brief
        Template for a method that will return a value of a given type
        after setting a dependency
      \tparam T_VALUE
        Class representing the type of value to be returned
     
      \param Value*
        Pointer to the dependent value
      \param Variable*
        Pointer to the variable with the needed value
     
      \return
        The value that is the target of the dependency cast to the template
        parameter type
     */
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
    
    /*!
      \brief
        Get the number of dynamic values in a given phase
     
      \param int
        The phase for which the size will be provided
     
      \return
        The number of dynamic values in the provided phase
    */
    virtual unsigned int size(int);
    
    /*!
      \brief
        Sort the dynamic values according to the dependencies for a given phase
      
      \param int
        The phase that should be sorted
     
      \return
        Vector of sorted dynamic values for the given phase
    */
    virtual std::vector<Dynamic*> sort(int) = 0;
    
};

#endif /* CHSM_DEPMANAGER_H_ */
