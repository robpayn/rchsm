/*
 * DepManInstallOrder.h
 */

#ifndef CHSM_DEPMANINSTALLORDER_H_
#define CHSM_DEPMANINSTALLORDER_H_

#include "DepManager.h"

/*!
  \brief
    A dependency manager based on installation order of variables
*/
class DepManInstallOrder : public DepManager
{
  public:
    
    /*!
      \brief
        Create a new instance of the dependency manager with the given
        number of phases
     
      \param int
        Number of phases for the solution strategy
    */
    DepManInstallOrder(int);
    
    /*!
      \brief
        Create a dependency between dynamic values
      \detail
        This dependency manager does not gather dependency information
        because the order of updates is determined by the installation order
        of variables
     
      \param Value*
        The dependent value
      \param Value*
        The value needed by the dependent value
     
      \return
        No return value
    */
    void createDependency(Value*, Value*) override;
    
    /*!
      \brief
        Sort the dynamic values according to the installation order of 
        variables for a given phase
     
      \param int
        The phase that should be sorted
     
      \return
        Vector of sorted dynamic values for the given phase
     */
    std::vector<Updater*> sort(int phase) override;
    
};

#endif /* CHSM_DEPMANINSTALLORDER_H_ */
