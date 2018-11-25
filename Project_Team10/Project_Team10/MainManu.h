#include <iostream>
#include <limits>
#include <cstdlib> 
using namespace std;

void MainManu()
{
	int Choice;
	bool Flag = true;
	do
	{
		cout << endl << endl << "       ####    G A M E - - - K I T    ####    " << endl << endl;
		cout << "        W A L C O M E   " << endl << endl << "        Please choose option :" << endl << endl <<
			"        1 ) Play a Game" << endl << endl <<
			"        2 ) Scoreboard" << endl << endl <<
			"        3 ) Options" << endl << endl <<
			"        4 ) Exit" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			system("CLS");
			cout << "       B y e  B y e" << endl << endl;
			cout << "       Press Enter to exit" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		default:
			system("CLS");
			cout<< endl << endl<< "       Wrong Choice. Choose Again" << endl << endl;
			cout << "       Press Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}