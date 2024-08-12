/*
 * StateDOConc.h
 */

#ifndef RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_
#define RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_

#include "../../../../CHSM/values/StateDouble.h"
#include <string>

class StateDOConc : public StateDouble
{
public:
  
  // Constructors/Destructor
  
  StateDOConc(int);
  
  StateDOConc(int, double);
  
};

#endif /* RCHSM_SOLUTES_DO_CONC_STATEDOCONC_H_ */
