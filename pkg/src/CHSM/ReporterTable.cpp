/*
 * ReporterTable.cpp
 */

#include "ReporterTable.h"
#include "Holon.h"
#include "values/ValueDouble.h"
#include "values/ValueLong.h"

Column::Column(std::string name) :
  name_(name)
{}

ColumnDouble::ColumnDouble(std::string name, ValueDouble* val) :
  Column(name),
  val_(&(val->v_))
{}

void ColumnDouble::collect()
{
  col_.push_back(*val_);
  length_++;
}

ColumnLong::ColumnLong(std::string name, ValueLong* val) :
  Column(name),
  val_(&(val->v_))
{}

void ColumnLong::collect()
{
  col_.push_back(*val_);
  length_++;
}

ReporterTable::ReporterTable(int interval) :
  ReporterInterval(interval)
{}

ReporterTable::~ReporterTable()
{
  for(Column* column : columns_) {
    delete column;
  }
}

void ReporterTable::close()
{}

void ReporterTable::collectData() 
{
  for(Column* column : columns_) {
    column->collect();
  }
}

void ReporterTable::open()
{}

void ReporterTable::saveData() 
{}

void ReporterTable::trackVariable(Variable* var)
{
  
  Value* val = dynamic_cast<ValueDouble*>(var->value_);
  if (val) {
    std::string name = var->holon_->name_ + std::string(".") + var->name_;
    Column* col = new ColumnDouble(name, (ValueDouble*)val);
    colMap_[name] = col;
    columns_.push_back(col);
    return;
  }
  
  val = dynamic_cast<ValueLong*>(var->value_);
  if (val) {
    std::string name = var->holon_->name_ + std::string(".") + var->name_;
    Column* col = new ColumnLong(name, (ValueLong*)val);
    colMap_[name] = col;
    columns_.push_back(col);
    return;
  }
  
}
