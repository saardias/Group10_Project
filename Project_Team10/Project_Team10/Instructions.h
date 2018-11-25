#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//this function is reading the Data from the files and applying a menu of the instructions of the chosen game. //
void DataFilesReadOnly(string Data) {
	string Read;
	if (Data == "Snakes and Ladders") {
		ifstream Snakes;
		Snakes.open("Snakes and Ladders.txt");
		while (getline(Snakes, Read)) {
			cout << Read << endl;
		}
		Snakes.close();
	}
	if (Data == "War") {
		ifstream War;
		War.open("War.txt");
		while (getline(War, Read)) {
			cout << Read << endl;
		}
		War.close();
	}
	if (Data == "Connect Four") {
		ifstream Row;
		Row.open("Connect Four.txt");
		while (getline(Row, Read)) {
			cout << Read << endl;
		}
		Row.close();
	}
	cout << "       Press Enter to Continue" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}
