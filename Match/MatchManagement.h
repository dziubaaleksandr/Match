#pragma once
#include "Match.h"

class MatchManagement
{
	std::vector<Match> matches;
	void printMatches(const std::vector<Match>&);
	std::vector<Match>::iterator findMatch(const unsigned int&);
public:
	MatchManagement(const unsigned int&);
	void printMatches();
	void printMatchesReverse();
	void printSortedByGoals();
	void removeMatch(const unsigned int&);
	void addMatch(const Match&);
	void writeInFile(const std::string&);
	Match& operator[](const int&);

};