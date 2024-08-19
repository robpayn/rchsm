/*
 * ReporterTable_R.cpp
 */

#include "ReporterTable_R.h"
#include "../../CHSM/ReporterTable.h"

#include <iostream>

void ReporterTable_finalizer(SEXP externalPointer) {
  
  ReporterTable* pointer = 
    static_cast <ReporterTable*> (R_ExternalPtrAddr(externalPointer));
  R_ClearExternalPtr(externalPointer);
  delete pointer;
  
}

SEXP ReporterTable_destructor(SEXP externalPointer)
{
  ReporterTable_finalizer(externalPointer);
  
  return R_NilValue;
}

SEXP ReporterTable_constructor(SEXP interval, SEXP regFinalizer)
{
  
  ReporterTable* pointer = new ReporterTable(asInteger(interval));
  
  SEXP externalPointer = PROTECT(
    R_MakeExternalPtr(pointer, R_NilValue, R_NilValue)
  );
  
  if(asLogical(regFinalizer)) {
    R_RegisterCFinalizer(externalPointer, ReporterTable_finalizer);
  }
  
  UNPROTECT(1);
  
  return externalPointer;
  
}

SEXP ReporterTable_getDataFrame(SEXP extRepPtr)
{
  ReporterTable* repPtr = 
    static_cast<ReporterTable*>(R_ExternalPtrAddr(extRepPtr));
  
  int numCols = repPtr->columns_.size();
  
  SEXP df = PROTECT(allocVector(VECSXP, numCols));
  SEXP dfNames = PROTECT(allocVector(VECSXP, numCols));
  
  int colIndex = 0;
  int row = 0;
  for(Column* col : repPtr->columns_) {
    Column* colt = dynamic_cast<ColumnDouble*>(col);
    if(colt) {
      SEXP vector = PROTECT(
        allocVector(REALSXP, colt->length_)
      );
      row = 0;
      for(double v : ((ColumnDouble*)colt)->col_) {
        REAL(vector)[row] = v;
        row++;
      }
      SET_VECTOR_ELT(df, colIndex, vector);
      SET_VECTOR_ELT(dfNames, colIndex, install(colt->name_.c_str()));
      colIndex++;
      continue;
    }
    colt = dynamic_cast<ColumnLong*>(col);
    if(colt) {
      SEXP vector = PROTECT(
        allocVector(INTSXP, colt->length_)
      );
      row = 0;
      for(long v : ((ColumnLong*)colt)->col_) {
        INTEGER(vector)[row] = v;
        row++;
      }
      SET_VECTOR_ELT(df, colIndex, vector);
      SET_VECTOR_ELT(dfNames, colIndex, install(colt->name_.c_str()));
      colIndex++;
      continue;
    }
  }
  
  setAttrib(df, install("names"), dfNames);
  
  SEXP rowNames = PROTECT(allocVector(INTSXP, row));
  for(int i = 0; i < row; i++) {
    INTEGER(rowNames)[i] = i + 1;
  }
  
  setAttrib(df, install("row.names"), rowNames);
  
  setAttrib(df, install("class"), mkString("data.frame"));
  
  UNPROTECT(colIndex + 3);

  return df;
}

SEXP ReporterTable_trackVariable(SEXP extRepPtr, SEXP extVarPtr)
{
  ReporterTable* repPtr = 
    static_cast<ReporterTable*>(R_ExternalPtrAddr(extRepPtr));
  Variable* varPtr = static_cast<Variable*>(R_ExternalPtrAddr(extVarPtr));
  
  repPtr->trackVariable(varPtr);
  
  return R_NilValue;
}