/*
 * VariableVarmap.h
 */

#ifndef RCHSM_VALUEVARMAP_H_
#define RCHSM_VALUEVARMAP_H_

#include "Value.h"
#include <unordered_map>

class VarmapFormatter;

//! A value for a CHSM variable composed of other variables
class ValueVarmap : public Value
{
  public:
    // Attributes ///////////////////////
    
    //! The map of pointers to variables composing the value
    std::unordered_map<std::string, Variable*> map_;
    
    //! The formatter for translating the variable map to a string
    VarmapFormatter* formatter_;

    
    // Constructors /////////////////////

    //! Create a new instance with the provided variable
    //!   \param Variable* Pointer to the variable associated with the value
    ValueVarmap();
    
    
    // Destructor ///////////////////////

    virtual ~ValueVarmap() override;
    
    
    // Methods //////////////////////////
    
    //! Add a variable to the variable map
    //!   \param Variable* Pointer to variable to be added
    //! \return Nothing returned
    /*!
      Note that the variable map will assume ownership of the Variable at the 
      pointer provided.
      The Variable will be deleted when the deconstructor of the value is
      called.
    */
    void addVariable(Variable*);
    
    //! Set the value based on the string representation provided.
    //!   \param std::string The string to be converted to the value
    //! \return Nothing returned
    void fromString(std::string) override;
    
    //! Get a variable with the provided name
    //!   \param std::string Name of the variable to be retrieved.
    //! \return Pointer to the variable with the provided name.
    //!   Returns a null pointer if the variable name is not found.
    Variable* getVariable(std::string);
    
    //! Provide a string representation of the variable map
    //! \return A string representing the variable map
    std::string toString() override;
    
};

class VarmapFormatter
{
public:
  ValueVarmap* varmap_;
  
  VarmapFormatter(ValueVarmap*);
  virtual ~VarmapFormatter();
  
  virtual std::string format() = 0;
};

class VarmapFormatterXML : public VarmapFormatter
{
public:
  VarmapFormatterXML(ValueVarmap*);
  
  std::string format() override;
};

#endif /* RCHSM_VALUEVARMAP_H_ */
