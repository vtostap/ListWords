#include <iostream>
#include <string>
#include "Command.h"


int main()
{
	int exit = 0;
	ListWords list_words;
	while (exit >= 0)
	{
		std::string line = "";
		std::cout << "Enter command : ";
		std::getline(std::cin, line);
		CommandList command(list_words, line);
		exit = command.call();
	}
	return 0;
}
