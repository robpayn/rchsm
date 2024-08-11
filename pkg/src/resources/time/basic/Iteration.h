/*
 * Iteration.h
 */

#ifndef RCHSM_ITERATION_BASIC_H_
#define RCHSM_ITERATION_BASIC_H_

#include "../../../CHSM/values/ValueLong.h"
#include "../../../CHSM/Dynamic.h"

class Iteration : public ValueLong, public Dynamic
{
  public:
    // Constructors/Destructor
    
    Iteration(int);
    
    Iteration(int, long);
    
    // Methods
    
    void setDependencies() override;
    
    void update() override;
};

#endif /* RCHSM_ITERATION_BASIC_H_ */
