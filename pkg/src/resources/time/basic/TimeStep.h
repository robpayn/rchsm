/*
 * TimeStep.h
 */

#ifndef RCHSM_TIMESTEP_BASIC_H_
#define RCHSM_TIMESTEP_BASIC_H_

#include "../../../CHSM/values/ValueDouble.h"

class TimeStep : public ValueDouble
{
  public:
    // Constructors/Destructor
    
    TimeStep();

    TimeStep(double);
    
};

#endif /* RCHSM_TIMESTEP_BASIC_H_ */
