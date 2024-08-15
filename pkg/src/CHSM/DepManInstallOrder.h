/*
 * DepManInstallOrder.h
 */

#ifndef CHSM_DEPMANINSTALLORDER_H_
#define CHSM_DEPMANINSTALLORDER_H_

#include "DepManager.h"

class DepManInstallOrder : public DepManager
{
  public:
    
    DepManInstallOrder(int);
    
    void createDependency(Value*, Value*) override;
    
    std::vector<Dynamic*> sort(int phase) override;
    
};

#endif /* CHSM_DEPMANINSTALLORDER_H_ */
