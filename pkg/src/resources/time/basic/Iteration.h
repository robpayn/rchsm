/*
 * Iteration.h
 */

#ifndef RESOURCES_TIME_BASIC_ITERATION_H_
#define RESOURCES_TIME_BASIC_ITERATION_H_

#include "../../../CHSM/values/ValueLongMemory.h"

class Iteration : public ValueLongMemory
{
  public:
    // Constructors/Destructor
    
    Iteration(long, int);
    
    // Methods
    
    void setDependencies(DepManager&) override;
    
    void update() override;
};

#endif /* RESOURCES_TIME_BASIC_ITERATION_H_ */
