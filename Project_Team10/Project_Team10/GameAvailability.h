#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Display_Game_Run_Count(string Game) {
	bool flag = false;
	ifstream Display;
	string Claim;
	if (Game == "Connect Four") {
		Display.open("Connect Four Availability.txt");
		while (getline(Display, Claim)) {
			if (flag == true) {
				cout << "Game Connect Four has ran " << Claim << " Times." << endl;
				break;
			}
			if (Claim[0] == 'A') {
				flag = true;
			}
		}
		Display.close();
	}
	if (Game == "War") {
		Display.open("Cards Availability.txt");
		while (getline(Display, Claim)) {
			if (flag == true) {
				cout << "Game Cards Battle has ran " << Claim << " Times." << endl;
				break;
			}
			if (Claim[0] == 'A') {
				flag = true;
			}
		}
		Display.close();
	}
	if (Game == "Snakes and Ladders") {
		Display.open("Snakes and Ladders Availability.txt");
		while (getline(Display, Claim)) {
			if (flag == true) {
				cout << "Game Snakes and Ladders has ran " << Claim << " Times." << endl;
				break;
			}
			if (Claim[0] == 'A') {
				flag = true;
			}
		}
		Display.close();
	}
}

void Set_Game_Run_Count(string Game) {
	bool flag = false;
	int number = 0;
	ifstream Check;
	ofstream Set;
	string Claim;
	Set.open("temp.txt");
	if (Game == "Connect Four") {
		Check.open("Connect Four Availability.txt");
		getline(Check, Claim);
		Check >> number;
		number += 1;
		Set << Claim << endl << number << endl;
		Set.close();
		Check.close();
		remove("Connect Four Availability.txt");
		rename("temp.txt", "Connect Four Availability.txt");
	}
	else if (Game == "Snakes and Ladders") {
		Check.open("Snakes and Ladders Availability.txt");
		getline(Check, Claim);
		Check >> number;
		number += 1;
		Set << Claim << endl << number << endl;
		Set.close();
		Check.close();
		remove("Snakes and Ladders Availability.txt");
		rename("temp.txt", "Snakes and Ladders Availability.txt");
	}
	else if (Game == "War") {
		Check.open("Cards Availability.txt");
		getline(Check, Claim);
		Check >> number;
		number += 1;
		Set << Claim << endl << number << endl;
		Set.close();
		Check.close();
		remove("Cards Availability.txt");
		rename("temp.txt", "Cards Availability.txt");
	}
}

void Set_Game_Availability(int Availability,string Game) {
	bool flag = false;
	ifstream Check;
	ofstream Set;
	string Claim;
	Set.open("temp.txt");
	if (Game == "Connect Four") {
		Check.open("Connect Four Availability.txt");
		while (getline(Check, Claim)) {
			if (flag == true) {
				Set << Claim << endl;
				break;
			}
			if (Availability == 1) {
				Set << "Availability :1" << endl;
				flag = true;
			}
			else if (Availability == 0) {
				Set << "Availability :0" << endl;
				flag = true;
			}
			else {
				cout << "Error Banning/Releasing a Game!" << endl;
				break;
			}
		}
		Set.close();
		Check.close();
		remove("Connect Four Availability.txt");
		rename("temp.txt", "Connect Four Availability.txt");
	}
	else if (Game == "Snakes and Ladders") {
		Check.open("Snakes and Ladders Availability.txt");
		while (getline(Check, Claim)) {
			if (flag == true) {
				Set << Claim << endl;
				break;
			}
			if (Availability == 1) {
				Set << "Availability :1" << endl;
				flag = true;
			}
			else if (Availability == 0) {
				Set << "Availability :0" << endl;
				flag = true;
			}
			else {
				cout << "Error Banning/Releasing a Game!" << endl;
				break;
			}
		}
		Set.close();
		Check.close();
		remove("Snakes and Ladders Availability.txt");
		rename("temp.txt", "Snakes and Ladders Availability.txt");
	}
	else if (Game == "War") {
		Check.open("Cards Availability.txt");
		while (getline(Check, Claim)) {
			if (flag == true) {
				Set << Claim << endl;
				break;
			}
			if (Availability == 1) {
				Set << "Availability :1" << endl;
				flag = true;
			}
			else if (Availability == 0) {
				Set << "Availability :0" << endl;
				flag = true;
			}
			else {
				cout << "Error Banning/Releasing a Game!" << endl;
				break;
			}
		}
		Set.close();
		Check.close();
		remove("Cards Availability.txt");
		rename("temp.txt", "Cards Availability.txt");
	}
}

bool Check_Game_Availability(string Game) {
	ifstream Check;
	string Claim;
	if (Game == "Connect Four") {
		Check.open("Connect Four Availability.txt");
		while (getline(Check, Claim)) {
			if (Claim == "Availability :1") {
				Check.close();
				return true;
			}
			else if (Claim == "Availability :0") {
				Check.close();
				return false;
			}
		}
	}
	else if (Game == "Snakes and Ladders") {
		Check.open("Snakes and Ladders Availability.txt");
		while (getline(Check, Claim)) {
			if (Claim == "Availability :1") {
				Check.close();
				return true;
			}
			else if (Claim == "Availability :0") {
				Check.close();
				return false;
			}
		}
	}
	else if (Game == "War") {
		Check.open("Cards Availability.txt");
		while (getline(Check, Claim)) {
			if (Claim == "Availability :1") {
				Check.close();
				return true;
			}
			else if (Claim == "Availability :0") {
				Check.close();
				return false;
			}
		}
	}
}
//display activations number of the games
void ShowingPlayCount()
{
	Display_Game_Run_Count("Connect Four");
	Display_Game_Run_Count("War");
	Display_Game_Run_Count("Snakes and Ladders");
}

// blocking a game
void Block_Game()
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####    B L O C K     ####    " << endl << endl;
		cout <<
			"        1 ) Cards Wars " << endl << endl <<
			"        2 ) Connect Four" << endl << endl <<
			"        3 ) Snakes and Ladders" << endl << endl <<
			"        4 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			Set_Game_Availability(0, "War");
			system("CLS");
			cout << endl << endl << "       Cards War - Blocked" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		case 2:
			Set_Game_Availability(0, "Connect Four");
			system("CLS");
			cout << endl << endl << "       Connect Four - Blocked" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		case 3:
			Set_Game_Availability(0, "Snakes and Ladders");
			system("CLS");
			cout << endl << endl << "       Snakes and Ladders - Blocked" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		case 4:
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
// enabling a game
void Enable_Game()
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####    E N A B L E     ####    " << endl << endl;
		cout <<
			"        1 ) Cards Wars " << endl << endl <<
			"        2 ) Connect Four" << endl << endl <<
			"        3 ) Snakes and Ladders" << endl << endl <<
			"        4 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			Set_Game_Availability(1, "War");
			cout << endl << endl << "       Cards War - Enabled" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		case 2:
			Set_Game_Availability(1, "Connect Four");
			cout << endl << endl << "       Connect Four - Enabled" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		case 3:
			Set_Game_Availability(1, "Snakes and Ladders");
			cout << endl << endl << "       Snakes and Ladders - Enabled" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		case 4:
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
// menu for blocking/enabling game
void Block_Enable_Game()
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####    Block/Enable Game     ####    " << endl << endl;
		cout <<
			"        1 ) Block Game" << endl << endl <<
			"        2 ) Enable Game" << endl << endl <<
			"        3 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			Block_Game();
			break;
		case 2:
			Enable_Game();
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

