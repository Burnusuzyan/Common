#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <fstream>
#include <iostream>
#include "declare.h"
#include "input.h"
#include "output.h"
#include "variable.h"
//#include "command.h"
#include <vector>

class CommandEngine 
{
public:
	CommandEngine(std::string fileName);
	void setCommandEngine(std::string fileName);
	void parsingFile(std::string& commandLine);
	void readFile();
	//void addCommand();
	
public:
	std::vector<Command*> m_commands;
	std::vector<Variable*> m_variables;
private:
	std::string m_fileName;
};

#endif
