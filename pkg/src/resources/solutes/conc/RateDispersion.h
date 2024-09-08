/*
 * RateDispersion.h
 */

#ifndef RESOURCES_SOLUTES_CONC_RATEDISPERSION_H_
#define RESOURCES_SOLUTES_CONC_RATEDISPERSION_H_

#include "../../../CHSM/values/RateDouble.h"

class RateDispersion : public RateDouble
{
  public:
    
    double* dispCoeff_ = nullptr;
    
    double* length_ = nullptr;
    
    double* concFrom_ = nullptr;
    
    double* concTo_ = nullptr;
    
    std::string coeffName_ = "";
    
    RateDispersion(
      double, 
      std::string, 
      std::string,
      int
    );

    void setDependencies(DepManager&) override;
    
    void update() override;
};

#endif /* RESOURCES_SOLUTES_CONC_RATEDISPERSION_H_ */
