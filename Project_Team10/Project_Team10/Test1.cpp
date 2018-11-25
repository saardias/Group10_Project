#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void DataFilesWriteOnly(string file) {
	if (file == "War") {
		ofstream War;
		War.open("War.txt");
		War << "---------- War game Restructions below -----------" << endl;
		// we need to fill in the battle card restructions here << // 
		War.close();
	}
	if (file == "4InARow") {
		ofstream Row;
		Row.open("4 in a row.txt");
		Row << "---------- 4 in a Row game Restructions below -----------" << endl;
		// we need to fill in the 4 in a row restructions below << //
		Row.close();
	}
	if (file == "Snakes") {
		ofstream Snakes;
		Snakes.open("Snakes n' trails.txt");
		Snakes << "---------- Snakes n' trails game Restructions below -----------" << endl;
		// we need to fill in the Snakes 'n trails restructions below << //
		Snakes.close();
	}
}

void Restructions() {

	cout << "------------- Choose a game to view restruction game's comment -------------" << endl;
	cout << "1) for card battle fill in [War]." << endl << "2) for 4 in a row fill in [4InARow]." << endl << "3) for snakes n' trails fill in [Snakes]." << endl;
	string str;
	cout << "Please select your choise :";
	cin >> str;
	cout << "Game " << str << " Assigned" << endl;
	DataFilesWriteOnly(str);
}

void DataFilesReadOnly() {
	string Read;
	ifstream Snakes;
	Snakes.open("Snakes n' trails.txt");
	while (getline(Snakes, Read)) {
		Snakes >> Read;
	}
	cout << "The read file is : " << Read << endl;
	Snakes.close();
}

void GuideApply() {
	Restructions();
	DataFilesReadOnly();
}
