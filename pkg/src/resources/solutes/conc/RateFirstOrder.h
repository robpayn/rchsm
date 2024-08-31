/*
 * RateFirstOrder.h
 */

#ifndef RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_H_
#define RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_H_

#include "../../../CHSM/values/RateDouble.h"

class RateFirstOrder : public RateDouble
{
public:
  
  double* rateCoeff_ = nullptr;
  
  double* conc_ = nullptr;
  
  std::string coeffName_ = "";
  
  RateFirstOrder(
    double, 
    std::string, 
    std::string,
    int, 
    std::shared_ptr<MemoryFactory> = nullptr
  );
  
  void setDependencies(DepManager&) override;
  
  void update() override;
  
};

#endif /* RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_H_ */
