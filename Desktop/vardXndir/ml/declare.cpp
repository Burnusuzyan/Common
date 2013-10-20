#include "declare.h"


/*
CommandDeclare::CommandDeclare() : Command("declare")
{}
*/
void CommandDeclare::exec(std::string& argument, std::vector<Variable*>& vectorVariable )
{
	Variable* var = new Variable();
	
	argument = argument.substr(argument.find_first_not_of(" "), argument.find_last_not_of(" ") + 1);
	std::string variable;
	int index = argument.find_first_of("<-");
	bool findVariable = false;

	if(index != std::string::npos) {
		variable = argument.substr(0, index);
		variable = variable.substr(0, variable.find_first_not_of(" ") + 1);
		
		for(int i = 0; i < vectorVariable.size(); ++i) 
		{
			if(vectorVariable[i]->getVariableName() == variable) {
				std::cout << "you have variable\n";
				findVariable = true;			
			}
		}
	
		if(findVariable == false) {
			argument = argument.substr(index + 2, argument.size() );
			
			argument = argument.substr(argument.find_first_of("\"") + 1, argument.find_last_of("\"") -1);

			var->setVariableName(variable);
			var->setVariableValue(argument);
			if(argument.find_first_of("\"") == std::string::npos)	{
				var->setVariableType("double");
								
			} else {
				argument = argument.substr(argument.find_first_of("\""), argument.find_last_of("\"") + 1);
				var->setVariableType("string");
			}
		
			vectorVariable.push_back(var);		
		}
	} else {
		for(int i = 0; i < vectorVariable.size(); ++i) 
		{
			if(vectorVariable[i]->getVariableName() == argument) {
				std::cout << "you have variable\n";
				findVariable = true;			
			}
		}
		if(findVariable == false) {
			var->setVariableName(argument);
			vectorVariable.push_back(var);
		}
	}

	
	
}
