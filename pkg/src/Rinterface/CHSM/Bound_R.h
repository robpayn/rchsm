/*!
  \file Bound_R.h
  \brief
    R interface functions for access to Bound CHSM objects
  \details
    See the "related symbols" documentation of the Bound class for a
    description of the R interface functions.
*/

#ifndef RINTERFACE_CHSM_BOUND_R_H_
#define RINTERFACE_CHSM_BOUND_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Bound.h"

void Bound_finalizer(SEXP);
  
extern "C"
{
  /*!
    \relatesalso Bound
    \brief
      R interface function for constructing a new Bound instance
   
    \param SEXP
      Name of the new bound object
    \param SEXP
      R logical value indicating if a finalizer should be registered.
      Value of TRUE registers a finalizer, FALSE does not.
   
    \return
      R external pointer to the new Bound object
  */
  SEXP Bound_constructor(SEXP, SEXP);
  
  /*!
    \relatesalso Bound
    \brief
      R interface function for destructing a bound object
   
    \param SEXP
      R external pointer to the bound object to be deconstructed
   
    \return
      R NULL value is returned
  */
  SEXP Bound_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_BOUND_R_H_ */
