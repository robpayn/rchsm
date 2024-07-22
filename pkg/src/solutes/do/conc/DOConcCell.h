/*
 * DOConcCell.h
 */

#include "../../../CHSM/Variable.h"
#include "../../../CHSM/Dynamic.h"
#include "../../../CHSM/ValueDouble.h"
#include <string>

class DOConcCell : virtual public Variable, virtual public Dynamic
{
  public:
    // Constructors/Destructor
    
    DOConcCell(std::string name);
    
    // Methods
    
    void update() override;
};