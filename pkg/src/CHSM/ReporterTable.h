/*
 * ReporterTable.h
 */

#include "ReporterInterval.h"
#include <list>
#include <map>
#include <string>

class ValueDouble;
class ValueLong;

class Column
{
  public:
    
    std::string name_ = "";
    
    long length_ = 0;
    
    Column(std::string);
    
    virtual ~Column() {};
    
    virtual void collect() = 0;
    
};

class ColumnDouble : public Column
{
  public:
  
    double* val_ = nullptr;
    
    std::list<double> col_;
    
    ColumnDouble(std::string, ValueDouble*);
    
    void collect() override;
  
};

class ColumnLong : public Column
{
  public:
    
    long* val_ = nullptr;
    
    std::list<long> col_;
    
    ColumnLong(std::string, ValueLong*);
    
    void collect() override;
    
};

class ReporterTable : public ReporterInterval
{
  public:
    
    std::map<std::string, Column*> colMap_;
    
    std::list<Column*> columns_;
    
    ReporterTable(int);
    
    virtual ~ReporterTable();
    
    virtual void close() override;
    
    virtual void collectData() override;
    
    virtual void open() override;
    
    virtual void saveData() override;
    
    virtual void trackVariable(Variable*);
    
};