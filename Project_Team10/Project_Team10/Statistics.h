#pragma once
#include <iostream>
#include <fstream>
#include "1.Sign_in_modules.h"
#include "Structs.h"
using namespace std;


void delete_player(string name);

//the function below updates the new statistic records of the winner and the defeated users especially made for Snakes and Ladders game.
void Set_Snakes_And_Ladders_Statistics(string Winner,string Looser) { 
	bool flag1 = false, flag2 = false;
	int number = 0;
	ifstream Set;
	ofstream Update;
	string Claim;
	Set.open("Snakes and Ladders Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if ((flag1 == false && flag2 == false) || (flag1 == false && flag2 == true && Claim[0] != 'L')) { // this if condition will allow going forth to claim and edit data from the file.
			Update << Claim << endl;
		}
		else if (flag1 == true) { // this if condition will change the Win rate Statistics for the winner user in this condition.//
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'W' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					for (int j = i + 1; Claim[j] != '\0'; j++) {
						number *= 10;
						number += Claim[j] - 48;
						if (Claim[j + 1] == '\0') {
							number += 1;
						}
						else {
							continue;
						}
					}
					Update << "Win rate :" << number << endl;
					number = 0;
					break;
				}
			}
			flag1 = false;
		}
		else if (flag2 == true) { // this if condition will change the Lose rate Statistics for the loosing user in this condition. //
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'L' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					for (int j = i + 1; Claim[j] != '\0'; j++) {
						number *= 10;
						number += Claim[j] - 48;
						if (Claim[j + 1] == '\0') {
							number += 1;
						}
						else {
							continue;
						}
					}
					Update << "Lose rate :" << number << endl;
					number = 0;
					break;
				}
			}
			flag2 = false;
		}
		if (Claim == Winner) { // checking if the winner's name applied
			flag1 = true;
		}
		if (Claim == Looser) { // checking if the loosing user's name applied
			flag2 = true;
		}
	}
	Update.close();
	Set.close();
	remove("Snakes and Ladders Statistics.txt");
	rename("temp.txt", "Snakes and Ladders Statistics.txt");
}

//the function below updates the new statistic records of the winner and the defeated users especially made for Connect Four game.
void Set_Connect_Four_Statistics(string Winner, string Looser) {
	bool flag1 = false, flag2 = false;
	int number = 0;
	ifstream Set;
	ofstream Update;
	string Claim;
	Set.open("Connect Four Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if ((flag1 == false && flag2 == false) || (flag1 == false && flag2 == true && Claim[0] != 'L')) { // this if condition will allow going forth to claim and edit data from the file.
			Update << Claim << endl;
		}
		else if (flag1 == true) { // this if condition will change the Win rate Statistics for the winner user in this condition.//
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'W' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					for (int j = i + 1; Claim[j] != '\0'; j++) {
						number *= 10;
						number += Claim[j] - 48;
						if (Claim[j + 1] == '\0') {
							number += 1;
						}
						else {
							continue;
						}
					}
					Update << "Win rate :" << number << endl;
					number = 0;
					break;
				}
			}
			flag1 = false;
		}
		else if (flag2 == true) { // this if condition will change the Lose rate Statistics for the loosing user in this condition. //
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'L' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					for (int j = i + 1; Claim[j] != '\0'; j++) {
						number *= 10;
						number += Claim[j] - 48;
						if (Claim[j + 1] == '\0') {
							number += 1;
						}
						else {
							continue;
						}
					}
					Update << "Lose rate :" << number << endl;
					number = 0;
					break;
				}
			}
			flag2 = false;
		}
		if (Claim == Winner) { // checking if the winner's name applied
			flag1 = true;
		}
		if (Claim == Looser) { // checking if the loosing user's name applied
			flag2 = true;
		}
	}
	Update.close();
	Set.close();
	remove("Connect Four Statistics.txt");
	rename("temp.txt", "Connect Four Statistics.txt");
}

