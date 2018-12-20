#pragma once
#include <iostream>
#include <limits>
#include <cstdlib>
#include "Header1.h"
#include "Structs.h"
#include "Instructions.h"
#include "4inaRow.h"
#include "playSnD.h"
#include "Statistics.h"
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
void WatchUserWinLose();
void PrintingUsersList();
void WhatchLogins();
void ResetUserStats();
bool Check_Name_Input(string name);
bool Check_Name_Input_of_UserToPremium(string name);
void ChangeUserToPremium(string name);
void UserToPremium(User &user2);
void ResetUserLogins(string name);
void Change_user_type(User &user2);
void PremiumToUser();
void Excahnge_Type_With_Player(User &user,User &user2);
void Pre_Lost(User &pre, User &NewPre);

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
			// scoreboard here
			break;
		case 3:
			system("CLS");
			// options here
			if (user1.if_manager)
			{
				Options_Admin(user1, user2);
			}
			else if (user1.if_premium)
			{
				Options_premium(user1,user2);
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
			PlayWar(user1, user2);	//Changed here to play war against user to just play war
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
			"        7 ) Return" << endl << endl <<
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
			Change_user_type(user2);
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
			// Plays Count here
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

void WatchUserWinLose()
{
	cout << "Connect Four Statistics : " << endl;
	Display_Statistics("Connect Four");
	cout << "Snakes and Ladders Statistics : " << endl;
	Display_Statistics("Snakes and Ladders");
	cout << "Cards War Statistics : " << endl;
	Display_Statistics("War");
	cout << endl << endl << "       Press Enter to return to options" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}
void PrintingUsersList()
{
	ifstream users_in;
	User temp;
	users_in.open("user_data.txt");
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "       \t     ******************** " << " U S E R S   L I S T  ********************" << endl << endl;
	cout << endl;
	while (!users_in.eof())
	{
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		cout << "\t\t\t\t" << temp.name << " - ";
		if (temp.if_manager)
		{
			cout << " Admin" << "\t\t\t\t" << endl;
		}
		else if (temp.if_premium)
		{
			cout << " Premium Player" << "\t\t\t" << endl;
		}
		else
		{
			cout << " Player" << "\t\t\t\t" << endl;
		}
		cout << endl;
	}
	users_in.close();
}
void WhatchLogins()
{
	ifstream users_in;
	User temp;
	users_in.open("user_data.txt");
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "       \t     ******************** " << " L O G I N S  C O U N T S  ********************" << endl << endl;
	cout << endl;
	while (!users_in.eof())
	{
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		cout << "\t\t\t" << temp.name << "\t-\t" << temp.logins << endl << endl;
	}
	users_in.close();
	cout << endl << endl << "       Press Enter to return" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}
void ResetUserStats()
{
	bool flag = false;
	string name;
	cout << "Connect Four Statistics : " << endl;
	Display_Statistics("Connect Four");
	cout << "Snakes and Ladders Statistics : " << endl;
	Display_Statistics("Snakes and Ladders");
	cout << "Cards War Statistics : " << endl;
	Display_Statistics("War");
	cout << endl;
	do
	{
		cout << "\t\t enter the name of a player to reset his stats." << endl;
		cin >> name;
		if (Check_Name_Input(name))
		{
			flag = false;
		}
		else
		{
			cout << "\t\t Name Does not exist !" << endl;
			flag = true;
		}
	} while (flag);
	Master_Statistics_Reset(name);
	ResetUserLogins(name);
	cout << endl << endl << "\t\t Press Enter to return" << endl;
	getchar();
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}
bool Check_Name_Input(string name)
{
	ifstream users_in;
	User temp;
	users_in.open("user_data.txt");
	while (!users_in.eof())
	{
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		if (name == temp.name)
		{
			users_in.close();
			return true;
		}
	}
	users_in.close();
	return false;
}
bool Check_Name_Input_of_UserToPremium(string name)
{
	ifstream users_in;
	User temp;
	users_in.open("user_data.txt");
	while (!users_in.eof())
	{
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		if (name == temp.name && (temp.if_manager == 1 || temp.if_premium==1))
		{
			cout << "\t\t This user is not a player!" << endl;
			users_in.close();
			return false;
		}
		if (name == temp.name)
		{
			users_in.close();
			return true;
		}
	}
	users_in.close();
	cout << "\t\t Name Does not exist !" << endl;
	return false;
}
void ChangeUserToPremium(string name)
{
	ifstream users_in;
	ofstream users_out;
	User temp;
	users_in.open("user_data.txt");
	users_out.open("temp.txt");
	while (!users_in.eof()) {
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		if (temp.name == name)
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << temp.logins << endl;
			users_out << temp.if_manager << endl;
			users_out << 1;
			if (users_in.peek() != std::ifstream::traits_type::eof())
				users_out << endl;
		}
		else
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << temp.logins << endl;
			users_out << temp.if_manager << endl;
			users_out << temp.if_premium;
			if (users_in.peek() != std::ifstream::traits_type::eof())
				users_out << endl;
		}
	}
	users_in.close();
	users_out.close();
	remove("user_data.txt");
	rename("temp.txt", "user_data.txt");
}
void ResetUserLogins(string name)
{
	ifstream users_in;
	ofstream users_out;
	User temp;
	users_in.open("user_data.txt");
	users_out.open("temp.txt");
	while (!users_in.eof()) {
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		if (temp.name == name)
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << 0 << endl;
			users_out << temp.if_manager << endl;
			users_out << temp.if_premium;
			if (users_in.peek() != std::ifstream::traits_type::eof())
				users_out << endl;
		}
		else
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << temp.logins << endl;
			users_out << temp.if_manager << endl;
			users_out << temp.if_premium;
			if (users_in.peek() != std::ifstream::traits_type::eof())
				users_out << endl;
		}
	}
	users_in.close();
	users_out.close();
	remove("user_data.txt");
	rename("temp.txt", "user_data.txt");
}
void Change_user_type(User &user2)
{
	int choice;
	bool Flag = true;
	PrintingUsersList();
	do
	{
		cout << endl << endl << "\t\t Press Enter your choice : " << endl
			<< endl << "\t\t 1 - change player to premium" << endl
			<< endl << "\t\t 2 - change player to admin" << endl
			<< endl << "\t\t 3 - change premium player to player" << endl
			<< endl << "\t\t 4 - return " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			UserToPremium(user2);
			system("CLS");
			PrintingUsersList();
			break;
		case 2:

			break;
		case 3:
			PremiumToUser();
			system("CLS");
			PrintingUsersList();
			break;
		case 4:
			Flag = false;
			break;
		default:
			system("CLS");
			cout << endl << endl << "\t\tWrong Choice. Choose Again" << endl << endl;
			cout << "\t\tPress Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}

void UserToPremium(User &user2)
{
	string name;
	bool flag = true;
	do
	{
		cout << "\t\t enter the name of a player." << endl;
		cin >> name;
		if (Check_Name_Input_of_UserToPremium(name))
		{
			flag = false;
		}
		else
		{
			flag = true;
		}
	} while (flag);
	PremiumToUser();
	if (user2.if_premium==1)
	{
		user2.if_premium = 0;
	}
	ChangeUserToPremium(name);
	if (name == user2.name)
	{
		user2.if_premium = 1;
	}
}
void PremiumToUser()
{
	ifstream users_in;
	ofstream users_out;
	User temp;
	users_in.open("user_data.txt");
	users_out.open("temp.txt");
	while (!users_in.eof()) {
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		if (temp.if_premium)
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << temp.logins << endl;
			users_out << temp.if_manager << endl;
			users_out << 0;
			if (users_in.peek() != std::ifstream::traits_type::eof())
				users_out << endl;
		}
		else
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << temp.logins << endl;
			users_out << temp.if_manager << endl;
			users_out << temp.if_premium;
			if (users_in.peek() != std::ifstream::traits_type::eof())
				users_out << endl;
		}
	}
	users_in.close();
	users_out.close();
	remove("user_data.txt");
	rename("temp.txt", "user_data.txt");
}
void Excahnge_Type_With_Player(User &user1, User &user2)
{
	bool flag = false;
	string name;
	PrintingUsersList();
	do
	{
		cout << "\t\t enter the name of a player." << endl;
		cin >> name;
		if (Check_Name_Input_of_UserToPremium(name))
		{
			flag = false;
		}
		else
		{
			flag = true;
		}
	} while (flag);
	PremiumToUser();
	if (user2.if_premium == 1)
	{
		user2.if_premium = 0;
	}
	if (user1.if_premium == 1)
	{
		user1.if_premium = 0;
	}
	ChangeUserToPremium(name);
	if (name == user2.name)
	{
		user2.if_premium = 1;
	}
	if (name == user1.name)
	{
		user2.if_premium = 1;
	}
}

void Pre_Lost(User &pre, User &NewPre)
{
	PremiumToUser();
	if (pre.if_premium == 1)
	{
		pre.if_premium = 0;
	}
	ChangeUserToPremium(NewPre.name);
	NewPre.if_premium = 1;
}
