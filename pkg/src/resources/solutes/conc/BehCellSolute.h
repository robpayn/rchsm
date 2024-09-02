/*
 * BehCellSolute.h
 */

#ifndef RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_H_
#define RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_H_

#include <string>
#include <memory>

class Matrix;
class Holon;
class MemoryDoubleFactory;

class BehCellSolute
{
  public:
    
    std::string soluteName_ = "";
    
    std::string stateSuffix_ = "Conc";
    
    std::string stateName_ = "";
    
    std::shared_ptr<MemoryDoubleFactory> mfDouble_ = nullptr;
    
    BehCellSolute(std::string, std::shared_ptr<MemoryDoubleFactory> = nullptr);
    
    // Methods
    
    void createVariables(Matrix*, Holon&, double);
    
    void setNames();
    
};

#endif /* RESOURCES_SOLUTES_CONC_BEHCELLSOLUTE_H_ */
