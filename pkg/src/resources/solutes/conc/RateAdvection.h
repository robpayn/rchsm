/*
 * RateAdvection.h
 */

#ifndef RESOURCES_SOLUTES_CONC_RATEADVECTION_H_
#define RESOURCES_SOLUTES_CONC_RATEADVECTION_H_

#include "../../../CHSM/values/RateDouble.h"
#include "../../../CHSM/values/UpdaterRateDouble.h"

class RateAdvection : public RateDouble
{
  public:
    
    RateAdvection(double, std::string, std::string, int);
    
};

class RateAdvectionUpdater : public UpdaterRateDouble
{
  public:
    
    std::string velocityName_ = "";
    
    double* velocity_ = nullptr;
    
    double* length_ = nullptr;
    
    double* concFrom_ = nullptr;
    
    double* concTo_ = nullptr;
    
    RateAdvectionUpdater(std::string, int);
    
    void setDependencies(DepManager&) override;
    
    void update() override;
    
};

#endif /* RESOURCES_SOLUTES_CONC_RATEADVECTION_H_ */
