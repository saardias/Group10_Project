#pragma once
#include<stdlib.h>
#include<time.h>
#include"Colors.h"
#include"visuals.h"
#include"Structs.h"
#include"MainManu.h"
#include"ScoreBoard.h"
void Pre_Lost(User &pre, User &NewPre);

bool PauseSnakes()
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

void snake_encounter(User player, int penalty, int &points, int &place) {
	string choice;
	cout << player.name << " has encoutered a snake. To save yourself you must pay: " << penalty;
	cout << ". You have: " << points << " points." << endl;
	cout << "To save yourself press 1, to go down the snake press any other charachter." << endl;
	cin >> choice;
	if (choice == "1") {
		if (points - penalty < 0) {
			cout << "You dont have enough points to save yourself! You'll go down the snake." << endl;
			place -= 10;

		}
		else {
			points -= penalty;
			cout << player.name << " paid " << penalty << " and now has " << points << " points." << endl;
		}
	}
	else {
		place -= 10;
	}

}

void ladder_encounter(User player, int penalty, int &points, int &place) {
	string choice;
	cout << player.name << " has encoutered a ladder. To go up the ladder you must pay: " << penalty;
	cout << ". You have: " << points << " points." << endl;
	cout << "To go up press 1, to skip the ladder press any other charachter." << endl;
	cin >> choice;
	if (choice == "1") {
		if (points - penalty < 0) {
			cout << "You dont have enough points to save yourself! You'll skip the ladder." << endl;
		}
		else {
			points -= penalty;
			cout << player.name << " paid " << penalty << " and now has " << points << " points." << endl;
			place += 10;
		}
	}
}

void bonus_points(User player, int &points, int rand_bonus, int turn) {
	int bonus;
	if (turn == 1)
		cout << player.name << " starts with " << points << " points." << endl;
	else {
		bonus = rand() % rand_bonus;
		cout << player.name << " has been given " << bonus << " points." << endl;
		points += bonus;
		cout << player.name << " has " << points << " points." << endl;
	}
}

void refresh_screen(SnakesBoard Board) {
	std::this_thread::sleep_for(std::chrono::milliseconds(1650));
	system("CLS");
	PrintSnakesBoard(Board);
}

void dice_placement(User player, int &place) {
	std::this_thread::sleep_for(std::chrono::milliseconds(60));
	int dice = rand() % 6 + 1;
	cout << player.name << " rolled " << dice << endl;
	place += dice;
	if (place > 100)
		place = 100;
}

void play_snakes_and_ladders(User& U1, User& U2) {
	SnakesBoard Board = SetNewBoard();
	int U1p, U2p, dice, penaltySnake1, penaltySnake2, penaltyLadder1, penaltyLadder2, rand1, rand2;
	string choice;
	if (U1.if_premium == 1) {
		U1p = 30;
		penaltySnake1 = 5;
		penaltyLadder1 = 3;
		rand1 = 10 + 1;
	}
	else {
		U1p = 20;
		penaltySnake1 = 10;
		penaltyLadder1 = 5;
		rand1 = 5 + 1;
	}
	if (U2.if_premium == 1) {
		U2p = 30;
		penaltySnake2 = 5;
		penaltyLadder2 = 3;
		rand2 = 10 + 1;
	}
	else {
		U2p = 20;
		penaltySnake2 = 10;
		penaltyLadder2 = 5;
		rand2 = 5 + 1;
	}
	srand(time(NULL));
	PrintSnakesBoard(Board);
	for (int i = 1; ; i++) {

		if (i % 2 != 0) {
			cout << "It's ";
			ChangeColor(LIGHTBLUE);
			cout << U1.name;
			ChangeColor(LIGHTGREY);
			cout << "'s turn." << endl;
			bonus_points(U1, U1p, rand1, i);
			cout << "Press 0 to pause the game. Press any other character to roll the dice." << endl; //pause menu here
			cin >> choice;
			if (choice == "0") {
				bool to_exit = PauseSnakes();
				if (to_exit == true) {
					return;
				}
				else {
					refresh_screen(Board);
					dice_placement(U1, Board.U1_place);
					refresh_screen(Board);
				}
			}
			else {
				dice_placement(U1, Board.U1_place);
				refresh_screen(Board);
			}
			if (Board.U1_place >= 100) {
				cout << U1.name << " has won the match!" << endl;
				cout << U1.name << " finished with " << U1p << " points." << endl;
				cout << U2.name << " finished with " << U2p << " points." << endl;
				Set_Snakes_And_Ladders_Statistics(U1.name, U2.name);
				Set_Snakes_And_Ladders_Score_Board(U1.name, U1p);
				if (U2.if_premium == true) {
					Pre_Lost(U2, U1);
				}
				cout << "Press any character to exit" << endl;
				cin >> choice;
				break;
			}
			else if (Board.U1_place == Board.snake1 || Board.U1_place == Board.snake2 || Board.U1_place == Board.snake3 || Board.U1_place == Board.snake4 || Board.U1_place == Board.snake5 || Board.U1_place == Board.snake6 || Board.U1_place == Board.snake7) {
				snake_encounter(U1, penaltySnake1, U1p, Board.U1_place);
				refresh_screen(Board);
			}
			else if (Board.U1_place == Board.lader1 || Board.U1_place == Board.lader2 || Board.U1_place == Board.lader3 || Board.U1_place == Board.lader4 || Board.U1_place == Board.lader5) {
				ladder_encounter(U1, penaltyLadder1, U1p, Board.U1_place);
				refresh_screen(Board);
			}
		}
		else {
			cout << "It's ";
			ChangeColor(LIGHTRED);
			cout << U2.name;
			ChangeColor(LIGHTGREY);
			cout << "'s turn." << endl;
			bonus_points(U2, U2p, rand2, i - 1);
			cout << "Press 0 to pause the game. Press any other character to roll the dice." << endl; //pause menu here
			cin >> choice;
			if (choice == "0") {
				bool to_exit = PauseSnakes();
				if (to_exit == true) {
					return;
				}
				else {
					refresh_screen(Board);
					dice_placement(U2, Board.U2_place);
					refresh_screen(Board);
				}
			}
			else {
				dice_placement(U2, Board.U2_place);
				refresh_screen(Board);
			}
			if (Board.U2_place >= 100) {
				cout << U2.name << " has won the match!" << endl;
				cout << U1.name << " finished with " << U1p << " points." << endl;
				cout << U2.name << " finished with " << U2p << " points." << endl;
				Set_Snakes_And_Ladders_Statistics(U2.name, U1.name);
				Set_Snakes_And_Ladders_Score_Board(U2.name, U2p);
				if (U1.if_premium == true) {
					Pre_Lost(U1, U2);
				}
				cout << "Press any character to exit" << endl;
				cin >> choice;
				break;
			}
			else if (Board.U2_place == Board.snake1 || Board.U2_place == Board.snake2 || Board.U2_place == Board.snake3 || Board.U2_place == Board.snake4 || Board.U2_place == Board.snake5 || Board.U2_place == Board.snake6 || Board.U2_place == Board.snake7) {
				snake_encounter(U2, penaltySnake2, U2p, Board.U2_place);
				refresh_screen(Board);
			}
			else if (Board.U2_place == Board.lader1 || Board.U2_place == Board.lader2 || Board.U2_place == Board.lader3 || Board.U2_place == Board.lader4 || Board.U2_place == Board.lader5) {
				ladder_encounter(U2, penaltyLadder2, U2p, Board.U2_place);
				refresh_screen(Board);
			}
		}
	}

}