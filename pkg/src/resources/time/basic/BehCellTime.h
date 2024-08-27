/*
 * BehCellTime.h
 */

#ifndef RESOURCES_TIME_BASIC_BEHCELLTIME_H_
#define RESOURCES_TIME_BASIC_BEHCELLTIME_H_

class Matrix;
class Holon;

class BehCellTime
{
  public:
    // Constructors/Destructor
    
    BehCellTime();

    // Methods
    
    void createVariables(Matrix*, Holon&, double, long, bool);
};

#endif /* RESOURCES_TIME_BASIC_BEHCELLTIME_H_ */
