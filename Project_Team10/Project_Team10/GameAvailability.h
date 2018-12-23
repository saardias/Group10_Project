#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Set_Game_Run_Count(string Game) {
	bool flag = false;
	ifstream Check;
	ofstream Set;
	string Claim;
	Set.open("temp.txt");
	if (Game == "Connect Four") {
		Check.open("Connect Four Availability.txt");
		while (getline(Check, Claim)) {
			if (flag == true) {
				for(int i=0; i< sizeof(Claim); i++){
					Claim[i] += 1;
				}
				Set << Claim << endl;
				break;
			}
			if (Claim[0] == 'A') {
				Set << Claim << endl;
				flag = true;
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
				for (int i = 0; i < sizeof(Claim); i++) {
					Claim[i] += 1;
				}
				Set << Claim << endl;
				break;
			}
			if (Claim[0] == 'A') {
				Set << Claim << endl;
				flag = true;
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
				for (int i = 0; i < sizeof(Claim); i++) {
					Claim[i] += 1;
					break;
				}
				Set << Claim << endl;
				break;
			}
			if (Claim[0] == 'A') {
				Set << Claim << endl;
				flag = true;
			}
		}
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