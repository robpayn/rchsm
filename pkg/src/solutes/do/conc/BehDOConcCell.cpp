/*
 * BehDOConcCell.cpp
 */

#include "BehDOConcCell.h"
#include "DOConcCell.h"
#include <string>
#include <iostream>

BehDOConcCell::BehDOConcCell() {};

void BehDOConcCell::createVariables(Holon* holon) {
  Variable* variable = new DOConcCell("DOConc");
  holon->addVariable(variable);
}
