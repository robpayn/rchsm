/*
 * RateDOGPP.h
 */

#ifndef RESOURCES_SOLUTES_DO_CONC_RATEDOGPP_H_
#define RESOURCES_SOLUTES_DO_CONC_RATEDOGPP_H_

#include "../../../../CHSM/values/RateDouble.h"

class RateDOGPP : public RateDouble
{
  public:
    
    RateDOGPP(int, std::string);
    
    RateDOGPP(int, double, std::string);
    
    void setDependencies(DepManager&) override;
    
    void update() override;
    
};

#endif /* RESOURCES_SOLUTES_DO_CONC_RATEDOGPP_H_ */
