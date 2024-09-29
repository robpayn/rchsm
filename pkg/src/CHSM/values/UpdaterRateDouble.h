/*
 * UpdaterRateDouble.h
 */

#ifndef CHSM_VALUES_UPDATERRATEDOUBLE_H_
#define CHSM_VALUES_UPDATERRATEDOUBLE_H_

#include "../Updater.h"

class UpdaterRateDouble : public Updater
{
  public:
    
    double* v_ = nullptr;
    
    double* vf_ = nullptr;
    
    UpdaterRateDouble(int);
    
    virtual void attachDynamicValue(Dynamic*) override;
  
};


#endif /* CHSM_VALUES_UPDATERRATEDOUBLE_H_ */
