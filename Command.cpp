#include "Command.h"
#include <iostream>



Command::Command()
{
}


Command::~Command()
{
}

int CommandList::call() const
{
	switch (m_action)
	{
	case read_file:
		m_list.ReadFromFile(m_param);
		break;
	case new_name:
		m_list.AddNewName(m_param);
		break;
	case print_list:
		break;
	case compute_score:
		std::cout << m_list.ComputeList();
		break;
	case quit:
		return -1;
		break;

	default: 
		break;
	}
	return 1;
}

std::pair<std::string, std::string> CommandList::ParseCommand(const std::string str)
{
	std::pair<std::string, std::string> result;
	size_t pos = str.find(':');
	if (pos == std::string::npos)
	{
		std::cout << "Wrong command" << std::endl;
		return result;
	}
	std::string command = str.substr(pos);

	bool first = false;
	bool second = false;
	for (auto iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter != ' ' && second == false)
			first = true;
		if (*iter == ' ' && first && second == false)
		{
			second = true;
			first = false;
		}

		if (*iter != ' ' && first)
			result.first.push_back(*iter);
		if (*iter != ' ' && second)
			result.second.push_back(*iter);
	}
	return result;
}

CommandList::CommandList(ListWords& list, const std::string& str)
	:m_list(list)
{
}
