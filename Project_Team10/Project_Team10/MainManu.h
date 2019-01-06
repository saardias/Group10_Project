#pragma once
#include <iostream>
#include <limits>
#include <cstdlib>
#include "1.Sign_in_modules.h"
#include "Header1.h"
#include "Structs.h"
#include "Instructions.h"
#include "4inaRow.h"
#include "playSnD.h"
#include "Statistics.h"
#include "ScoreBoard.h"
#include "GameAvailability.h"
#include "ChangeTypeFunctions.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// functions
void MainMenu(User user1, User user2);
void Play_A_Game(User &user1, User &user2);
void CardsWars_Menu(User &user1, User &user2);
void Connect4_Menu(User &user1, User &user2);
void SnakesAndLadders_Menu(User &user1, User &user2);
void Options_player(User &user1);
void Options_Admin(User &user1, User &user2);
void Options_premium(User &user1, User &user2);



// main menu
void MainMenu(User user1, User user2)
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####    G A M E - - - K I T    ####" << endl << endl;
		cout << "        W A L C O M E - " << user1.name << endl << endl << "        Please choose option :" << endl << endl <<
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
			Play_A_Game(user1, user2);
			break;
		case 2:
			system("CLS");
			Display_Game_Score_Board("Connect Four");
			Display_Game_Score_Board("Snakes and Ladders");
			Display_Game_Score_Board("War");
			cout << "       Press Enter to return" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

			break;
		case 3:
			system("CLS");
			if (user1.if_manager)
			{
				Options_Admin(user1, user2);
			}
			else if (user1.if_premium)
			{
				Options_premium(user1, user2);
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
			cout << endl << endl << "       Wrong Choice. Choose Again" << endl << endl;
			cout << "       Press Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}
// play a game menu
void Play_A_Game(User &user1, User &user2)
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
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
			if (Check_Game_Availability("War"))
			{
				CardsWars_Menu(user1, user2);
			}
			else
			{
				system("CLS");
				cout << "\t Game is not available" << endl;
				cout << endl << endl << "\t Press Enter to return" << endl;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			}
			break;
		case 2:
			if (Check_Game_Availability("Connect Four"))
			{
				Connect4_Menu(user1, user2);
			}
			else
			{
				system("CLS");
				cout << "\t Game is not available" << endl;
				cout << endl << endl << "\t Press Enter to return" << endl;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			}
			break;
		case 3:
			if (Check_Game_Availability("Snakes and Ladders"))
			{
				SnakesAndLadders_Menu(user1, user2);
			}
			else
			{
				system("CLS");
				cout << "\t Game is not available" << endl;
				cout << endl << endl << "\t Press Enter to return" << endl;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			}
			cout << endl << endl << "\t Press Enter to return" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
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
// card wars menu
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
			Set_Game_Run_Count("War");
			PlayWar(user1, user2);	
			break;
		case 2:
			system("CLS");
			DataFilesReadOnly("War");

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
// connect4 menu
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
			Set_Game_Run_Count("Connect Four");
			PlayForInARow(user1, user2);//activating game here
			system("CLS");
			cout << endl << endl << "       Press Enter to return to the main manu" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			Flag = false;
			break;
		case 2:
			system("CLS");
			DataFilesReadOnly("Connect Four");
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
// S&L menu
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
			Set_Game_Run_Count("Snakes and Ladders");
			play_snakes_and_ladders(user1, user2);
			break;
		case 2:
			system("CLS");
			DataFilesReadOnly("Snakes and Ladders");
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
// option menu of player 
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
			Display_Personal_User_Statistics(user1.name);
			cout << endl << endl << "       Press Enter to return." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
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
// option menu of admin 
void Options_Admin(User &user1, User &user2)
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
			"        3 ) Logins of players" << endl << endl <<
			"        4 ) Reset user data" << endl << endl <<
			"        5 ) Change user type" << endl << endl <<
			"        6 ) Delete user" << endl << endl <<
			"        7 ) Block/Enable Game" << endl << endl <<
			"        8 ) Return" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			system("CLS");
			PrintingUsersList();
			cout << endl << endl << "       Press Enter to return" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			break;
		case 2:
			system("CLS");
			WatchUserWinLose();
			break;
		case 3:
			system("CLS");
			WhatchLogins();
			break;
		case 4:
			system("CLS");
			ResetUserStats();
			break;
		case 5:
			system("CLS");
			Change_user_type(user1, user2);
			break;
		case 6:
			system("CLS");
			DeletePlayerFromData(user1, user2);
			break;
		case 7:
			system("CLS");
			Block_Enable_Game();
			break;
		case 8:
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
// option menu of premium 
void Options_premium(User &user1, User &user2)
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
			system("CLS");
			PrintingUsersList();
			cout << endl << endl << "       Press Enter to return" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			break;
		case 2:
			system("CLS");
			WatchUserWinLose();
			break;
		case 3:
			system("CLS");
			ShowingPlayCount();
			cout << endl << endl << "       Press Enter to return" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			break;
		case 4:
			system("CLS");
			Excahnge_Type_With_Player(user1, user2);
			cout << endl << endl << "       Press Enter to return" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
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
