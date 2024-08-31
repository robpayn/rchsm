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
    
    Iteration(long, int, std::shared_ptr<MemoryFactory> = nullptr);
    
    // Methods
    
    void setDependencies(DepManager&) override;
    
    void update() override;
};

#endif /* RESOURCES_TIME_BASIC_ITERATION_H_ */
