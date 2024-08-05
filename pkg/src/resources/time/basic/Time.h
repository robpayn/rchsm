/*
 * Time.h
 */

#ifndef RCHSM_TIME_BASIC_H_
#define RCHSM_TIME_BASIC_H_

#include "../../../CHSM/ValueDouble.h"
#include "../../../CHSM/Dynamic.h"
#include "../../../CHSM/Cell.h"

class Time : public ValueDouble, public Dynamic
{
  public:
    // Attributes
    
    double* timeStep_;
    
    Dynamic* iteration_;
    
    // Constructors/Destructor
    
    Time();
    
    Time(double);
    
    // Methods
    
    void setDependencies() override;
    
    void update() override;
};

#endif /* RCHSM_TIME_BASIC_H_ */
