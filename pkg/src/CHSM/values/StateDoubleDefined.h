/*
 * StateDoubleDefined.h
 */

#ifndef RESOURCES_SOLUTES_CONC_STATEDOUBLEDEFINED_H_
#define RESOURCES_SOLUTES_CONC_STATEDOUBLEDEFINED_H_

#include "StateDouble.h"
#include <vector>

class StateDoubleDefined : public StateDouble
{
  public:
    
    StateDoubleDefined(
      Holon&, 
      std::string, 
      std::string, 
      std::vector<double>, 
      int
    );
    
};

class StateDoubleDefinedUpdater : public StateDoubleUpdater
{
  public:
    
    std::vector<double> values_;
    
    long length_;
    
    long* iter_ = nullptr;
    
    StateDoubleDefinedUpdater(
      Holon&, 
      std::string, 
      std::string, 
      std::vector<double>,
      int
    );
    
    void update() override;
  
};

#endif /* RESOURCES_SOLUTES_CONC_STATEDOUBLEDEFINED_H_ */
