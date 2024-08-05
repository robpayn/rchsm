/*
 * Model.h
 */

#ifndef RCHSM_MODEL_H_
#define RCHSM_MODEL_H_

#include "CHSM/Holon.h"
#include "resources/time/basic/BehCellTime.h"
#include "resources/time/basic/BehBoundTime.h"

class Matrix;

class Cell;

class Bound;

class Model : public Holon
{
  public:
    BehCellTime behCellTime_;
    BehBoundTime behBoundTime_;
    
    // Constructors/Destructor
    
    Model(std::string, Matrix*);
    
    virtual ~Model();
    
    Cell* createCell (std::string, Holon*);
    
    Bound* createBound (
        std::string name, 
        Cell* cellFrom, 
        Cell* cellTo, 
        Holon* holon
    );
};

#endif /* RCHSM_MODEL_H_ */
