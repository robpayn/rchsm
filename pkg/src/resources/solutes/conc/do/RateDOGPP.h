/*
 * RateDOGPP.h
 */

#ifndef RESOURCES_SOLUTES_DO_CONC_RATEDOGPP_H_
#define RESOURCES_SOLUTES_DO_CONC_RATEDOGPP_H_

#include "../../../../CHSM/values/RateDouble.h"

class RateDOGPP : public RateDouble
{
  public:
    
    RateDOGPP(
      double, 
      std::string, 
      int, 
      std::shared_ptr<MemoryFactory> = nullptr
    );
    
    void setDependencies(DepManager&) override;
    
    void update() override;
    
};

#endif /* RESOURCES_SOLUTES_DO_CONC_RATEDOGPP_H_ */
