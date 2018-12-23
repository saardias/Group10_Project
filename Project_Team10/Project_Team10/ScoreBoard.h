#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Structs.h"
using namespace std;

void Set_Snakes_And_Ladders_Score_Board(string name, int score) {
	bool flag1 = false, flag2 = false;
	ifstream Set;
	ofstream Update;
	string Claim, *Temp = new string[5], Holder, Name = name;
	int Register = 0, BubbleSort = 0, Score = score, *temp = new int[5], i = 0;
	Set.open("Snakes and Ladders Score Board.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (Claim[0] < 48 || Claim[0] > 57) {
			Temp[i] = Claim;
		}
		if (Claim[0] > 47 && Claim[0] < 58) {
			for (int i = 0; Claim[i] != '\0'; i++) {
				Register *= 10;
				Register += Claim[i] - 48;
			}
			temp[i] = Register;
			i++;
			Register = 0;
		}
	}
	for (int i = 0; i < 5; i++) {
		if ((Score > temp[i] && name != Temp[0] && name != Temp[1] && name != Temp[2] && name != Temp[3] && name != Temp[4]) || (flag1 == true)) {
			BubbleSort = temp[i];
			temp[i] = Score;
			Score = BubbleSort;
			Holder = Temp[i];
			Temp[i] = Name;
			Name = Holder;
			flag1 = true;
		}
		else if (Score > temp[i] && Temp[i] == name) {
			temp[i] = Score;
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		Update << Temp[i] << endl << temp[i] << endl;
	}
	delete[] Temp;
	delete[] temp;
	Update.close();
	Set.close();
	remove("Snakes and Ladders Score Board.txt");
	rename("temp.txt", "Snakes and Ladders Score Board.txt");
}

void Set_Connect_Four_Score_Board(string name, int score) {
	bool flag1 = false, flag2 = false;
	ifstream Set;
	ofstream Update;
	string Claim, *Temp = new string[5], Holder, Name = name;
	int Register = 0, BubbleSort = 0, Score = score, *temp = new int[5], i = 0;
	Set.open("Connect Four Score Board.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (Claim[0] < 48 || Claim[0] > 57) {
			Temp[i] = Claim;
		}
		if (Claim[0] > 47 && Claim[0] < 58) {
			for (int i = 0; Claim[i] != '\0'; i++) {
				Register *= 10;
				Register += Claim[i] - 48;
			}
			temp[i] = Register;
			i++;
			Register = 0;
		}
	}
	for (int i = 0; i < 5; i++) {
		if ((Score > temp[i] && name != Temp[0] && name != Temp[1] && name != Temp[2] && name != Temp[3] && name != Temp[4]) || (flag1 == true)) {
			BubbleSort = temp[i];
			temp[i] = Score;
			Score = BubbleSort;
			Holder = Temp[i];
			Temp[i] = Name;
			Name = Holder;
			flag1 = true;
		}
		else if (Score > temp[i] && Temp[i] == name) {
			temp[i] = Score;
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		Update << Temp[i] << endl << temp[i] << endl;
	}
	delete[] Temp;
	delete[] temp;
	Update.close();
	Set.close();
	remove("Connect Four Score Board.txt");
	rename("temp.txt", "Connect Four Score Board.txt");
}

void Set_Cards_Score_Board(string name, int score) {
	bool flag1 = false, flag2 = false;
	ifstream Set;
	ofstream Update;
	string Claim, *Temp = new string[5], Holder, Name = name;
	int Register = 0, BubbleSort=0,Score=score, *temp = new int[5], i = 0;
	Set.open("Cards Score Board.txt");
	Update.open("temp.txt");
	while (getline(Set, Claim)) {
		if (Claim[0] < 48 || Claim[0] > 57) {
			Temp[i] = Claim;
		}
		if (Claim[0] > 47 && Claim[0] < 58) {
			for (int i = 0; Claim[i] != '\0'; i++) {
				Register *= 10;
				Register += Claim[i] - 48;
			}
			temp[i] = Register;
			i++;
			Register = 0;
		}
	}
	for (int i = 0; i < 5; i++) {
		if ((Score > temp[i] && name != Temp[0] && name != Temp[1] && name != Temp[2] && name != Temp[3] && name != Temp[4])||(flag1 == true)) {
			BubbleSort = temp[i];
			temp[i] = Score;
			Score = BubbleSort;
			Holder = Temp[i];
			Temp[i] = Name;
			Name = Holder;
			flag1 = true;
		}
		else if (Score > temp[i] && Temp[i] == name) {
			temp[i] = Score;
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		Update << Temp[i] << endl << temp[i] << endl;
	}
	delete[] Temp;
	delete[] temp;
	Update.close();
	Set.close();
	remove("Cards Score Board.txt");
	rename("temp.txt", "Cards Score Board.txt");
}

void Display_Game_Score_Board(string Game){
	int flag1 = false, flag2 = false;
	ifstream Display;
	string Claim;
	cout << endl;
	cout << endl << "\t\t ________________________________________________________" << endl;
	if (Game == "Connect Four") {
		cout << "\t\t|\t\t\tConnect Four    \t\t |";
		cout << endl << "\t\t|________________________________________________________|" << endl;
		Display.open("Connect Four Score Board.txt");
		while (getline(Display, Claim)) {
			if (flag1 == true) {
				cout << "\t ~ ~ ~ ~ ~ \tScore :" << Claim << "\t |"<< endl;
				flag2 = true;
			}
			if (flag1 == false) {
				cout << "\t\t|\t\t" << Claim;
				flag1 = true;
			}
			if (flag1 == true && flag2 == true) {
				flag1 = false;
				flag2 = false;
			}
		}
	}
	else if (Game == "Snakes and Ladders") {
		cout << "\t\t|\t\t   Snakes and Ladders   \t\t |";
		cout << endl << "\t\t|________________________________________________________|" << endl;
		Display.open("Snakes and Ladders Score Board.txt");
		while (getline(Display, Claim)) {
			if (flag1 == true) {
				cout << "\t ~ ~ ~ ~ ~ \tScore :" << Claim << "\t |" << endl;
				flag2 = true;
			}
			if (flag1 == false) {
				cout << "\t\t|\t\t" << Claim;
				flag1 = true;
			}
			if (flag1 == true && flag2 == true) {
				flag1 = false;
				flag2 = false;
			}
		}
	}
	else if (Game == "War") {
		cout << "\t\t|\t\t\tCards Battle    \t\t |";
		cout << endl << "\t\t|________________________________________________________|" << endl;
		Display.open("Cards Score Board.txt");
		while (getline(Display, Claim)) {
			if (flag1 == true) {
				cout << "\t ~ ~ ~ ~ ~ \tScore :" << Claim << "\t |" << endl;
				flag2 = true;
			}
			if (flag1 == false) {
				cout << "\t\t|\t\t" << Claim;
				flag1 = true;
			}
			if (flag1 == true && flag2 == true) {
				flag1 = false;
				flag2 = false;
			}
		}
	}
	Display.close();
	cout << "\t\t|________________________________________________________|" << endl << endl << endl;

}

int main() {
	Set_Cards_Score_Board("yana", 96);
	Display_Game_Score_Board("Snakes and Ladders");
	system("PAUSE");
	return 0;
}
