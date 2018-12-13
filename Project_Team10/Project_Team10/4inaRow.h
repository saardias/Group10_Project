#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
#define red 'r'
#define blue 'b'
#define r 'r'
#define b 'b'
#define Mlen 6
#define Mwidth 7
#define Disc (char)254
#define Space ' '
#define Win 4
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int len = Mlen, width = Mwidth; // size
	char **player; // table view
}Board;
/*void print(Board *B); // printing function
int PlacePlayer(char p, int x,Board *B); // spotting player function
bool Winner(int x, int y, char p,Board *B); // winner boolean function
*/
void Winner_point(User Winner, User losser, int passed_turns)
{
	int winner_points = 0;
	winner_points = 1000 - (25 * passed_turns);
	cout << "with " << winner_points << " points" << endl;
}

void print(Board *B) {

	int i, j, p;
	cout << "|";
	for (j = 0; j < B->width; j++) {
		cout << " " << j + 1 << " " << "|";
	}
	cout << endl << " ";
	for (p = 1; p < (B->width * 4); p++) { cout << "_"; }
	cout << endl;
	for (i = 0; i < B->len; i++) {
		cout << "|";
		for (j = 0; j < B->width; j++) {
			cout << " ";
			if (B->player[i][j] == 'r') {
				cout << red;
			}
			if (B->player[i][j] == 'b') {
				cout << blue;
			}
			else {
				if (B->player[i][j] != 'r' && B->player[i][j] != 'b') {
					cout << B->player[i][j];
				}
			}
			cout << " " << "|";
		}
		cout << endl << " ";
		for (p = 1; p < (B->width * 4); p++) { cout << "_"; }
		cout << endl;
	}
}

int PlacePlayer(char p, int x, Board *B) {
	for (int i = B->len; i > 0; i--) {
		if (B->player[i - 1][x - 1] == ' ') {
			B->player[i - 1][x - 1] = p;
			return i;
		}
	}
}

bool Winner(int x, int y, char p, Board *B, User &player1, User &player2, int passed_turns) {
	int ccol = 1, crow = 1, cld = 1, crd = 1;
	for (int i = x, j = y - 1; i < B->len && B->player[i][j] == p; i++) {
		ccol++;
		if (ccol >= Win) {
			if (p == r)
			{
				cout << player1.name << "Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << player2.name << "Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}
			return true;
		}
	} // this loop checking win rate between blue and red on the columns
	for (int j = y - 2, i = x - 1; j >= 0 && B->player[i][j] == p; j--) {
		crow++;
		if (crow >= Win) {
			if (p == r)
			{
				cout << player1.name << "Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << player2.name << "Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}
			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the left side on the row
	for (int j = y, i = x - 1; j < B->width && B->player[i][j] == p; j++) {
		crow++;
		if (crow >= Win) {
			if (p == r)
			{
				cout << player1.name << "Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << player2.name << "Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}
			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the right side on the row
	for (int j = y - 2, i = x; i < B->len && B->player[i][j] == p; i++, j--) {
		cld++;
		if (cld >= Win) {
			if (p == r)
			{
				cout << player1.name << "Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << player2.name << "Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}
			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the left diagonal on the board
	for (int j = y, i = x; i < B->len && B->player[i][j] == p; i++, j++) {
		crd++;
		if (crd >= Win) {
			if (p == r)
			{
				cout << player1.name << "Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << player2.name << "Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}
			return true;
		}
	} // this loop checking win rate between blue and red from the last spot to the right diagonal on the board
	for (int j = y, i = x - 2; i >= 0 && j < B->width && B->player[i][j] == p; i--, j++) {
		cld++;
		if (cld >= Win) {
			if (p == r)
			{
				cout << player1.name << "Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << player2.name << "Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}
			return true;
		}
	} // this loop checking win rate between blue and red from the last spot on the upper left diagonal
	for (int j = y - 2, i = x - 2; i >= 0 && j >= 0 && B->player[i][j] == p; i--, j--) {
		crd++;
		if (crd >= Win) {
			if (p == r)
			{
				cout << player1.name << "Won ! " << endl;
				Winner_point(player1, player2, passed_turns);
			}
			else
			{
				cout << player2.name << "Won ! " << endl;
				Winner_point(player2, player1, passed_turns);
			}
			return true;
		}
	} // this loop checking win rate between blue and red from the last spot on the upper right diagonal
	return false;
}

void PlayForInARow(User &player1, User &player2) {
	Board *P = new Board;
	int passed_turns = 0;
	int k = 0, i, placement, temp, row, col;
	row = P->len;
	col = P->width;
	P->player = new char*[row];
	for (int i = 0; i < row; i++) {
		P->player[i] = new char[col];
		for (int j = 0; j < col; j++) {
			P->player[i][j] = ' ';
		}
	}
	print(P);
	for (i = 0; i < row*col; i++) {
		if (k % 2 == 0) {
			cout << player1.name << "Please enter your input! [1-" << col << "]" << " Player (Red) :";
			cin >> placement;
			if (placement > col || placement <= 0) {
				cout << " Board-size deviation! Please re-enter your input " << endl;
				cin >> placement;
			}
			temp = PlacePlayer(r, placement, P);
			print(P);
			if (i >= 6 && temp > 0 && Winner(temp, placement, r, P, player1, player2, passed_turns) == true) {
				break;
			}
		}
		if (k % 2 != 0) {
			cout << player2.name << "Please enter your input! [1-" << col << "]" << " Player (Blue) :";
			cin >> placement;
			if (placement > col || placement <= 0) {
				cout << " Board-size deviation! Please re-enter your input " << endl;
				cin >> placement;
			}
			temp = PlacePlayer(b, placement, P);
			print(P);
			if (i >= 6 && temp > 0 && Winner(temp, placement, b, P, player1, player2, passed_turns) == true) {
				break;
			}
			passed_turns++;
		}
		k++;
	} // this loop running the Connect Four game
	if (i == row * col) {
		cout << " Draw! " << endl;
	}
	delete P;
}
