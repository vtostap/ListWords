#pragma once
#include <list>
#include <string>

class ListWords
{
private:
	std::list<std::string> m_list;

public:
	explicit ListWords(const std::string& path = "");
	~ListWords();
	void AddNewName(const std::string& name);
	int ComputeList();
	void ReadFromFile(const std::string& path);
	void Print();

private:
	int ComputeWord(std::string word);
};

