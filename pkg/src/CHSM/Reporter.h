/*
 * Reporter.h
 */

class Matrix;
class Holon;
class Variable;

class Reporter
{
  public:
    
    virtual ~Reporter() {};
    
    virtual void close() = 0;
    
    virtual void collectData() = 0;
    
    virtual void init(Matrix*) = 0;
    
    virtual bool isActive() = 0;
    
    virtual void open() = 0;
    
    virtual void saveData() = 0;

};