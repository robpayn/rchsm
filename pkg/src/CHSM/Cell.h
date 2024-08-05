/*
 * Cell.h
 */

#ifndef RCHSM_CELL_H_
#define RCHSM_CELL_H_

#include "Holon.h"
#include "Bound.h"
#include <string>
#include <unordered_map>

class Bound;

class Cell : public Holon
{
  public:
    // Attributes
    
    std::unordered_map<std::string, Bound*> bounds_;
    
    // Constructors
    
    Cell(std::string);
    
    // Methods
    
    void addBound(Bound*);
    
    std::unordered_map<std::string, Variable*> getBoundVariables(std::string);
    
};

#endif /* RCHSM_CELL_H_ */
