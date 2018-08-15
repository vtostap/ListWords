#pragma once
#include <list>
#include <string>

class ListWords
{
private:
	std::list<std::string> m_list;

public:
	ListWords(const std::string& path = "");
	~ListWords();
	void AddNewName(const std::string& name);
	int ComputeList();

private:
	void ReadFromFile(const std::string& path);
	int ComputeWord(std::string word);
};

