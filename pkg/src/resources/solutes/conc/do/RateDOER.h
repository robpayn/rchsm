/*
 * RateDOER.h
 */

#ifndef RESOURCES_SOLUTES_DO_CONC_RATEDOER_H_
#define RESOURCES_SOLUTES_DO_CONC_RATEDOER_H_

#include "../../../../CHSM/values/RateDouble.h"

class RateDOER : public RateDouble
{
  public:
    
    RateDOER(
      double, 
      std::string, 
      int
    );
    
    void setDependencies(DepManager&) override;
    
    void update() override;
    
};

#endif /* RESOURCES_SOLUTES_DO_CONC_RATEDOER_H_ */
