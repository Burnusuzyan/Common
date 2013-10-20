#include "commandEngine.h" 

CommandEngine::CommandEngine(std::string fileName) : m_fileName(fileName)
{

	CommandDeclare* declare = new CommandDeclare();
	CommandInput* input = new CommandInput();
	CommandOutput* output = new CommandOutput();
	m_commands.push_back(declare);
	m_commands.push_back(input);
	m_commands.push_back(output);
	Variable* var = new Variable("y");
	m_variables.push_back(var);
	

}

void CommandEngine::setCommandEngine(std::string fileName)
{
	m_fileName = fileName;
}

void CommandEngine::readFile()
{
	std::ifstream myFile(m_fileName.c_str());
    	
	if(myFile.is_open() ) {

		std::string commandLine;
		std::string text;
		while (myFile.good() )
		{
			getline (myFile, commandLine);
			int indexStartOfChar = commandLine.find_first_not_of(" ");

			if(indexStartOfChar != std::string::npos) {
				commandLine = commandLine.substr(indexStartOfChar, commandLine.size() );
				parsingFile(commandLine);
			} 
		}			
		myFile.close();
  	} else {
	 	std::cout << "Unable to open file"; 

	}  
}
void CommandEngine::parsingFile(std::string& allCommandLine)
{
	int indexOfFirstComma = allCommandLine.find_first_of(";");
	if(indexOfFirstComma != std::string::npos) {
		std::string firstCommandLine;
		firstCommandLine = allCommandLine.substr(0, indexOfFirstComma);//firstCommand  arajin hraman tox@

		int indexFirstWord = firstCommandLine.find_first_of(" ");
		bool findCommand = false;
		if(indexFirstWord != std::string::npos) {
			std::string firstCommandWord = firstCommandLine.substr(0, indexFirstWord);
				
			for(int i = 0; i < (int)m_commands.size(); ++i)
			{
				
				
				if(m_commands[i]->getCommandName() == firstCommandWord) {
					std::string argument = firstCommandLine.substr(indexFirstWord+1, firstCommandLine.size());
					m_commands[i]->exec(argument, m_variables);//talov argument 	firstCommandLine.substr(indexFirstWord+1, firstCommandLine.size());
					findCommand = true;		
				}	
			}
			
		}
		if(findCommand == false) {
                	int indexOfVeragrel = firstCommandLine.find_first_of("<-");
			
			if(indexOfVeragrel != std::string::npos) {
				std::string variable = firstCommandLine.substr(0, indexOfVeragrel);
				variable = variable.substr(variable.find_first_not_of(" "), variable.find_last_not_of(" ") + 1);
				firstCommandLine = firstCommandLine.substr(firstCommandLine.find_last_of(variable) + variable.size(), firstCommandLine.size());
				firstCommandLine = firstCommandLine.substr(firstCommandLine.find_first_not_of(" "), firstCommandLine.find_last_not_of(" ") + 1);
				std::cout << firstCommandLine << "\n";
				for(int i = 0; i < (int)m_variables.size(); ++i)
				{	
					if(m_variables[i]->getVariableName() == variable) {
						
						std::cout <<"var" <<variable << "\n";
						if(m_variables[i]->getVariableType() == "string") 
						{
							if(firstCommandLine.find_first_of("*") == std::string::npos || firstCommandLine.find_first_of("/") == std::string::npos ||firstCommandLine.find_first_of("-") == std::string::npos) {
								std::cout << "sintax error\n";
							}
							
							if(firstCommandLine.find_first_of("+") != std::string::npos) {
								
								m_variables[i]->setVariableValue(m_variables[i]->getVariableValue() + firstCommandLine.substr(firstCommandLine.find_first_of("+") + 1, firstCommandLine.size()));					
							}
						} else {
							std::cout <<"not find\n";
						}
						findCommand = true;		
					}
				}
				if(findCommand == false) {
					std::cout <<"not find\n";
				}	
			} else {
				std::cout <<"sintax ereor <-\n";
			}
		}
		 
	} else {
		/*
			exaption
		*/
		std::cout << "Error forgive ;\n";
	}
}
