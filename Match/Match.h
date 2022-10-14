#pragma once
#include <string>
#include <vector>


class Match
{
	unsigned short team1Goals;
	unsigned short team2Goals;
	unsigned short matchNumber;
	static unsigned int instanceNumber;
	std::vector<std::string> Teams;
	std::string team1Name;
	std::string team2Name;
	std::vector<unsigned short> goalsTime;

	unsigned short CalculateGoal(const int&);
	std::vector<std::string> getTeamsFromFile(const std::string&, std::vector<std::string>);
	std::vector<unsigned short> CalculateGoalsTime(std::vector<unsigned short>);
	std::string getRandomteam();

public:
	Match();
	std::string getWinner() const;
	int sumOfGoals() const;
	void setTeam1Name(const std::string&);
	void setTeam2Name(const std::string&);
	void setTeam1Goals(const short&);
	void setTeam2Goals(const short&);
	void printMatchInfo() const;
	void writeInFile (const std::string&) const;
	unsigned short getMatchNumber()const;
};

