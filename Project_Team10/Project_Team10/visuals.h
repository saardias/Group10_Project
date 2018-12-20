#pragma once
#pragma once

#include <iostream>
#include <string>
#include "Structs.h"
#include "Header1.h"
#include <thread>
#include <chrono>
#include "Colors.h"

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

/*this file contain visual prints of items (like cards for example)*/

/* card shape 1:

		num

		  xx   xx
		 xxxx xxxx
		 xxxxxxxxx
		  xxxxxxx
		   xxxxx
			xxx
			 x

				num


 card shape 2:


		num

			 /\
			/  \
		   / /\ \
		   \ \/ /
			\  /
			 \/

				num


*/

void PrintCard(int num) {

	if (num % 2 == 0) {
		cout << "\n\t\t=================" << endl;

		if (num < 10) { cout << "\t\t||" << num << "   \t       ||" << endl; }
		else { cout << "\t\t||" << num << "   \t       ||" << endl; }
		cout << "\t\t||   xx   xx   ||" << endl;
		cout << "\t\t||  xxxx xxxx  ||" << endl;
		cout << "\t\t||  xxxxxxxxx  ||" << endl;
		cout << "\t\t||   xxxxxxx   ||" << endl;
		cout << "\t\t||    xxxxx    ||" << endl;
		cout << "\t\t||     xxx     ||" << endl;
		cout << "\t\t||      x      ||" << endl;
		if (num < 10) { cout << "\t\t||            " << num << "||" << endl; }
		else { cout << "\t\t||           " << num << "||" << endl; }
		cout << "\t\t=================" << endl;
	}
	if (num % 2 == 1) {
		cout << "\n\t\t=================" << endl;

		if (num < 10) { cout << "\t\t||" << num << "   \t       ||" << endl; }
		else { cout << "\t\t||" << num << "   \t       ||" << endl; }
		cout << "\t\t||     /\\      ||" << endl;
		cout << "\t\t||    //\\\\     ||" << endl;
		cout << "\t\t||   ///\\\\\\    ||" << endl;
		cout << "\t\t||   \\\\\\///    ||" << endl;
		cout << "\t\t||    \\\\//     ||" << endl;
		cout << "\t\t||     \\/      ||" << endl;
		if (num < 10) { cout << "\t\t||            " << num << "||" << endl; }
		else { cout << "\t\t||           " << num << "||" << endl; }
		cout << "\t\t=================" << endl;
	}
}
int RandomForSnakes() {
	//return random number 0<=rand<=12
	//used to take out rando card from user package
	unsigned int rand = time(NULL) % 1000;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	rand = rand * rand + 733;
	//rand = rand % 500;
	return rand;
}

/*************************************VISUALS FOR SNAKES***************************************/
SnakesBoard SetNewBoard() {

	SnakesBoard board;
	//set default start of 2 players
	board.U1_place = 1;
	board.U2_place = 1;
	//set laders to random value in range
	board.lader1 = RandomForSnakes() % 6 + 5;  //Range [5-10]
	board.lader2 = RandomForSnakes() % 3 + 21; //Range [21-23]
	board.lader3 = RandomForSnakes() % 4 + 44; //Range [44-47]
	board.lader4 = RandomForSnakes() % 4 + 67; //Range [67-70]
	board.lader5 = 85; //Range [85]
									   //set snakes to random value in range
	board.snake1 = RandomForSnakes() % 4 + 11;  //Range [11-14]
	board.snake2 = RandomForSnakes() % 4 + 34;  //Range [34-37]
	board.snake3 = RandomForSnakes() % 3 + 58;  //Range [58-60]
	board.snake4 = RandomForSnakes() % 3 + 61;   //Range [61-63]
	board.snake5 = RandomForSnakes() % 4 + 74;  //Range [74-77]
	board.snake6 = RandomForSnakes() % 4 + 91;   //Range [91-94]
	board.snake7 = RandomForSnakes() % 4 + 96;   //Range [96-99]
		/*try not to make sequance of laders
	while (board.lader1+10 == board.lader2) {
		board.lader1 = RandomForSnakes() % 10 + 1;  //Range [1-10]

	}
	while (board.lader2 + 10 == board.lader3) {
		board.lader2 = RandomForSnakes() % 10 + 11;  //Range [1-10]

	}


//check and fix if that there isnt snake and lader in the same spot
	while (board.snake1 == board.lader1+10|| board.snake1 == board.lader2 + 10) {
		board.snake1 = RandomForSnakes() % 20 + 11;  //new place in range

	}
	while (board.snake2 == board.lader3+10) {
		board.snake2 = RandomForSnakes() % 10 + 31;  //new place in range

	}
	while (board.snake3 == board.lader4+10) {
		board.snake3 = RandomForSnakes() % 25 + 41;  //new place in range

	}
	while (board.snake4 == board.lader4 + 10|| board.snake4 == board.lader5 + 10) {
		board.snake4 = RandomForSnakes() % 9 + 66;  //new place in range

	}
	while (board.snake5 == board.lader5+10) {
		board.snake5 = RandomForSnakes() % 16 + 75;  //new place in range

	}
	while (board.snake6 == board.lader5 + 10) {
		board.snake6 = RandomForSnakes() % 16 + 75;  //new place in range

	}
	*/

	return board;
}

