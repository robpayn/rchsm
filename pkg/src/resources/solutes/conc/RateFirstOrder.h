/*
 * RateFirstOrder.h
 */

#ifndef RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_H_
#define RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_H_

#include "../../../CHSM/Updater.h"
#include "../../../CHSM/values/RateDouble.h"

class RateFirstOrder : public RateDouble
{
  public:
    
    RateFirstOrder(double, std::string, std::string, int);
    
};

class RateFirstOrderUpdater : public UpdaterDouble
{
  public:
    
    double* rateCoeff_ = nullptr;
    
    double* conc_ = nullptr;
    
    std::string coeffName_ = "";
    
    RateFirstOrderUpdater(std::string, int);

    void setDependencies(DepManager&) override;
    
    void update() override;
  
};

#endif /* RESOURCES_SOLUTES_CONC_RATEFIRSTORDER_H_ */
