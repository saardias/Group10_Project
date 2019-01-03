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