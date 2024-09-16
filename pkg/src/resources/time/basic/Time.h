/*
 * Time.h
 */

#ifndef RESOURCES_TIME_BASIC_TIME_H_
#define RESOURCES_TIME_BASIC_TIME_H_

#include "../../../CHSM/values/ValueDouble.h"
#include "../../../CHSM/DynamicMemory.h"

class Time : public ValueDouble, public DynamicMemory
{
  public:
    // Attributes
    
    double* timeStep_;
    
    // Constructors/Destructor
    
    Time(double, int);
    
    // Methods
    
    void setDependencies(DepManager&) override;
    
    void update() override;
};

#endif /* RESOURCES_TIME_BASIC_TIME_H_ */
