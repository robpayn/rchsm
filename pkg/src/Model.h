/*
 * Model.h
 */

#ifndef RCHSM_MODEL_H_
#define RCHSM_MODEL_H_

#include <string>
#include "CHSM/Holon.h"
#include "CHSM/Dynamic.h"
#include "CHSM/Cell.h"
#include "CHSM/Bound.h"

class Model : public Holon, Dynamic
{
  public:
    // Constructors/Destructor
    
    Model(std::string name);
    
    virtual ~Model();
    
    // Methods
    
    Cell* createCell (std::string name, Holon* holon);

    Bound* createBound (
      std::string name, 
      Cell* cellFrom, 
      Cell* cellTo, 
      Holon* holon
    );
    
    void setDependencies() override;
    
    void update() override;
    
};

#endif /* RCHSM_MODEL_H_ */
