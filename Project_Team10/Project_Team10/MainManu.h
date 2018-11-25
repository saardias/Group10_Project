#pragma once
#include <iostream>
#include <limits>
#include <cstdlib>
#include "Header1.h"
#include "Structs.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// functions
void MainMenu(User user1, User user2);
void Play_A_Game(User &user1, User &user2);
void CardsWars_Menu(User &user1, User &user2);
void Connect4_Menu(User &user1, User &user2);
void SnakesAndLadders_Menu(User &user1, User &user2);
void Options_player(User &user1);
void Options_Admin(User &user1);
void Options_premium(User &user1);

void MainMenu(User user1,User user2)
{
	int Choice;
	bool Flag = true;
	do
	{
		cout << endl << endl << "       ####    G A M E - - - K I T    ####" << endl << endl;
		cout << "        W A L C O M E - " <<user1.name<< endl << endl << "        Please choose option :" << endl << endl <<
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
			Play_A_Game(user1, user1);
			break;
		case 2:
			system("CLS");
			// scoreboard here
			break;
		case 3:
			system("CLS");
			// options here
			if (user1.if_manager)
			{
				Options_Admin(user1);
			}
			else if (user1.if_premium)
			{
				Options_premium(user1);
			}
			else
			{
				Options_player(user1);
			}
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

void Play_A_Game(User &user1, User &user2)
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
			CardsWars_Menu(user1, user2);
			break;
		case 2:
			Connect4_Menu(user1, user2);
			break;
		case 3:
			SnakesAndLadders_Menu(user1, user2);
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

void CardsWars_Menu(User &user1, User &user2)
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

void Connect4_Menu(User &user1, User &user2)
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

void SnakesAndLadders_Menu(User &user1, User &user2)
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

void Options_player(User &user1) 
{
	int Choice;
	bool Flag = true;
	do
	{
	system("CLS");
	cout << endl << endl << "       ####     O P T I O N S     ####    " << endl << endl;
	cout <<
		"        1 ) Watch Wins / Losses " << endl << endl <<
		"        2 ) Return" << endl << endl <<
		"       ###################################" << endl;
	cin >> Choice;
	getchar();
	switch (Choice)
	{
		case 1:
			system("CLS");
			// Watch Wins / Losses here
			break;
		case 2:
			system("CLS");
			cout << endl << endl << "       Press Enter to return to the Main menu" << endl;
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

void Options_Admin(User &user1)
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####     O P T I O N S - A D M I N    ####    " << endl << endl;
		cout <<
			"        1 ) Users list " << endl << endl <<
			"        2 ) Watch Wins / Losses " << endl << endl <<
			"        3 ) Connections" << endl << endl <<
			"        4 ) Reset user data" << endl << endl <<
			"        5 ) Change user type" << endl << endl <<
			"        6 ) Delete user" << endl << endl <<
			"        7 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			// user list
			break;
		case 2:
			system("CLS");
			// Watch Wins / Losses here
			break;
		case 3:
			system("CLS");
			// Connections here
			break;
		case 4:
			system("CLS");
			//  Reset user data here
			break;
		case 5:
			system("CLS");
			//  Change user type here
			break;
		case 6:
			system("CLS");
			//  Delete user here
			break;
		case 7:
			system("CLS");
			cout << endl << endl << "       Press Enter to return to the Main menu" << endl;
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

void Options_premium(User &user1)
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####     O P T I O N S - P R E M I U M    ####    " << endl << endl;
		cout <<
			"        1 ) Users list " << endl << endl <<
			"        2 ) Watch Wins / Losses " << endl << endl <<
			"        3 ) Plays Count" << endl << endl <<
			"        4 ) Change type with player" << endl << endl <<
			"        5 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			// user list
			break;
		case 2:
			system("CLS");
			// Watch Wins / Losses here
			break;
		case 3:
			system("CLS");
			// Plays Count here
			break;
		case 4:
			system("CLS");
			//  Change type with player here
			break;
		case 5:
			system("CLS");
			cout << endl << endl << "       Press Enter to return to the Main menu" << endl;
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