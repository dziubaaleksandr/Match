#include <iostream>
#include "MatchManagement.h"

using namespace std;

int main()
{
	while(true)
	{
		
		cout << "Enter number of matches[0-20): ";
		unsigned int numberOfInstance;
		cin >> numberOfInstance;
		if (numberOfInstance < 0 || numberOfInstance >= 20)
		{
			std::cerr << "Wrong enter! Try again!\n";
			continue;
		}
		cout << endl;
		MatchManagement manage(numberOfInstance);
		bool running = true;
		
		while (running)
		{
			system("CLS");
			cout << "To display information for all matches enter 1\nTo display information for all matches in reverse order enter 2\n" <<
				"To dispaly information about particular match enter 3\nTo disaply matches sorted by goals scored enter 4\n" <<
				"To save information in file enter 5\nTo add match enter 6\nTo delete match enter 7\nTo quit enter 8\nYour choice: ";

			unsigned short userChoice;
			cin >> userChoice;
			switch (userChoice)
			{
			case 1:
				system("CLS");
				manage.printMatches();
				system("pause");
				break;
			case 2:
				system("CLS");
				manage.printMatchesReverse();
				system("pause");
				break;
			case 3:
				system("CLS");
				cout << "Enter the match number: ";
				int matchNumber;
				cin >> matchNumber;

				try
				{
					manage[matchNumber].printMatchInfo();
					system("pause");
					break;
				}
				catch (int)
				{
					system("pause");
					break;
				}
			case 4:
				system("CLS");
				manage.printSortedByGoals();
				system("pause");
				break;
			case 5:
			{
				system("CLS");
				cout << "Enter file name(example.txt): ";
				string fileName;
				cin >> fileName;

				manage.writeInFile(fileName);
				system("pause");
				break;
			}	
			case 6:
				system("CLS");
				manage.addMatch(Match());
				cout << "Done\n";
				system("pause");
				break;
			case 7:
				system("CLS");
				cout << "Enter the match number that you want delete: ";
				int matchNumberDel;
				cin >> matchNumberDel;
				manage.removeMatch(matchNumberDel);
				system("pause");
				break;
			case 8:
				running = false;
				break;
			default:
				system("CLS");
				cout << "Wrong choice. Try again\n";
				system("pause");
				break;
			}
		}
		break;
	}
}

