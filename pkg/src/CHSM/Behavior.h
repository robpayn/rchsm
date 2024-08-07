/*
 * Behavior.h
 */

#ifndef CHSM_BEHAVIOR_H_
#define CHSM_BEHAVIOR_H_

class Holon;
class Machine;

class Behavior
{
  public:
    virtual ~Behavior() {};
    
    virtual void createVariables(Machine*, Holon*) = 0;
};

#endif /* CHSM_BEHAVIOR_H_ */
