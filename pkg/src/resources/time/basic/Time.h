/*
 * Time.h
 */

#ifndef RESOURCES_TIME_BASIC_TIME_H_
#define RESOURCES_TIME_BASIC_TIME_H_

#include "../../../CHSM/Updater.h"
#include "../../../CHSM/values/ValueDouble.h"
#include "../../../CHSM/DynamicMemory.h"

class DepManager;

class Time : public ValueDouble, public DynamicMemory
{
  public:
    
    Time(double, int);
    
};

class TimeUpdater : public Updater
{
  public:
    
    double* v_ = nullptr;
    
    double* timeStep_;
    
    TimeUpdater(int);
    
    void setDependencies(DepManager&) override;
    
    void update() override;
    
};

#endif /* RESOURCES_TIME_BASIC_TIME_H_ */
