#include "ListWords.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

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
	for (auto iter = m_list.begin(); iter != m_list.end(); ++index, ++iter)
	{
		result = index * ComputeWord(*iter);
	}
	return result;
}

void ListWords::ReadFromFile(const std::string & path)
{
	std::ifstream myfile(path);

	if (myfile.is_open())
	{
		std::string line;
		while (std::getline(myfile, line))
		{
			m_list.push_back(line);
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
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
