#include "input.h"


/*
CommandDeclare::CommandDeclare() : Command("declare")
{}
*/
void CommandInput::exec(std::string& argument, std::vector<Variable*>& vectorVariable )
{

	argument = argument.substr(argument.find_first_not_of(" "), argument.find_last_not_of(" ") + 1);
	
	std::string value;
	std::cin >> value;
	bool findVariable = false;
	for(int i = 0; i < vectorVariable.size(); ++i) 
	{
		if(vectorVariable[i]->getVariableName() == argument) {
			vectorVariable[i]->setVariableValue(value);
			if(value.find_first_of("\"") == std::string::npos)	{
				vectorVariable[i]->setVariableType("double");
								
			} else {
				value = value.substr(value.find_first_of("\""), value.find_last_of("\"") + 1);
				vectorVariable[i]->setVariableType("string");
			}
			findVariable = true;			
		}
	}
	if(findVariable == false) {
		Variable* var = new Variable();
		var->setVariableValue(value);
		if(value.find_first_of("\"") == std::string::npos)	{
			var->setVariableType("double");
		} else {
			value = value.substr(value.find_first_of("\""), value.find_last_of("\"") + 1);
			var->setVariableType("string");
		}
		var->setVariableName(argument);
	}
	
	
				
	
}
