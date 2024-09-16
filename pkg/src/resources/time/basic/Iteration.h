/*
 * Iteration.h
 */

#ifndef RESOURCES_TIME_BASIC_ITERATION_H_
#define RESOURCES_TIME_BASIC_ITERATION_H_

#include "../../../CHSM/values/ValueLong.h"
#include "../../../CHSM/DynamicMemory.h"

class Iteration : public ValueLong, public DynamicMemory
{
  public:
    // Constructors/Destructor
    
    Iteration(long, int);
    
    // Methods
    
    void setDependencies(DepManager&) override;
    
    void update() override;
};

#endif /* RESOURCES_TIME_BASIC_ITERATION_H_ */
