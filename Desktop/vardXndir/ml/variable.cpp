#include "variable.h"

Variable::Variable(std::string variableName, std::string variableValue )
{
	m_variableName = variableName;
	m_variableValue = variableValue;
}

void Variable::setVariable(std::string variableName, std::string variableValue, std::string variableType)
{
	m_variableName = variableName;
	m_variableValue = variableValue;
	m_variableType = variableType;
}

void Variable::setVariableName(std::string variableName)
{
	m_variableName = variableName;
}

void Variable::setVariableValue(std::string variableValue)
{
	m_variableValue = variableValue;
}

void Variable::setVariableType(std::string variableType)
{
	m_variableType = variableType;
}

std::string Variable::getVariableName()
{
	return m_variableName;
}

std::string Variable::getVariableType()
{
	return m_variableType;
}


std::string Variable::getVariableValue()
{
	return m_variableValue;
}

