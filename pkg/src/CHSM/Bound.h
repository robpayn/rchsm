/*
 * Bound.h
 */

#ifndef RCHSM_BOUND_H_
#define RCHSM_BOUND_H_

#include "Holon.h"

class Cell;

class Bound : virtual public Holon
{
  public:
    // Attributes
    
    Cell* cellFrom_;
    Cell* cellTo_;
    
    // Constructors/Destructor
    
    Bound(std::string name);
    
    Bound(std::string name, Cell* fromCell, Cell* toCell);
    
    virtual ~Bound();
    
};

#endif /* RCHSM_BOUND_H_ */
