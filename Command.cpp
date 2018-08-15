#include "Command.h"
#include <iostream>



Command::Command()
{
}


Command::~Command()
{
}

int CommandList::call(const std::string& param) const
{
	{
		switch (action)
		{
		case read_file:
			m_list.ReadFromFile(param);
			break;
		case new_name:
			m_list.AddNewName(param);
			break;
		case print_list:
			break;
		case compute_score:
			std::cout << m_list.ComputeList();
			break;
		case quit:
			return -1;
			break;

		default: break;
		}
	}
}
