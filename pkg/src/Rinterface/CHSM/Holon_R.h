/*!
  \file Holon_R.h
  \brief
    R interface functions for access to Holon CHSM objects
  \details
    See the "related symbols" documentation of the Holon class for a
    description of the R interface functions.
 */

#ifndef RINTERFACE_CHSM_HOLON_R_H_
#define RINTERFACE_CHSM_HOLON_R_H_

#include <R.h>
#include <Rinternals.h>

extern "C"
{
  /*!
    \relatesalso Holon
    \brief
      R interface function for getting a variable from the holon
   
    \param SEXP
      External pointer to holon from which the variable should be retrieved
    \param SEXP
      Name of the variable to retrieve
   
    \return
      R external pointer to the retrieved variable.
      Returns an R null value if the variable is not found.
   */
  SEXP Holon_getVariable(SEXP, SEXP);
}

#endif /* RINTERFACE_CHSM_HOLON_R_H_ */
