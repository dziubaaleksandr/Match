#include "MatchManagement.h"
#include "Match.h"
#include <algorithm>
#include <iostream>
#include <vector>

void MatchManagement::printMatches(const std::vector<Match>& matches)
{
	for (const Match& i : matches)
	{
		i.printMatchInfo();
	}
}

MatchManagement::MatchManagement(const unsigned int& numberOfMatches)
{
	matches.reserve(numberOfMatches);
	for (int i = 0; i < numberOfMatches; i++)
	{
		matches.emplace_back();
	}
}

void MatchManagement::printMatches()
{
	printMatches(matches);
}

void MatchManagement::printMatchesReverse()
{
	for (int i = matches.size() - 1; i >= 0; i--)
	{
		matches[i].printMatchInfo();
	}
}

void MatchManagement::printSortedByGoals()
{
	std::vector<Match> sorted(matches);
	std::sort(sorted.begin(), sorted.end(), [](const Match& a, const Match& b) {
		return a.sumOfGoals() > b.sumOfGoals();
		});

	printMatches(sorted);
}

std::vector<Match>::iterator MatchManagement::findMatch(const unsigned int& matchNumber)
{
	std::vector<Match>::iterator it = std::find_if(matches.begin(), matches.end(), [&](const Match& a)
		{
			return matchNumber == a.getMatchNumber();
		});

	return it;
}

void MatchManagement::removeMatch(const unsigned int& matchNumber)
{
	if (matches.size() == 0)
	{
		std::cerr << "There are no matches!\n";
		return;
	}
	else if (matchNumber >= matches.size())
	{
		std::cerr << "There are not so many matches!\n";
		return;
	}
	else
	{
		auto it = findMatch(matchNumber);
		if (it == matches.end())
		{
			std::cout << "There isn't match with number " << matchNumber << std::endl;
			return;
		}
		matches.erase(it);
		std::cout << "Match was deleted!\n";
	}
	
}

void MatchManagement::addMatch(const Match& match)
{
	if (matches.size() < 21)
	{
		matches.push_back(match);
	}
}

void MatchManagement::writeInFile(const std::string& fileName)
{
	for (const Match& m : matches)
	{
		m.writeInFile(fileName);
	}
	std::cout << "Done!\n";
} 

Match& MatchManagement::operator[](const int& i)
{
	if (matches.size() == 0)
	{
		std::cerr << "There are no matches!\n";
		throw 1;
	}
	else if (i < 0)
	{
		std::cerr << "Are you stupid? Match number can not be less than 0!\n";
		throw 1;
	}
	else if (i >= matches.size())
	{
		std::cerr << "There are not so many matches!\n";
		throw 1;
	}
	else
	{
		auto it = findMatch(i);
		if (it == matches.end())
		{
			std::cout << "There isn't match with number " << i << std::endl;
			throw 1;
		}
		return *it;
	}
}