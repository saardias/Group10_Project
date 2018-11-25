#include <iostream>
#include <limits>
#include <cstdlib> 
using namespace std;

void Play_A_Game();
void CardsWars_Manu();
void Connect4_Manu();
void SnakesAndLadders_Manu();

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
			system("CLS");
			Play_A_Game();
			break;
		case 2:
			system("CLS");
			// scoreboard here
			break;
		case 3:
			system("CLS");
			// options here
			break;
		case 4:
			system("CLS");
			cout << endl << endl << "       B y e  B y e" << endl << endl;
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

void Play_A_Game()
{
	int Choice;
	bool Flag = true;
	do
	{

		cout << endl << endl << "       ####    P l a y     ####    " << endl << endl;
		cout <<
			"        1 ) Cards Wars " << endl << endl <<
			"        2 ) Connect Four" << endl << endl <<
			"        3 ) Snakes and Ladders" << endl << endl <<
			"        4 ) Return To Manu" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			CardsWars_Manu();
			break;
		case 2:
			Connect4_Manu();
			break;
		case 3:
			SnakesAndLadders_Manu();
			break;
		case 4:
			system("CLS");
			cout << endl << endl << "       Press Enter to return to the main manu" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		default:
			system("CLS");
			cout << endl << endl << "       Wrong Choice. Choose Again" << endl << endl;
			cout << "       Press Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}

void CardsWars_Manu()
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####     C A R D S   W A R S     ####    " << endl << endl;
		cout <<
			"        1 ) Play " << endl << endl <<
			"        2 ) Instructions" << endl << endl <<
			"        3 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			system("CLS");
			// activating the game here
			break;
		case 2:
			system("CLS");
			// instructions here
			break;
		case 3:
			system("CLS");
			cout << endl << endl << "       Press Enter to return" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		default:
			system("CLS");
			cout << endl << endl << "       Wrong Choice. Choose Again" << endl << endl;
			cout << "       Press Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}

void Connect4_Manu()
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####     C O N N E C T   F O U R     ####    " << endl << endl;
		cout <<
			"        1 ) Play " << endl << endl <<
			"        2 ) Instructions" << endl << endl <<
			"        3 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			system("CLS");
			// activating the game here
			break;
		case 2:
			system("CLS");
			// instructions here
			break;
		case 3:
			system("CLS");
			cout << endl << endl << "       Press Enter to return to the main manu" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		default:
			system("CLS");
			cout << endl << endl << "       Wrong Choice. Choose Again" << endl << endl;
			cout << "       Press Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}

void SnakesAndLadders_Manu()
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####     S N A K E S  &  L A d D E R S     ####    " << endl << endl;
		cout <<
			"        1 ) Play " << endl << endl <<
			"        2 ) Instructions" << endl << endl <<
			"        3 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			system("CLS");
			// activating the game here
			break;
		case 2:
			system("CLS");
			// instructions here
			break;
		case 3:
			system("CLS");
			cout << endl << endl << "       Press Enter to return to the main manu" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		default:
			system("CLS");
			cout << endl << endl << "       Wrong Choice. Choose Again" << endl << endl;
			cout << "       Press Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}