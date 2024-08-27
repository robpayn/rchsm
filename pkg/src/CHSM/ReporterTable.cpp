/*
 * ReporterTable.cpp
 */

#include "ReporterTable.h"
#include "Holon.h"
#include "values/RateDouble.h"
#include "values/ValueLong.h"

Column::Column(std::string name) :
  name_(name)
{}

ColumnDouble::ColumnDouble(std::string name, double& val) :
  Column(name),
  val_(val)
{}

void ColumnDouble::collect()
{
  col_.push_back(val_);
  length_++;
}

ColumnLong::ColumnLong(std::string name, long& val) :
  Column(name),
  val_(val)
{}

void ColumnLong::collect()
{
  col_.push_back(val_);
  length_++;
}

ReporterTable::ReporterTable(int interval, Variable& var) :
  ReporterInterval(interval, var)
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

void ReporterTable::trackRate(Variable& var, bool from, bool to)
{
  Value* val = dynamic_cast<RateDouble*>(var.value_);
  if(val) {
    RateDouble* rate = static_cast<RateDouble*>(var.value_);
    if(from) {
      std::string name = 
        var.holon_->name_ + std::string(".") + var.name_ + ".from";
      Column* col = new ColumnDouble(name, rate->vf_);
      colMap_[name] = col;
      columns_.push_back(col);
    }
    if(to) {
      std::string name = 
        var.holon_->name_ + std::string(".") + var.name_ + ".to";
      Column* col = new ColumnDouble(name, rate->v_);
      colMap_[name] = col;
      columns_.push_back(col);
    }
    return;
  }
}

void ReporterTable::trackVariable(Variable& var)
{
  
  Value* val = dynamic_cast<ValueDouble*>(var.value_);
  if(val) {
    std::string name = var.holon_->name_ + std::string(".") + var.name_;
    Column* col = new ColumnDouble(name, ((ValueDouble*)val)->v_);
    colMap_[name] = col;
    columns_.push_back(col);
    return;
  }
  
  val = dynamic_cast<ValueLong*>(var.value_);
  if(val) {
    std::string name = var.holon_->name_ + std::string(".") + var.name_;
    Column* col = new ColumnLong(name, ((ValueLong*)val)->v_);
    colMap_[name] = col;
    columns_.push_back(col);
    return;
  }
  
}
