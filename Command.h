#pragma once
#include "ListWords.h"

class Command
{
public:
	Command();
	~Command();

	virtual int call() const = 0;
};

class CommandList : public Command
{
	ListWords& m_list;
	enum Action { read_file, new_name, print_list, compute_score, quit} m_action;
	std::string m_param;
public:
	CommandList(ListWords& list, const std::string& str);
	int call() const override;
private:
	std::pair<std::string, std::string> ParseCommand(const std::string str);
};