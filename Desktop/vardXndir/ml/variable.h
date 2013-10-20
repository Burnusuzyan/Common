#ifndef VAR_H
#define VAR_H

#include <string>

class Variable
{	
public:
	Variable(std::string variableName = "", std::string variableValue = "");

	void setVariable(std::string variableName = "", std::string variableValue = "", std::string variableType = "");
	void setVariableName(std::string variableName);
	void setVariableValue(std::string variableValue);
	void setVariableType(std::string variableType);

	std::string getVariableName();
	std::string getVariableValue();
	std::string getVariableType();
private:
	std::string m_variableName;
	std::string m_variableValue;
	std::string m_variableType;
};
 	

#endif
