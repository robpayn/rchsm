/*
 * StateDOConc.h
 */

#ifndef RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_
#define RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_

#include "../../../../CHSM/Dynamic.h"
#include "../../../../CHSM/values/ValueDouble.h"
#include <string>

class StateDOConc : public ValueDouble, public Dynamic
{
public:
  // Constructors/Destructor
  
  StateDOConc(int);
  
  // Methods
  
  void setDependencies() override;
  
  void update() override;
};

#endif /* RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_ */
