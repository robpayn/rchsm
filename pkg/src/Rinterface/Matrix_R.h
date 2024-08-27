/*!
 \file Matrix_R.h
 \brief
 R interface functions for access to CHSM Matrix objects
 \details
 See the "related symbols" documentation of the Matrix class for a
 description of the R interface functions.
 */

#ifndef RINTERFACE_MATRIX_R_H_
#define RINTERFACE_MATRIX_R_H_

#include <R.h>
#include <Rinternals.h>

void Matrix_finalizer(SEXP);

extern "C"
{
  /*!
    \relatesalso Matrix
    \brief
      R interface function for creating a new matrix object
   
    \param SEXP
      External pointer to the dependency manager
    \param SEXP
      R logical value indicating if a finalizer should be registered.
      Value of TRUE registers a finalizer, FALSE does not.
   
    \return SEXP
      R external pointer to the new machine object
  */
  SEXP Matrix_constructor(SEXP, SEXP);
  
  /*!
    \relatesalso Matrix
    \brief
      R interface function for deconstructing a matrix object
   
    \param SEXP
      R external pointer to the matrix to be deconstructed
   
    \return
      R NULL value is returned
  */
  SEXP Matrix_destructor(SEXP);

  /*!
    \relatesalso Matrix
    \brief
      R interface function for creating a bound holon in a matrix
   
    \param SEXP
      An R external pointer to the Matrix object
    \param SEXP
      An R character string with the name of the bound
    \param SEXP
      An R external pointer to the "from" cell
    \param SEXP
      An R external pointer to the "to" cell
    \param SEXP
      An R external pointer to the holon to which the bound should be added.
      Providing an R NULL value will result in the bound being installed
      in the Machine holon.
   
    \return
      An R external pointer to the Bound that was created.
      If an error occurs in creation of the bound, the return value will
      be a character string with a explanation of the error starting with
      <CERROR>.
  */
  SEXP Matrix_createBound(SEXP, SEXP, SEXP, SEXP, SEXP);
  
  /*!
    \relatesalso Matrix
    \brief
      R interface function for creating a cell holon in a matrix
   
    \param SEXP
      An R external pointer to the Matrix object
    \param SEXP
      An R character string with the name of the cell
    \param SEXP
      An R external pointer to the holon to which the bound should be added.
      Providing an R NULL value will result in the bound being installed
      in the Machine holon.
   
    \return
      An R external pointer to the Cell that was created.
      If an error occurs in creation of the bound, the return value will
      be a character string with a explanation of the error starting with
      <CERROR>.
  */
  SEXP Matrix_createCell(SEXP, SEXP, SEXP);
  
  /*!
    \relatealso Matrix
    \brief
      R interface function for creating a variable in the matrix
   
    \param SEXP
      An R external pointer to the Matrix object
    \param SEXP
      R character string with the name of the variable
    \param SEXP
      External pointer to the value of the variable
    \param SEXP
      External pointer to the holon in which the variable should be created
   
    \return
      External pointer to the variable that was created
  */
  SEXP Matrix_createVariable(SEXP, SEXP, SEXP, SEXP);
  
  /*!
    \brief
      R interface function for installing a solver in a matrix
   
    \param SEXP
      External pointer to the matrix in which the solver should be installed
    \param SEXP
      External pointer to the solver to be installed in the matrix
   
    \return
      R NULL value
  */
  SEXP Matrix_installSolver(SEXP, SEXP);
  
}

#endif /* RINTERFACE_MATRIX_R_H_ */
