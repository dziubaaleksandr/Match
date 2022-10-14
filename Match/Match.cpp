#include "Match.h"
#include <iostream>
#include <fstream>

unsigned int Match::instanceNumber = 0;

Match::Match()
{
	std::cout << ". ";
	team1Goals = CalculateGoal(1);
	team2Goals = CalculateGoal(2);
	matchNumber = instanceNumber;
	Teams = getTeamsFromFile("Teams.txt", Teams);
	team1Name = getRandomteam();
	team2Name = getRandomteam();
	goalsTime = CalculateGoalsTime(goalsTime);
	instanceNumber++;
	while (team1Name == team2Name)
	{
		team2Name = getRandomteam();
	}
}

unsigned short Match::CalculateGoal(const int& seed)
{
	srand((unsigned)time(NULL) + seed);
	
	return rand() % 4;;
}

std::vector<unsigned short> Match::CalculateGoalsTime(std::vector<unsigned short> goalsTime)
{
	if (team1Goals == 0 && team2Goals == 0)
	{
		return goalsTime;
	}

	if (goalsTime.size() != 0)
	{
		goalsTime.clear();
	}
	srand((unsigned)time(NULL));
	unsigned int from = 0, to = 90 / (team1Goals + team2Goals);
	for (int i = 0; i < team1Goals + team2Goals; i++)
	{
		/*int randTime = (rand() % to) + from;*/
		int randTime = rand() %(to - from + 1) + from;
		from = randTime;
		to += 90 / (team1Goals + team2Goals);
		goalsTime.push_back(randTime);
	}

	return goalsTime;
}

std::vector<std::string> Match::getTeamsFromFile(const std::string& fileName, std::vector<std::string> Teams)
{
	std::fstream newfile;
	newfile.open(fileName, std::ios::in); //open a file to perform read operation using file object
	if (newfile.is_open()) { //checking whether the file is open
		std::string teamName;
		while (std::getline(newfile, teamName)) { //read data from file object and put it into string.
			Teams.push_back(teamName);//add team to vector Teams
		}
		newfile.close(); //close the file object.
	}

	return Teams;
}

void Match::setTeam1Goals(const short& Goals)
{
	if (Goals < 0 || Goals >3)
	{
		std::cerr << "Wrong goals count\n";
		return;
	}
	team1Goals = Goals;
	goalsTime = CalculateGoalsTime(goalsTime);
}

void Match::setTeam2Goals(const short& Goals)
{
	if (Goals < 0 || Goals >3)
	{
		std::cerr << "Wrong goals count";
		return;
	}
	team2Goals = Goals;
	goalsTime = CalculateGoalsTime(goalsTime);
}

void Match::printMatchInfo() const
{
	std::cout << "Match number:\t" << matchNumber << "\t" << team1Name << " vs " << team2Name << "\tScore " << team1Goals << ":" << team2Goals << std::endl << "Goal time: ";
	if (goalsTime.size() == 0)
	{
		std::cout << "No goals\t";
	}
	else
	{
		for (const int& i : goalsTime)
		{
			std::cout << i << "\t";
		}
	}
	
	std::cout << "Winner: " << getWinner() << std::endl;
}

std::string Match::getRandomteam()
{
	srand((unsigned)time(NULL));

	int randNumber = rand() % Teams.size();
	return Teams[randNumber];
}

std::string Match::getWinner() const
{
	if (team1Goals > team2Goals)
	{
		return team1Name;
	}
	else if (team1Goals < team2Goals)
	{
		return team2Name;
	}
	else
	{
		return "draw";
	}
}

void Match::writeInFile (const std::string& fileName) const
{
	std::fstream newfile;
	newfile.open(fileName, std::ios::app);  // open a file to perform write operation using file object
	if (newfile.is_open()) //checking whether the file is open {
	{
		
		newfile << "Match number:\t" << matchNumber << "\t" << team1Name << " vs " << team2Name << "\tScore " << team1Goals << ":" << team2Goals << std::endl << "Goal time: ";
		
		if (goalsTime.size() == 0)
		{
			newfile << "No goals\t";
		}
		else
		{
			for (const int& i : goalsTime)
			{
				newfile << i << "\t";
			}
		}

		newfile << "Winner: " << getWinner() << std::endl;
	}
	newfile.close(); //close the file object
}

void Match::setTeam1Name(const std::string& teamName) { team1Name = teamName; }
void Match::setTeam2Name(const std::string& teamName) { team1Name = teamName; }
int Match::sumOfGoals()const { return team1Goals + team2Goals; }
unsigned short Match::getMatchNumber() const { return matchNumber; }

