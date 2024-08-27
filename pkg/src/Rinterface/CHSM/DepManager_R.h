/*!
  \file DepManager_R.h
  \brief
    R interface functions for access to dependency manager CHSM objects
  \details
    See the "related symbols" documentation of dependency manager classes for a
    description of the R interface functions.
 */

#ifndef RINTERFACE_CHSM_DEPMANAGER_R_H_
#define RINTERFACE_CHSM_DEPMANAGER_R_H_

#include <R.h>
#include <Rinternals.h>

void DepManInstallOrder_finalizer(SEXP);

extern "C"
{
  /*!
    \relatesalso DepManInstallOrder
    \brief
      R interface function for constructing a new install order dependency
      manager
   
    \param SEXP
      Number of phases for the solution strategy
    \param SEXP
      R logical value indicating if a finalizer should be registered.
      Value of TRUE registers a finalizer, FALSE does not.
   
    \return
      R external pointer to the new dependency manager object
  */
  SEXP DepManInstallOrder_constructor(SEXP, SEXP);
  
  /*!
    \relatesalso DepManInstallOrder
    \brief
      R interface function for deconstructing the dependency manager object
   
    \param SEXP
      R external pointer to the dependency manager object to be deconstructed
   
    \return
      R NULL value is returned
  */
  SEXP DepManInstallOrder_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_DEPMANAGER_R_H_ */