/*
 * Machine_R.h
 */

/*!
  \file Machine_R.h
  \brief
    R interface functions for access to Machine objects
  \details
    See the "related symbols" documentation of the Machine class for a
    description of the R interface functions.
*/

#ifndef CHSM_MACHINE_R_H_
#define CHSM_MACHINE_R_H_

#include <R.h>
#include <Rinternals.h>

void Machine_finalizer(SEXP externalPointer);
  
extern "C"
{
  /*!
    \relatesalso Machine
    \brief
      R interface function for creating a new machine object
    \param SEXP
      R character string with the name of the machine
    \return SEXP
      R external pointer to the new machine object
  */
  SEXP Machine_constructor(SEXP, SEXP, SEXP, SEXP);
  
  /*!
    \relatesalso Machine
    \brief
      R interface function for destructing a machine object
    \param SEXP
      R external pointer to the machine to be deconstructed
    \return
      R NULL value is returned
  */
  SEXP Machine_destructor(SEXP);
  
  /*!
    \relatesalso Machine
    \brief
      R interface function for creating a bound holon in a matrix
    \param SEXP
      An R external pointer to the Machine object
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
  SEXP Machine_createBound(SEXP, SEXP, SEXP, SEXP, SEXP);
  
  /*!
    \relatesalso Machine
    \brief
      R interface function for creating a cell holon in a matrix
    \param SEXP
      An R external pointer to the Machine object
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
  SEXP Machine_createCell(SEXP, SEXP, SEXP);
  
  /*!
    \relatesalso Machine
    \brief
      Initialize the state machine
    \param SEXP
      R external pointer to the state machine.
    \return
      Returns a null value if successful.
      If an error occurs in initialization, the return value will
      be a character string with a explanation of the error starting with
      <CERROR>.
  */
  SEXP Machine_init(SEXP);
  
  SEXP Machine_installReporter(SEXP, SEXP);

  /*!
    \relatesalso Machine
    \brief
      Run the state machine
    \param SEXP
      R external pointer to the state machine.
    \return
      Returns a null value if successful.
      If an error occurs in running the machine, the return value will
      be a character string with a explanation of the error starting with
      <CERROR>.
  */
  SEXP Machine_run(SEXP);
}

#endif /* CHSM_MACHINE_R_H_ */
