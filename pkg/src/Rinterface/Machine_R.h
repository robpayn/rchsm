/*!
  \file Machine_R.h
  \brief
    R interface functions for access to CHSM Machine objects
  \details
    See the "related symbols" documentation of the Machine class for a
    description of the R interface functions.
*/

#ifndef RINTERFACE_MACHINE_R_H_
#define RINTERFACE_MACHINE_R_H_

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
    \param SEXP
      External pointer to the matrix value for the machine
    \param SEXP
      R logical value indicating if a finalizer should be registered.
      Value of TRUE registers a finalizer, FALSE does not.
   
    \return SEXP
      R external pointer to the new machine object, if construction is 
        successful. 
      If a fatal error occurs in executing the C function, the return value will
        be a character string with an explanation of the error starting with
        <CERROR>.
  */
  SEXP Machine_constructor(SEXP, SEXP, SEXP);
  
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
      R interface function to install a reporter in the state machine.
   
    \param SEXP
      R external pointer to the state machine.
    \param SEXP
      R external pointer to the reporter to be installed.
   
    \return
      If an error occurs in executing the C function, the return value will
        be a character string with an explanation of the error starting with
        <CERROR>.
  */
  SEXP Machine_installReporter(SEXP, SEXP);

  /*!
    \relatesalso Machine
    \brief
      R interface function to run the state machine simulation
   
    \param SEXP
      R external pointer to the state machine to run
   
    \return
      Returns a null value if successful.
      If an error occurs in executing the C function, the return value will
        be a character string with an explanation of the error starting with
        <CERROR>.
  */
  SEXP Machine_run(SEXP);
  
  /*!
    \relatesalso Machine
    \brief
      R interface function to set the time valid variable that determines
        when to terminate a state machine simulation
   
    \param SEXP
      R external pointer to the state machine object
    \param SEXP
      R external pointer to the variable with the time valid value
   
    \return
      Returns a null value if successful.
      If an error occurs in executing the C function, the return value will
        be a character string with an explanation of the error starting with
        <CERROR>.
  */
  SEXP Machine_setTimeValidVariable(SEXP, SEXP);
  
}

#endif /* RINTERFACE_MACHINE_R_H_ */
