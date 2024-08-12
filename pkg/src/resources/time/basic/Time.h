/*
 * Time.h
 */

#ifndef RESOURCES_TIME_BASIC_TIME_H_
#define RESOURCES_TIME_BASIC_TIME_H_

#include "../../../CHSM/values/ValueDouble.h"
#include "../../../CHSM/Dynamic.h"
#include "../../../CHSM/Cell.h"

class Time : public ValueDouble, public Dynamic
{
  public:
    // Attributes
    
    double* timeStep_;
    
    Dynamic* iteration_;
    
    Dynamic* timeValid_;
    
    // Constructors/Destructor
    
    Time(int);
    
    Time(int, double);
    
    // Methods
    
    void setDependencies(DepManager*) override;
    
    void update() override;
};

#endif /* RESOURCES_TIME_BASIC_TIME_H_ */
