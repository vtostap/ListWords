#pragma once
#include "ListWords.h"

class Command
{
public:
	Command();
	~Command();

	virtual int call(const std::string& param = "") const = 0;
};

class CommandList : public Command
{
	ListWords& m_list;
	enum Action { read_file, new_name, print_list, compute_score, quit} action;

	int call(const std::string& param = "") const override;
};