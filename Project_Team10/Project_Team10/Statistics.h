#pragma once
#include <iostream>
//#include <string>
#include <fstream>
#include "Structs.h"
using namespace std;

//the function below updates the new statistic records of the winner and the defeated users especially made for Snakes and Ladders game.
void Set_Snakes_And_Ladders_Statistics(string Winner,string Looser) { 
	bool flag1 = false, flag2 = false;
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
					Claim[i + 1] += 1;
					Update << Claim << endl;
					break;
				}
			}
			flag1 = false;
		}
		else if (flag2 == true) { // this if condition will change the Lose rate Statistics for the loosing user in this condition. //
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'L' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					Claim[i + 1] += 1;
					Update << Claim << endl;
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
					Claim[i + 1] += 1;
					Update << Claim << endl;
					break;
				}
			}
			flag1 = false;
		}
		else if (flag2 == true) { // this if condition will change the Lose rate Statistics for the loosing user in this condition. //
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'L' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					Claim[i + 1] += 1;
					Update << Claim << endl;
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
					Claim[i + 1] += 1;
					Update << Claim << endl;
					break;
				}
			}
			flag1 = false;
		}
		else if (flag2 == true) { // this if condition will change the Lose rate Statistics for the loosing user in this condition. //
			for (int i = 0; i < sizeof(Claim); i++) {
				if ((Claim[0] == 'L' && Claim[i] == ':') && (Claim[i + 1] > 47 && Claim[i + 1] < 58)) {
					Claim[i + 1] += 1;
					Update << Claim << endl;
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
