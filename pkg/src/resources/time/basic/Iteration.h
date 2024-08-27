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
    
    Iteration(int);
    
    Iteration(int, long);
    
    // Methods
    
    void setDependencies(DepManager&) override;
    
    void update() override;
};

#endif /* RESOURCES_TIME_BASIC_ITERATION_H_ */
