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
	case Action::read_file:
		m_list.ReadFromFile(m_param);
		break;
	case Action::new_name:
		m_list.AddNewName(m_param);
		break;
	case Action::print_list:
		break;
	case Action::compute_score:
		std::cout << m_list.ComputeList();
		break;
	case Action::quit:
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

CommandList::Action CommandList::TraitsToAction(const std::string & str)
{
	if (str == "read_file")
		return Action::read_file;
	if (str == "compute_score")
		return Action::compute_score;
	if (str == "new_name")
		return Action::new_name;
	if (str == "print_list")
		return Action::print_list;
	if (str == "quit")
		return Action::quit;

	std::cout << "Not implemented" <<std::endl;
	return Action::error;
}

CommandList::CommandList(ListWords& list, const std::string& str)
	:m_list(list)
{
	auto command = ParseCommand(str);
	m_param = command.second;
	m_action = TraitsToAction(command.first);
}
