/*
 * RateAdvection.h
 */

#ifndef RESOURCES_SOLUTES_CONC_RATEADVECTION_H_
#define RESOURCES_SOLUTES_CONC_RATEADVECTION_H_

#include "../../../CHSM/values/RateDouble.h"

class RateAdvection : public RateDouble
{
  public:
    
    double* velocity_ = nullptr;
    
    double* length_ = nullptr;
    
    double* concFrom_ = nullptr;
    
    double* concTo_ = nullptr;
    
    std::string velocityName_ = "";
    
    RateAdvection(
      double, 
      std::string, 
      std::string,
      int
    );

    void setDependencies(DepManager&) override;
    
    void update() override;
};

#endif /* RESOURCES_SOLUTES_CONC_RATEADVECTION_H_ */