//the function below updates the new statistic records of the winner and the defeated users especially made for Cards game.
void Set_Cards_Battle_Statistics(string Winner, string Looser) {
	bool flag1 = false, flag2 = false;
	int number = 0;
	ifstream Set;
	ofstream Update;
	string Claim;
	Set.open("Cards Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if ((flag1 == false && flag2 == false) || (flag1 == false && flag2 == true && Claim[0] != 'L')) { // this if condition will allow going forth to claim and edit data from the file.
			Update << Claim << endl;
		}
		else if (flag1 == true) { // this if condition will change the Win rate Statistics for the winner user in this condition.//
			for (int i = 0; i < sizeof(Claim); i++) {
				if((Claim[0] == 'W' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)){
					for (int j = i + 1; Claim[j] != '\0'; j++) {
						number *= 10;
						number += Claim[j]-48;
						if (Claim[j + 1] == '\0') {
							number += 1;
						}
						else {
							continue;
						}
					}
					Update <<"Win rate :" << number << endl;
					number = 0;
					break;
				}
			}
			flag1 = false;
		}
		else if (flag2 == true) { // this if condition will change the Lose rate Statistics for the loosing user in this condition. //
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'L' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					for (int j = i + 1; Claim[j] != '\0'; j++) {
						number *= 10;
						number += Claim[j] - 48;
						if (Claim[j + 1] == '\0') {
							number += 1;
						}
						else {
							continue;
						}
					}
					Update << "Lose rate :" << number << endl;
					number = 0;
					break;
				}
			}
			flag2 = false;
		}
		if(Claim == Winner){ // checking if the winner's name applied
			flag1 = true;
		}
		if (Claim == Looser) { // checking if the loosing user's name applied
			flag2 = true;
		}
	}
	Update.close();
	Set.close();
	remove("Cards Statistics.txt");
	rename("temp.txt", "Cards Statistics.txt");
}

//this function will display the game statistics when ever being called in the main menu.
//the function recieves the name of the game chosen and then displays it's statistics.
void Display_Statistics(string Game) {
	cout << "----------------------------------------------------" << endl;
	cout << "******************** Statistics ********************" << endl << endl << endl;
	ifstream Display;
	string Claim;
	if (Game == "Connect Four") {
		Display.open("Connect Four Statistics.txt");
		while (getline(Display, Claim)) {
			cout << Claim << endl;
		}
	}
	else if (Game == "Snakes and Ladders") {
		Display.open("Snakes and Ladders Statistics.txt");
		while (getline(Display, Claim)) {
			cout << Claim << endl;
		}
	}
	else if (Game == "War") {
		Display.open("Cards Statistics.txt");
		while (getline(Display, Claim)) {
			cout << Claim << endl;
		}
	}
	Display.close();
	cout << endl << endl << endl << "----------------------------------------------------" << endl;
	cout << "       Press Enter to Continue" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

void Master_Statistics_Reset(string User) { // function for master usage only //
	bool flag1 = false, flag2 = false, flag = false;
	ifstream Set;
	ofstream Update;
	string Claim;
	Set.open("Snakes and Ladders Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (flag1 == true) { // this if condition will change the Win rate Statistics for the winner user in this condition.//
			Update << "Win rate :0" << endl;
			flag1 = false;
			flag = true;
		}
		else if (flag2 == true) {
			Update << "Lose rate :0" << endl;
			flag2 = false;
		}
		else
			Update << Claim << endl;
		if (Claim == User) { // checking if the winner's name applied
			flag1 = true;
		}
		if (flag == true) {
			flag2 = true;
			flag = false;
		}
	}
	Update.close();
	Set.close();
	remove("Snakes and Ladders Statistics.txt");
	rename("temp.txt", "Snakes and Ladders Statistics.txt");
	Set.open("Connect Four Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (flag1 == true) { // this if condition will change the Win rate Statistics for the winner user in this condition.//
			Update << "Win rate :0" << endl;
			flag1 = false;
			flag = true;
		}
		else if (flag2 == true) {
			Update << "Lose rate :0" << endl;
			flag2 = false;
		}
		else
			Update << Claim << endl;
		if (Claim == User) { // checking if the winner's name applied
			flag1 = true;
		}
		if (flag == true) {
			flag2 = true;
			flag = false;
		}
	}
	Update.close();
	Set.close();
	remove("Connect Four Statistics.txt");
	rename("temp.txt", "Connect Four Statistics.txt");
	Set.open("Cards Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (flag1 == true) { // this if condition will change the Win rate Statistics for the winner user in this condition.//
			Update << "Win rate :0" << endl;
			flag1 = false;
			flag = true;
		}
		else if (flag2 == true) {
			Update << "Lose rate :0" << endl;
			flag2 = false;
		}
		else
			Update << Claim << endl;
		if (Claim == User) { // checking if the winner's name applied
			flag1 = true;
		}
		if (flag == true) {
			flag2 = true;
			flag = false;
		}
	}
	Update.close();
	Set.close();
	remove("Cards Statistics.txt");
	rename("temp.txt", "Cards Statistics.txt");
}

