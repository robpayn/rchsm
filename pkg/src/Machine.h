/*
 * Machine.h
 */

#ifndef CHSM_MACHINE_H_
#define CHSM_MACHINE_H_

#include "CHSM/Holon.h"

class Matrix;
class Cell;
class Bound;

class Machine : public Holon
{
  public:
    
    // Constructors/Destructor
    
    Machine(std::string);
    
    virtual ~Machine();
    
    void installVariable(Variable*, Holon*);
    
    Bound* createBound (std::string, Cell*, Cell*, Holon*);
    
    Cell* createCell (std::string, Holon*);
    
};

#endif /* CHSM_MACHINE_H_ */
