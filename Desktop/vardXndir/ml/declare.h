#ifndef DECLARE_H
#define DECLARE_H

#include "command.h"
#include <iostream>

class CommandDeclare : public Command
{
public:
	CommandDeclare() : Command("declare")
	{}
	void exec(std::string& argument, std::vector<Variable*>& vectorVariable );
};
#endif
