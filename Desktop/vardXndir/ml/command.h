#ifndef COMMAND_H
#define COMMAND_H

#include "variable.h"
#include <vector>
#include "boost/lexical_cast.hpp"
#include <cctype>

class Command
{
public:
	Command(const std::string commandName = "") : m_commandName(commandName)
	{}

	virtual void exec(std::string& argument, std::vector<Variable*>& vectorVariable ) = 0;
	const std::string getCommandName()
	{
		return m_commandName;
	}
protected:
	const std::string m_commandName;	
};
#endif
