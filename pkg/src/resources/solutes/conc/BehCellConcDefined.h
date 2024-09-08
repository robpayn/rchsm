/*
 * BehCellConcDefined.h
 */

#ifndef RESOURCES_SOLUTES_CONC_BEHCELLCONCDEFINED_H_
#define RESOURCES_SOLUTES_CONC_BEHCELLCONCDEFINED_H_

#include <string>
#include <vector>

class Matrix;
class Holon;
class MemoryDoubleFactory;

class BehCellConcDefined
{
  public:
    
    std::string soluteName_ = "";
    
    std::string stateSuffix_ = "Conc";
    
    std::string stateName_ = "";
    
    BehCellConcDefined(
      std::string
    );
    
    // Methods
    
    void createVariables(
        Matrix*, 
        Holon&,
        Holon&,
        std::string,
        std::string,
        std::vector<double>, 
        MemoryDoubleFactory* = nullptr
    );
    
    void setNames();
    
};

#endif /* RESOURCES_SOLUTES_CONC_BEHCELLCONCDEFINED_H_ */
