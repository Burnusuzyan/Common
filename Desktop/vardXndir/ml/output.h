#ifndef OUTPUT_H
#define OUTPUT_H

#include "command.h"
#include <iostream>

class CommandOutput : public Command
{
public:
	CommandOutput() : Command("output")
	{}
	void exec(std::string& argument, std::vector<Variable*>& vectorVariable );
};
#endif
