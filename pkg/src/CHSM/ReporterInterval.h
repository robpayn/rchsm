/*
 * ReporterInterval.h
 */

#include "Reporter.h"
#include <string>

class ReporterInterval : Reporter
{
  public:
    
    int interval_;
    
    long* iteration_;
    
    std::string cellTimeName_ = "CellTime";
    
    std::string varNameIter_ = "Iteration";
    
    ReporterInterval(int);
    
    virtual void init(Matrix*) override;
    
    virtual bool isActive() override;

};