/*
 * Cell.h
 */

#ifndef RCHSM_CELL_H_
#define RCHSM_CELL_H_

#include "Holon.h"
#include <string>
#include <unordered_map>

class Bound;

class Cell : virtual public Holon
{
  public:
    // Attributes
    
    std::unordered_map<std::string, Bound*> bounds_;
    
    // Constructors
    
    Cell(std::string);
    
    // Destructor
    
    virtual ~Cell();
    
    // Methods
    
    void addBound(Bound* bound);
    
};

#endif /* RCHSM_CELL_H_ */
