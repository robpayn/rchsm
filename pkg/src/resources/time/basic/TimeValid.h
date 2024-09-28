/*
 * TimeValid.h
 */

#ifndef RESOURCES_TIME_BASIC_TIMEVALID_H_
#define RESOURCES_TIME_BASIC_TIMEVALID_H_

#include "../../../CHSM/Updater.h"
#include "../../../CHSM/values/ValueBoolean.h"
#include "../../../CHSM/DynamicMemory.h"

class TimeValid : public ValueBoolean, public DynamicMemory
{
  public:
    
    TimeValid(bool, int);
};

class TimeValidUpdater : public Updater
{
  public:
    
    bool* v_ = nullptr;
    
    double* time_ = nullptr;
    
    double* timeMax_ = nullptr;
    
    TimeValidUpdater(int);
    
    void setDependencies(DepManager&) override;
    
    void update() override;
    
};

#endif /* RESOURCES_TIME_BASIC_TIMEVALID_H_ */
