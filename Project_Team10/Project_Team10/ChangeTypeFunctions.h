#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Structs.h"
#include "Statistics.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


void Pre_Lost(User &pre, User &NewPre);
void UserToAdmin(User &user1, User &user2);
void UserToPremium(User &user2);
void PremiumToUser();
void Change_user_type(User &user1, User &user2);
bool Check_Name_Input_of_UserToPremium(string name);
void ChangeUserToPremium(string name);
void Excahnge_Type_With_Player(User &user1, User &user2);

// in case premium use lost  
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
// changing  user to admin
void UserToAdmin(User &user1, User &user2)
{
	string name;
	bool flag = true;
	do
	{
		cout << "\t\t enter the name of a player. 'exit' - to return" << endl;
		cin >> name;
		if (name == "exit")
		{
			system("CLS");
			flag = false;
		}
		else
		{
			make_admin(name, user1, user2);
			system("CLS");
			PrintingUsersList();
		}
	} while (flag);
	PrintingUsersList();
}
// changing  premium to player
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
// changing user to premium (menu)
void UserToPremium(User &user2)
{
	string name;
	bool flag = true;
	do
	{
		cout << "\t\t enter the name of a player. 'exit' - return" << endl;
		cin >> name;
		if (name == "exit")
		{
			flag = false;
		}
		else
		{
			if (Check_Name_Input_of_UserToPremium(name))
			{
				flag = false;
			}
			else
			{
				flag = true;
			}
		}
	} while (flag);
	PremiumToUser();
	if (user2.if_premium == 1)
	{
		user2.if_premium = 0;
	}
	ChangeUserToPremium(name);
	if (name == user2.name)
	{
		user2.if_premium = 1;
	}
}
// menu for admin - changing users type
void Change_user_type(User &user1, User &user2)
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
			UserToAdmin(user1, user2);
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
// checing input of name in usertopremium function
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
		if (name == temp.name && (temp.if_manager == 1 || temp.if_premium == 1))
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
// changing  user to premium 
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
// Excahnging between player to premium
void Excahnge_Type_With_Player(User &user1, User &user2)
{
	bool flag = false;
	string name;
	PrintingUsersList();
	do
	{
		cout << "\t\t enter the name of a player. 'exit' to return" << endl;
		cin >> name;
		if (name == "exit")
		{
			flag = false;
		}
		else
		{
			if (Check_Name_Input_of_UserToPremium(name))
			{
				flag = false;
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
			else
			{
				flag = true;
			}
		}
	} while (flag);
}