#include "pch.h"
#include <iostream>
#include <set>
#include <string>
#include <regex>

void addConctact(const std::string & nameIn, std::set<std::string> & contacts)
{
	std::string name = nameIn;
	//приводим к нижнему регистру
	std::transform(name.begin(), name.end(), name.begin(), tolower);
	contacts.insert(name);
};

int calculateMatches(const std::set<std::string> & myContacts, const std::string & matchesName)
{
	//Проходим по всем именам осуществляя поиск подстроки в строке(имени). 
	//Увеличиваем счетчик

	int count = 0;
	
	for(auto nameItr = myContacts.upper_bound(matchesName); nameItr != myContacts.end(); nameItr++) {

		if ((*nameItr).find(matchesName, 0) != std::string::npos)
		{
			count++;
		}
		else
		{
			return count;
		}
	}
	return count;
};


int main()
{
	//хранится в контейнере set что позволяет избежать повторений

	std::set<std::string> myContacts = 
	{
		"alexander",
		"alexey",
		"andrey",
		"kirill",
		"kirusha",
		"zahar",
	};	
	addConctact("Anton", myContacts);
	

	int count = calculateMatches(myContacts, "alex");	
	
    std::cout << count; 

	//Сложность алгоритма O(log(n)) — линейная сложность
	//затраченное время 1 час 30 минут
}
