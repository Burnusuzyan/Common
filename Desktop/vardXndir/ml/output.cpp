#include "output.h"


/*
CommandDeclare::CommandDeclare() : Command("declare")
{}
*/
void CommandOutput::exec(std::string& argument, std::vector<Variable*>& vectorVariable )
{
	argument = argument.substr(argument.find_first_not_of(" "), argument.find_last_not_of(" ") + 1);
	
	for(int i = 0; i < vectorVariable.size(); ++i) 
	{
		
		if(vectorVariable[i]->getVariableName() == argument) {
			std::cout << vectorVariable[i]->getVariableValue();
			return;		
		}
	}
	/*
	if(argument.find_first_of("\"" !=std::string::npos && argument.find_last_of("\"" !=std::string::npos) ) ) {
			std::cout << argument.substr(argument.find_first_not_of("\""), argument.find_last_not_of("\"") + 1);
	} else {
		std::cout << "not decler var\n";
	}
	*/

}
