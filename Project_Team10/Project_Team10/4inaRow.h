#pragma once
#include <time.h>
#include "Colors.h"
#include <iostream>
#include <stdlib.h>
#include "Statistics.h"
#include "MainManu.h"
#define BoardLength 6
#define Boardhwidth 7
#define Win 4

void Pre_Lost(User &pre, User &NewPre);

typedef enum {
	space = ' ', red = 'r', blue = 'b',stone='s'
}Cell;

typedef struct {
	int length = BoardLength, width = Boardhwidth; // size
	Cell **surface; // table view
}Board;
int UserChoice(User player,Board *board);

bool PauseManu()
{
	int Choice;
	bool Flag = true;
	do
	{
		system("CLS");
		cout << endl << endl << "       ####     P A U S E     ####    " << endl << endl;
		cout <<
			"        1 ) Back to game " << endl << endl <<
			"        2 ) Exit" << endl << endl <<
			"       ###################################" << endl;
		cin >> Choice;
		getchar();
		switch (Choice)
		{
		case 1:
			return false;
			break;
		case 2:
			return true;
			break;
		default:
			system("CLS");
			cout << endl << endl << "       Wrong Choice. Choose Again" << endl << endl;
			cout << "       Press Enter to Continue" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
	} while (Flag);
}
int RandomCol() {
	//return random number 1<=rand<=7
	//used to take out rando card from user package
	unsigned int rand = time(NULL) % 1000;

	rand = rand % 7+1;
	return rand;
}
void Winner_point(User &Winner, User &losser, int passed_turns)
{
	int winner_points = 0;
	winner_points = 1000 - (25 * passed_turns);
	cout << "       with " << winner_points << " points" << endl << "       after " << passed_turns << " turns" << endl;
	Set_Connect_Four_Statistics(Winner.name, losser.name);
	if (losser.if_premium == 1)
	{
		Pre_Lost(losser, Winner);
	}
	// add update datas here
}
void PrintBoard(Board *board) //method for printing the board
{
	system("CLS");
	//first printing the top line of the matrix and numbering the column
	for (int i = 0; i < board->width; i++)
	{
		cout << "| " << i + 1 << "  ";
	}
	cout << "|" << endl;
	for (int i = 0; i < board->width; i++)
	{
		cout << "_____";
	}
	cout << endl;
	// printing the lines of the board while cheking each value of cell 
	for (int i = 0; i < board->length; i++)
	{
		for (int j = 0; j < board->width; j++)
		{
			if (board->surface[i][j] == red) //in case the cell is red 
			{
				cout << "| ";
				ChangeColor(LIGHTRED);
				cout << (char)254 << "  ";
				ChangeColor(LIGHTGREY);
			}
			else if (board->surface[i][j] == blue) //in case the cell is blue 
			{
				cout << "| ";
				ChangeColor(LIGHTBLUE);
				cout << (char)254 << "  ";
				ChangeColor(LIGHTGREY);
			}
			else if (board->surface[i][j] == stone) //in case the cell is white
			{
				cout << "| ";
				ChangeColor(WHITE);
				cout << (char)254 << "  ";
				ChangeColor(LIGHTGREY);
			}
			else if (board->surface[i][j] == space) //in case the cell is empty 
			{
				cout << "| ";
				cout << " " << "  ";
			}
		}
		cout << "|" << endl;
		for (int i = 0; i < board->width; i++)
		{
			cout << "_____";
		}
		cout << endl;
	}
}
int PlacePlayer(Cell p, int x, Board *board) {
	for (int i = board->length; i > 0; i--) {
		if (board->surface[i - 1][x - 1] == ' ') {
			board->surface[i - 1][x - 1] = p;
			return i;
		}
	}
}
void PlaceStone(int x, Board *board)
{
	for (int i = board->length; i > 0; i--) {
		if (board->surface[i - 1][x - 1] == ' ') {
			board->surface[i - 1][x - 1] = stone;
			break;
		}
	}
}
bool Winner(int x, int y, Cell p, Board *board, User &player1, User &player2, int passed_turns) {
	int ccol = 1, crow = 1, cld = 1, crd = 1;
	for (int i = x, j = y - 1; i < board->length && board->surface[i][j] == p; i++) {
		ccol++;
		if (ccol >= Win) {
			if (p == red)
			{
				cout <<"       "<< player1.name << "  Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << "       "<<player2.name << "  Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}

			return true;
		}
	} // this loop checking win rate between blue and red on the columns
	for (int j = y - 2, i = x - 1; j >= 0 && board->surface[i][j] == p; j--) {
		crow++;
		if (crow >= Win) {
			if (p == red)
			{
				cout << "       " << player1.name << "  Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << "       " << player2.name << "  Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}

			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the left side on the row
	for (int j = y, i = x - 1; j < board->width && board->surface[i][j] == p; j++) {
		crow++;
		if (crow >= Win) {
			if (p == red)
			{
				cout << "       " << player1.name << "  Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << "       " << player2.name << "  Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}

			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the right side on the row
	for (int j = y - 2, i = x; i < board->length && board->surface[i][j] == p; i++, j--) {
		cld++;
		if (cld >= Win) {
			if (p == red)
			{
				cout << "       " << player1.name << "  Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << "       " << player2.name << "  Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}

			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the left diagonal on the board
	for (int j = y, i = x; i < board->length && board->surface[i][j] == p; i++, j++) {
		crd++;
		if (crd >= Win) {
			if (p == red)
			{
				cout << "       " << player1.name << "  Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << "       " << player2.name << "  Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}

			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the right diagonal on the board
	for (int j = y, i = x - 2; i >= 0 && j < board->width && board->surface[i][j] == p; i--, j++) {
		cld++;
		if (cld >= Win) {
			if (p == red)
			{
				cout << "       " << player1.name << "  Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << "       " << player2.name << "  Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}

			return true;
		}
	} // this loop checking win rate between blue and red from the last spot on the upper left diagonal
	for (int j = y - 2, i = x - 2; i >= 0 && j >= 0 && board->surface[i][j] == p; i--, j--) {
		crd++;
		if (crd >= Win) {
			if (p == red)
			{
				cout << "       " << player1.name << "  Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << "       " << player2.name << "  Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}

			return true;
		}
	} // this loop checking win rate between blue and red from the last spot on the upper right diagonal
	return false;
}
void PlayForInARow(User &player1, User &player2) {
	Board *board = new Board;
	int passed_turns = 0;
	int StoneCounter = 0;
	int k = 0, i, placement, temp, row, col;
	int Tothrow, throwed=0;
	bool flag=false;
	row = board->length;
	col = board->width;
	board->surface = new Cell*[row];
	for (int i = 0; i < row; i++) {
		board->surface[i] = new Cell[col];
		for (int j = 0; j < col; j++) {
			board->surface[i][j] = space;
		}
	}
	PrintBoard(board);

	for (i = 0; i < row*col; i++) {
		if (k % 2 == 0) {
			placement = UserChoice(player1, board);
			if (placement == 0)
			{
				flag = true;
				break;
			}
			temp = PlacePlayer(red, placement, board);
			PrintBoard(board);
			if (i >= 6 && temp > 0 && Winner(temp, placement, red, board, player1, player2, passed_turns) == true) {
				cout << endl << endl << "       \nPress Enter continue" << endl;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			}
			if (player1.if_premium && throwed == 0)
			{
				cout << player1.name << " Would you like to throw a stone?  1 - Yes  2 - No  0 - Pause" << endl;
				cin >> Tothrow;
				if (Tothrow == 1)
				{
					cout << player1.name << " Where would you like to throw a stone? [1-" << col << "]" << endl;
					placement = UserChoice(player1, board);
					if (placement == 0)
					{
						flag = true;
						break;
					}
					PlaceStone(placement, board);
					throwed++;
					PrintBoard(board);
				}
			}
		}
		if (k % 2 != 0) {
			placement = UserChoice(player2, board);
			if (placement == 0)
			{
				flag = true;
				break;
			}
			temp = PlacePlayer(blue, placement, board);
			PrintBoard(board);
			if (i >= 6 && temp > 0 && Winner(temp, placement, blue, board, player1, player2, passed_turns) == true) {
				cout << endl << endl << "       \nPress Enter continue" << endl;
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
				break;
			}
			if (player2.if_premium && throwed == 0)
			{
				cout << player2.name << " Would you like to throw a stone?  1 - Yes  2 - No  0 - Pause" << endl;
				cin >> Tothrow;
				if (Tothrow == 1)
				{
					cout << player2.name << " Where would you like to throw a stone? [1-" << col << "]" << endl;
					placement = UserChoice(player1, board);
					if (placement == 0)
					{
						flag = true;
						break;
					}
					PlaceStone(placement, board);
					throwed++;
					PrintBoard(board);
				}
			}
			passed_turns++;
			StoneCounter++;
		}
		if (StoneCounter == 3)
		{
			placement = RandomCol();
			PlacePlayer(stone, placement, board);
			StoneCounter = 0;
		}
		k++;
	} // this loop running the Connect Four game
	if (i == row * col && flag==false) {
		cout << " Draw! " << endl;
		getchar();
		cout << endl << endl << "       \nPress Enter continue" << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	getchar();
	delete board;
}
int UserChoice(User player, Board *board)
{
	bool flag = true,flag2=false;
	int choice;
	do
	{
		cout << player.name << " Please enter your - input! [1-7]  0 - Pause:";
		cin >> choice;
		if (choice == 0)
		{
			flag2 = PauseManu();
			if (flag2)
			{
				break;
			}
		}
		else if (choice > 7 || choice <0)
		{
			cout << " Board-size deviation! Please re-enter your input " << endl;
		}
		else
		{
			return choice;
		}
		PrintBoard(board);
	} while (flag);

	return 0;
}