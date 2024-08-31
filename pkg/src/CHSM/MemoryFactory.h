/*
 * MemoryFactory.h
 */

#ifndef CHSM_MEMORYFACTORY_H_
#define CHSM_MEMORYFACTORY_H_

class Memory;
class Value;

/*!
  \brief
    A factory for creating memory objects
 */
class MemoryFactory
{
  public:
    
    /*!
      \brief
        Create a new instance of a factory for creating memory objects with
          the provided capacity
     
      \param int
        Number of elements the created memory should have
    */
    MemoryFactory(int);
    
    virtual ~MemoryFactory(); 
    
    /*!
      \brief
        Create a memory object
     
      \param Value*
        Pointer to the value for which the memory will be provided
     
      \return
        Pointer to the new memory object
    */
    virtual Memory* createMemory(Value*) = 0;
    
};

#endif /* CHSM_MEMORYFACTORY_H_ */
