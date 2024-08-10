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
    // Attributes
    
    bool* timeValid_ = nullptr;
    
    // Constructors/Destructor
    
    Machine(std::string);
    
    virtual ~Machine();
    
    // Methods
    
    void init();
    
    void installVariable(Variable*, Holon*);
    
    Bound* createBound(std::string, Cell*, Cell*, Holon*);
    
    Cell* createCell(std::string, Holon*);
    
    Variable* createVariable(std::string, Value*, Holon*);
    
    void run();
    
};

#endif /* CHSM_MACHINE_H_ */