void Data_Base_User_Additional(string User) { // adding a new user to the statistic list data base // 
	ifstream Set;
	ofstream Update;
	string Claim;
	Set.open("Snakes and Ladders Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		Update << Claim << endl;
	}
	Update << User << endl << "Win rate :0" << endl << "Lose rate :0" << endl;
	Set.close();
	Update.close();
	remove("Snakes and Ladders Statistics.txt");
	rename("temp.txt", "Snakes and Ladders Statistics.txt");
	Set.open("Connect Four Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		Update << Claim << endl;
	}
	Update << User << endl << "Win rate :0" << endl << "Lose rate :0" << endl;
	Set.close();
	Update.close();
	remove("Connect Four Statistics.txt");
	rename("temp.txt", "Connect Four Statistics.txt");
	Set.open("Cards Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		Update << Claim << endl;
	}
	Update << User << endl << "Win rate :0" << endl << "Lose rate :0" << endl;
	Set.close();
	Update.close();
	remove("Cards Statistics.txt");
	rename("temp.txt", "Cards Statistics.txt");
}

void Data_Base_User_Removal(string User) { // removing/deleting a user from the statistic list data base //
	bool flag1 = false, flag2 = false, flag3 = false;
	ifstream Set;
	ofstream Update;
	string Claim;
	Set.open("Snakes and Ladders Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (flag1 == true && flag2 == true && flag3 == true) {
			flag1 = false;
			flag2 = false;
			flag3 = false;
		}
		if (flag2 == true)
			flag3 = true;
		if (flag1 == true)
			flag2 = true;
		if (Claim == User)
			flag1 = true;
		if (flag1 == false && flag2 == false && flag3 == false) {
			Update << Claim << endl;
		}
		else
			continue;
	}
	Set.close();
	Update.close();
	remove("Snakes and Ladders Statistics.txt");
	rename("temp.txt", "Snakes and Ladders Statistics.txt");
	Set.open("Connect Four Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (flag1 == true && flag2 == true && flag3 == true) {
			flag1 = false;
			flag2 = false;
			flag3 = false;
		}
		if (flag2 == true)
			flag3 = true;
		if (flag1 == true)
			flag2 = true;
		if (Claim == User)
			flag1 = true;
		if (flag1 == false && flag2 == false && flag3 == false) {
			Update << Claim << endl;
		}
		else
			continue;
	}
	Set.close();
	Update.close();
	remove("Connect Four Statistics.txt");
	rename("temp.txt", "Connect Four Statistics.txt");
	Set.open("Cards Statistics.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (flag1 == true && flag2 == true && flag3 == true) {
			flag1 = false;
			flag2 = false;
			flag3 = false;
		}
		if (flag2 == true)
			flag3 = true;
		if (flag1 == true)
			flag2 = true;
		if (Claim == User)
			flag1 = true;
		if (flag1 == false && flag2 == false && flag3 == false) {
			Update << Claim << endl;
		}
		else
			continue;
	}
	Set.close();
	Update.close();
	remove("Cards Statistics.txt");
	rename("temp.txt", "Cards Statistics.txt");
}
// a display function display personal statistic , statistics being printed by user's in game name. //
void Display_Personal_User_Statistics(string User) { 
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "     \t    ******************** " << User << "'s Personal  Statistics ********************" << endl << endl;
	ifstream Display;
	string Claim;
	bool flag1 = false, flag2 = false;
	Display.open("Snakes and Ladders Statistics.txt");
	cout << "\t\t ________________________________________________________" << endl;
	cout << "\t\t|\t\t Game : Snakes and Ladders.\t\t |" << endl;
	cout << "\t\t|\t\t\t\t\t\t\t |" << endl;
	while (getline(Display, Claim)) {
		if (flag2 == true) {
			cout << "\t\t" << Claim << "\t |" << endl; // will display Lose rate :*
			flag1 = false;
			flag2 = false;
			break;
		}
		if (flag1 == true) {
			cout << "\t\t|\t" << Claim << "\t "; // will display Win rate :*
			flag2 = true;
		}
		if (Claim == User) {
			flag1 = true;
		}
	}
	Display.close();
	cout << "\t\t|\t\t\t\t\t\t\t |";
	cout << endl << "\t\t|________________________________________________________|" << endl;
	Display.open("Connect Four Statistics.txt");
	cout << "\t\t| \t\t Game : Connect Four.   \t\t |" << endl;
	cout << "\t\t|\t\t\t\t\t\t\t |" << endl;
	while (getline(Display, Claim)) {
		if (flag2 == true) {
			cout << "\t\t" << Claim << "\t |" << endl; // will display Lose rate :*
			flag1 = false;
			flag2 = false;
			break;
		}
		if (flag1 == true) {
			cout << "\t\t|\t" << Claim << "\t "; // will display Win rate :*
			flag2 = true;
		}
		if (Claim == User) {
			flag1 = true;
		}
	}
	Display.close();
	cout << "\t\t|\t\t\t\t\t\t\t |";
	cout << endl << "\t\t|________________________________________________________|" << endl;
	Display.open("Cards Statistics.txt");
	cout <<  "\t\t| \t\t Game : Cards Battle.   \t\t |" << endl;
	cout << "\t\t|\t\t\t\t\t\t\t |" << endl;
	while (getline(Display, Claim)) {
		if (flag2 == true) {
			cout << "\t\t" << Claim << "\t |" << endl; // will display Lose rate :*
			flag1 = false;
			flag2 = false;
			break;
		}
		if (flag1 == true) {
			cout << "\t\t|\t" << Claim << "\t "; // will display Win rate :*
			flag2 = true;
		}
		if (Claim == User) {
			flag1 = true;
		}
	}
	Display.close();
	cout << "\t\t|\t\t\t\t\t\t\t |";
	cout << endl << "\t\t|________________________________________________________|" << endl << endl << endl;
	
}

// display list of all users in system
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
//checking input of users name
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
// function that display statistic of all games
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
// function that display logins number of all users
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
// reset login data of a user
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
// reset data of a user
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
		cout << "\t\t enter the name of a player to reset his stats. 'exit' to return" << endl;
		cin >> name;
		if (name == "exit")
		{
			flag = false;
		}
		else if (Check_Name_Input(name))
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
// deleting user from system
void DeletePlayerFromData(User &user1, User &user2)
{
	bool flag = false;
	string name;
	PrintingUsersList();
	do
	{
		cout << "\t\t enter name of a player to delete from system . 'exit' to return" << endl;
		cin >> name;
		if (name == "exit")
		{
			flag = false;
		}
		else if (name == user1.name || name == user2.name)
		{
			cout << "\t\t Can't delete connected users !" << endl;
			flag = true;
		}
		else if (Check_Name_Input(name))
		{
			delete_player(name);
			Data_Base_User_Removal(name);
			flag = false;
		}
		else
		{
			cout << "\t\t Name Does not exist !" << endl;
			flag = true;
		}
	} while (flag);
}