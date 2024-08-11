/*
 * DepManager.h
 */

#ifndef CHSM_DEPMANAGER_H_
#define CHSM_DEPMANAGER_H_

#include <list>

class Dynamic;

class DepManager 
{
  public:
    
    int phase_;
    
    std::list<Dynamic*>* dynamics_;
    
    DepManager(int);
    
    virtual ~DepManager();
    
    virtual void addDynamic(Dynamic*);
    
    virtual unsigned int size(int);
    
};

#endif /* CHSM_DEPMANAGER_H_ */
