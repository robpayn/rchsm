/*
 * StateDOConc.h
 */

#ifndef RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_
#define RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_

#include "../../../CHSM/Variable.h"
#include "../../../CHSM/Dynamic.h"
#include "../../../CHSM/ValueDouble.h"
#include <string>

class StateDOConc : virtual public Variable, virtual public Dynamic
{
  public:
    // Constructors/Destructor
    
    StateDOConc(std::string name);
    
    // Methods
    
    void setDependencies() override;
    
    void update() override;
};

#endif /* RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_ */
