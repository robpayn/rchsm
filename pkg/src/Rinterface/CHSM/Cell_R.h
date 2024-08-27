/*!
  \file Cell_R.h
  \brief
    R interface functions for access to Cell CHSM objects
  \details
    See the "related symbols" documentation of the Cell class for a
    description of the R interface functions.
*/

#ifndef RINTERFACE_CHSM_CELL_R_H_
#define RINTERFACE_CHSM_CELL_R_H_

#include <R.h>
#include <Rinternals.h>
#include "../../CHSM/Cell.h"

void Cell_finalizer(SEXP);

extern "C"
{
  /*!
    \relatesalso Cell
    \brief
      R interface function for constructing a new Bound instance
   
    \param SEXP
      Name of the new cell object
    \param SEXP
      R logical value indicating if a finalizer should be registered.
      Value of TRUE registers a finalizer, FALSE does not.
   
    \return
      R external pointer to the new Cell object
  */
  SEXP Cell_constructor(SEXP, SEXP);
  
  /*!
    \relatesalso Cell
    \brief
      R interface function for destructing a cell object
   
    \param SEXP
      R external pointer to the cell object to be deconstructed
   
    \return
      R NULL value is returned
  */
  SEXP Cell_destructor(SEXP);
}

#endif /* RINTERFACE_CHSM_CELL_R_H_ */
