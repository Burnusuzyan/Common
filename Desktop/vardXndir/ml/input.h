#ifndef INPUT_H
#define INPUT_H

#include "command.h"
#include <iostream>

class CommandInput : public Command
{
public:
	CommandInput() : Command("input")
	{}
	void exec(std::string& argument, std::vector<Variable*>& vectorVariable );
};
#endif
