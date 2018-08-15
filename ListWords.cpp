#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

#include "ListWords.h"

ListWords::ListWords(const std::string& path)
{
	if (path.empty())
		return;
	else ReadFromFile(path);
}

ListWords::~ListWords()
{
}

void ListWords::AddNewName(const std::string & name)
{
	m_list.push_back(name);
}

int ListWords::ComputeList()
{
	int result = 0;
	int index = 1;
	m_list.sort();
	for (auto iter = m_list.begin(); iter != m_list.end(); ++index, ++iter)
	{
		result = index * ComputeWord(*iter);
	}
	return result;
}

void ListWords::ReadFromFile(const std::string & path)
{
	std::ifstream file;
	file.open(path);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			m_list.push_back(line);
		}
		file.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}

void ListWords::Print()
{
	m_list.sort();
	for (auto iter = m_list.begin(); iter != m_list.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

int ListWords::ComputeWord(std::string word)
{
	const char start_letter = 'a';
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);

	int worth = 0;
	for (auto iter = word.begin(); iter != word.end(); ++iter)
	{
		worth = *iter - start_letter + 1 + worth;
	}
	return worth;
}
