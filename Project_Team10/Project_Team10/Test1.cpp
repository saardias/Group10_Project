#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// this functions may be used only once!!! * , the function below create three instruction files of the games.//
void DataFilesWriteOnly() {
	ofstream War, Row, Snakes;
	War.open("War.txt");
	Row.open("4 in a row.txt");
	Snakes.open("Snakes n' trails.txt");
	Row << "---------- 4 in a Row game Instructions below -----------" << endl;
	// we need to fill in the 4 in a row restructions below << //
	War << "---------- War game Instructions below -----------" << endl;
	// we need to fill in the battle card restructions here << //
	Snakes << "---------- Snakes n' trails game Instructions below -----------" << endl;
	// we need to fill in the Snakes 'n trails restructions below << //
	Snakes.close();
	War.close();
	Row.close();
}

//this function is reading the Data from the files and applying a menu of the instructions of the chosen game. //
void DataFilesReadOnly(string Data) {
	string Read;
	if (Data == "Snakes") {
		ifstream Snakes;
		Snakes.open("Snakes n' trails.txt");
		while (getline(Snakes, Read)) {
			Snakes >> Read;
		}
		Snakes.close();
	}
	if (Data == "War") {
		ifstream War;
		War.open("War.txt");
		while (getline(War, Read)) {
			War >> Read;
		}
		War.close();
	}
	if (Data == "4InARow") {
		ifstream Row;
		Row.open("4 in a row.txt");
		while (getline(Row, Read)) {
			Row >> Read;
		}
		Row.close();
	}
	cout << "The read file is : " << Read << endl;
}

void Instructions() { // instructions function re-creates a data from the user to choose a game-instruction from the menu below.

	cout << "------------- Choose a game to view instruction game's comment -------------" << endl;
	cout << "1) for card battle fill in [War]." << endl << "2) for 4 in a row fill in [4InARow]." << endl << "3) for snakes n' trails fill in [Snakes]." << endl;
	string str;
	cout << "Please select your choise :";
	cin >> str;
	cout << "Game " << str << " Assigned" << endl;
	DataFilesWriteOnly(); //this command line may be used only once! noted.//
	DataFilesReadOnly(str);
}

void Apply() { // this function begin the proccesing.//
	Instructions();
}
