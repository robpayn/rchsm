/*
 * Bound.h
 */

#ifndef RCHSM_BOUND_H_
#define RCHSM_BOUND_H_

#include "Holon.h"

class Cell;

class Bound : public Holon
{
  public:
    // Attributes
    
    Cell* cellFrom_;
    Cell* cellTo_;
    
    // Constructors/Destructor
    
    Bound(std::string);
    
    Bound(std::string, Cell*, Cell*);
    
};

#endif /* RCHSM_BOUND_H_ */