/*
void PrintDown_Lader() { cout << "|__L__|"; }
void PrintDown_Snake() { cout << "|__S__|"; }
void PrintDown_Empty() { cout << "|_____|"; }

void PrintDown(int cube, SnakesBoard board) {
	if (cube == board.snake1 || cube == board.snake2 || cube == board.snake3 || cube == board.snake4 || cube == board.snake5 || cube == board.snake6 || cube == board.snake7) {
		PrintDown_Snake();
	}
	else if (cube == board.lader1 + 10 || cube == board.lader2 + 10 || cube == board.lader3 + 10 || cube == board.lader4 + 10 || cube == board.lader5 + 10) {

		PrintDown_Lader();
	}
	else { PrintDown_Empty(); }
}


void PrintUp_Lader() { cout << "|--L--|"; }
void PrintUp_Snake() { cout << "|--S--|"; }
void PrintUp_Empty() { cout << "|-----|"; }

void PrintUp(int cube, SnakesBoard board) {
	if (cube == board.snake1 - 10 || cube == board.snake2 - 10 || cube == board.snake3 - 10 || cube == board.snake4 - 10 || cube == board.snake5 - 10 || cube == board.snake6 - 10 || cube == board.snake7 - 10) {
		PrintUp_Snake();
	}
	else if (cube == board.lader1 || cube == board.lader2 || cube == board.lader3 || cube == board.lader4 || cube == board.lader5) {

		PrintUp_Lader();
	}
	else { PrintUp_Empty(); }
}


void PrintMiddle_U1()    { cout << "|U1   |"; }
void PrintMiddle_U2()    { cout << "|U2   |"; }
void PrintMiddle_U1_U2() { cout << "|U1&U2|"; }
void PrintMiddle_Empty() { cout << "|     |"; }
*/

void PrintDown_Lader() { 
	cout << "|__ ";
	ChangeColor(BROWN);
	cout << "H";
	ChangeColor(LIGHTGREY);
	cout << "_";
}
void PrintDown_Snake() { 
	cout << "|__ "; 
	ChangeColor(LIGHTGREEN);
	cout << "S";
	ChangeColor(LIGHTGREY);
	cout<<"_";
}
void PrintDown_Empty() { cout << "|_____"; }

void PrintDown(int cube, SnakesBoard board) {
	if (cube == board.snake1 || cube == board.snake2 || cube == board.snake3 || cube == board.snake4 || cube == board.snake5 || cube == board.snake6 || cube == board.snake7) {
		PrintDown_Snake();
	}
	else if (cube == board.lader1 + 10 || cube == board.lader2 + 10 || cube == board.lader3 + 10 || cube == board.lader4 + 10 || cube == board.lader5 + 10) {

		PrintDown_Lader();
	}
	else { PrintDown_Empty(); }
}

void PrintUp_Lader(int cube) {
	cout << "|" << cube;
	if (cube < 10) { cout << " "; }
	ChangeColor(BROWN);
	cout << " H ";
	ChangeColor(LIGHTGREY);

}

void PrintUp_Snake(int cube) {
	cout << "|" << cube;
	if (cube < 10) { cout << " "; }
	ChangeColor(LIGHTGREEN);
	cout << " S ";
	ChangeColor(LIGHTGREY);
}
void PrintUp_Empty(int cube) {
	cout << "|" << cube;
	if (cube < 10) { cout << " "; }
	if (cube == 100) {
		cout << "  ";
	}

	if (cube < 100) {
		cout << "   ";
	}
}

void PrintUp(int cube, SnakesBoard board) {
	if (cube == board.snake1 - 10 || cube == board.snake2 - 10 || cube == board.snake3 - 10 || cube == board.snake4 - 10 || cube == board.snake5 - 10 || cube == board.snake6 - 10 || cube == board.snake7 - 10) {
		PrintUp_Snake(cube);
	}
	else if (cube == board.lader1 || cube == board.lader2 || cube == board.lader3 || cube == board.lader4 || cube == board.lader5) {

		PrintUp_Lader(cube);
	}
	else { PrintUp_Empty(cube); }
}


void PrintMiddle_U1() {
	cout << "|";
	ChangeColor(LIGHTBLUE);
	cout << "U1   ";
	ChangeColor(LIGHTGREY);
}
void PrintMiddle_U2() { 
	ChangeColor(LIGHTRED);
	cout << "|";
	cout << "U2   "; 
	ChangeColor(LIGHTGREY);
}
void PrintMiddle_U1_U2() { 
	cout << "|";
	ChangeColor(LIGHTBLUE);
	cout << "U1";
	ChangeColor(LIGHTGREY);
	cout << " ";
	ChangeColor(LIGHTRED);
	cout << "U2";
	ChangeColor(LIGHTGREY);
}
void PrintMiddle_Empty() { cout << "|     "; }


void PrintMiddle(int cube, SnakesBoard board) {
	if (cube == board.U1_place&&cube == board.U2_place) {
		PrintMiddle_U1_U2();

	}
	if (cube == board.U1_place&&cube != board.U2_place) {

		PrintMiddle_U1();
	}
	if (cube != board.U1_place&&cube == board.U2_place) {

		PrintMiddle_U2();
	}
	if (cube != board.U1_place&&cube != board.U2_place) {
		PrintMiddle_Empty();
	}
}


void PrintSnakesBoard(SnakesBoard board) {
	//print top outline
	cout << " "; for (int i = 0; i < 10; i++) { cout << "______"; } cout << endl;

	//run on each row from the top of the board
	for (int row = 91; row >= 0; row -= 10) {
		for (int i = 0; i < 10; i++) { PrintUp(row + i, board); }		cout << "|" << endl;

		for (int i = 0; i < 10; i++) { PrintMiddle(row + i, board); }     cout << "|" << endl;

		for (int i = 0; i < 10; i++) { PrintDown(row + i, board); }       cout << "|" << endl;


	}
}

