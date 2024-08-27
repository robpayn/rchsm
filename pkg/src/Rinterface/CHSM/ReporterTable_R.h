/*!
  \file ReporterTable_R.h
  \brief
    R interface functions for access to a tabular reporter CHSM object
  \details
    See the "related symbols" documentation of the ReporterTable class for a
    description of the R interface functions.
*/

#ifndef RINTERFACE_CHSM_REPORTERTABLE_R_H_
#define RINTERFACE_CHSM_REPORTERTABLE_R_H_

#include <R.h>
#include <Rinternals.h>

void ReporterTable_finalizer(SEXP);

extern "C"
{
  /*!
    \relatesalso ReporterTable
    \brief
      R interface function for constructing a new reporter instance
   
    \param SEXP
      The iteration interval determining when the reporter is active
    \param SEXP
      R logical value indicating if a finalizer should be registered.
      Value of TRUE registers a finalizer, FALSE does not.
   
    \return
      R external pointer to the new reporter object
  */
  SEXP ReporterTable_constructor(SEXP, SEXP, SEXP);
  
  /*!
    \relatesalso ReporterTable
    \brief
      R interface function for destructing a reporter object
   
    \param SEXP
      R external pointer to the reporter object to be deconstructed
   
    \return
      R NULL value is returned
   */
  SEXP ReporterTable_destructor(SEXP);
  
  /*!
   \relatesalso ReporterTable
   \brief
      Get the table of collected data as a data frame
   
    \param SEXP
      External pointer to the reporter object
   
    \return
      The table of collected data as an R data frame
  */
  SEXP ReporterTable_getDataFrame(SEXP);
  
  /*!
    \relatesalso ReporterTable
    \brief
      Add a rate variable to track
   
    \param SEXP
      External pointer to the reporter object
    \param SEXP
      External pointer to the rate variable to be tracked
    \param SEXP
      R logical specifying if the value on the from side should be tracked
    \param SEXP
      R logical specifying if the value on the to side should be tracked
   
    \return
      Returns an R NULL value
  */
  SEXP ReporterTable_trackRate(SEXP, SEXP, SEXP, SEXP);
  
  /*!
    \relatesalso ReporterTable
    \brief
      Add a variable to track
   
    \param SEXP
      External pointer to the reporter object
    \param SEXP
      External pointer to the variable to be tracked
   
    \return
      Returns an R NULL value
  */
  SEXP ReporterTable_trackVariable(SEXP, SEXP);
}

#endif /* RINTERFACE_CHSM_REPORTERTABLE_R_H_ */