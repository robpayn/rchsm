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
  
    double& val_;
    
    std::list<double> col_;
    
    ColumnDouble(std::string, double&);
    
    void collect() override;
  
};

class ColumnLong : public Column
{
  public:
    
    long& val_;
    
    std::list<long> col_;
    
    ColumnLong(std::string, long&);
    
    void collect() override;
    
};

/*!
  \brief
    A tabular reporter operating on a set interval of iterations
*/
class ReporterTable : public ReporterInterval
{
  public:
    
    /*!
      \brief
        A map of columns in the table
    */
    std::map<std::string, Column*> colMap_;
    
    /*!
      \brief
        A list of columns in the table
    */
    std::list<Column*> columns_;
    
    /*!
      \brief
        Construct a new instance of the reporter operating at the provided
        interval
     
      \param int
        The interval of iterations at which the reporter should operate
    */
    ReporterTable(int, Variable&);
    
    virtual ~ReporterTable();
    
    /*!
      \brief
        Close the reporter's memory. Memory does not require closing for
        this reporter.
     
      \return
        No return value
    */
    virtual void close() override;
    
    /*!
      \brief
        Collect data from the CHSM model by adding to a list of values for each
        column.
     
      \return
        No return value
    */
    virtual void collectData() override;
    
    /*!
      \brief
        Open the reporter's memory. Memory does not need to be opened for this
        reporter.
     
      \return
        No return value
    */
    virtual void open() override;
    
    /*!
      \brief
        Save the collected data. Data is already saved by collector for this
        reporter.
     
      \return
        No return value
     */
    virtual void saveData() override;
    
    /*!
      \brief
        Track the value of a rate variable
      
      \param Variable&
        Reference to the rate variable for which the value(s) should be tracked
      \param bool
        Boolean value to determine if value on from side should be tracked.
      \param bool
        Boolean value to determine if value on to side should be tracked.
     
      \return
        No return value
    */
    virtual void trackRate(Variable&, bool, bool);
    
    /*!
      \brief
        Track the value of a variable
     
      \param Variable&
        Reference to the variable for which the value should be tracked
     
      \return
        No return value
    */
    virtual void trackVariable(Variable&);
    
};