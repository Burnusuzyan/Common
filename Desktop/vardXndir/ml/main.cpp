#include<iostream>
#include "commandEngine.h"


int main()
{
       
	std::string fileName = "example.txt";
	
	CommandEngine engine(fileName);
	engine.readFile();
	//int a;	
	//std::cin >> a;

	return 0;
}



