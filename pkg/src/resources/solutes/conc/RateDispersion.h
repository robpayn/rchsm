/*
 * RateDispersion.h
 */

#ifndef RESOURCES_SOLUTES_CONC_RATEDISPERSION_H_
#define RESOURCES_SOLUTES_CONC_RATEDISPERSION_H_

#include "../../../CHSM/Updater.h"
#include "../../../CHSM/values/RateDouble.h"

class RateDispersion : public RateDouble
{
  public:
    
    RateDispersion(double, std::string, std::string, int);

};

class RateDispersionUpdater : public Updater
{
  public:
    
    double* v_ = nullptr;
    
    double* vf_ = nullptr;
    
    double* dispCoeff_ = nullptr;
    
    double* length_ = nullptr;
    
    double* concFrom_ = nullptr;
    
    double* concTo_ = nullptr;
    
    std::string coeffName_ = "";
  
    RateDispersionUpdater(std::string, int);
    
    void setDependencies(DepManager&) override;
    
    void update() override;
  
};

#endif /* RESOURCES_SOLUTES_CONC_RATEDISPERSION_H_ */
