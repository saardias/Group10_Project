#pragma once
#include"visuals.h"
#include"Structs.h"

void play_snakes_and_ladders(User U1, User U2) {
	SnakesBoard Board = SetNewBoard();
	int U1p, U2p, dice, penaltySnake1, penaltySnake2, penaltyLadder1, penaltyLadder2;
	char choice;
	if (U1.if_premium == 1) {
		U1p = 30;
		penaltySnake1 = 5;
		penaltyLadder1 = 3;
	}
	else {
		U1p = 20;
		penaltySnake1 = 10;
		penaltyLadder1 = 5;
	}
	if (U2.if_premium == 1) {
		U2p = 30;
		penaltySnake2 = 5;
		penaltyLadder2 = 3;
	}
	else {
		U2p = 20;
		penaltySnake2 = 10;
		penaltyLadder2 = 5;
	}
	srand(time(NULL));
	PrintSnakesBoard(Board);
	cout << U1.name << " has " << U1p << " points." << endl;
	cout << U2.name << " has " << U2p << " points." << endl;
	for (int i = 1; ; i++) {

		if (i % 2 != 0) {
			cout << "It's " << U1.name << "'s turn. Press 0 to surrender. Press any other charachter to roll the dice." << endl; //pause menu here
			cin >> choice;
			if (choice != 0) {
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
				dice = rand() % 6 + 1;
			}
			else {
				cout << U1.name << " has surrendered. " << U2.name << " wins!" << endl;
				break;
			}

			cout << U1.name << " rolled " << dice << endl;
			Board.U1_place += dice;
			PrintSnakesBoard(Board);
			if (Board.U1_place >= 100) {
				cout << U1.name << " has won the match!" << endl;
				break;
			}
			else if (Board.U1_place == Board.snake1 || Board.U1_place == Board.snake2 || Board.U1_place == Board.snake3 || Board.U1_place == Board.snake4 || Board.U1_place == Board.snake5 || Board.U1_place == Board.snake6 || Board.U1_place == Board.snake7) {
				cout << U1.name << " has encoutered a snake. To save yourself you must pay: " << ((U1.if_premium) ? 5 : 10) << endl;
				cout << "To save yourself press 1, to go down the snake press anyother charachter." << endl;
				cin >> choice;
				if (choice == '1') {
					U1p -= penaltySnake1;
				}
				else {
					Board.U1_place -= 10;
					PrintSnakesBoard(Board);
				}
			}
			else if (Board.U1_place == Board.lader1 || Board.U1_place == Board.lader2 || Board.U1_place == Board.lader3 || Board.U1_place == Board.lader4 || Board.U1_place == Board.lader5) {
				cout << U1.name << " has encoutered a ladder. To go up the ladder you must pay: " << ((U1.if_premium) ? 3 : 5) << endl;
				cout << "To go up press 1, to skip the ladder press any other charachter." << endl;
				cin >> choice;
				if (choice == '1') {
					U1p -= penaltyLadder1;
					Board.U1_place += 10;
					PrintSnakesBoard(Board);
				}
			}
		}
		else {
			cout << "It's " << U2.name << "'s turn. Press 0 to surrender. Press any other charachter to roll the dice." << endl; //pause menu here
			cin >> choice;
			if (choice != 0) {
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
				dice = rand() % 6 + 1;
			}
			else {
				cout << U2.name << " has surrendered. " << U1.name << " wins!" << endl;
				break;
			}
			cout << U2.name << " rolled " << dice << endl;
			Board.U2_place += dice;
			PrintSnakesBoard(Board);
			if (Board.U2_place == 100) {
				cout << U2.name << " has won the match!" << endl;
				break;
			}
			else if (Board.U2_place == Board.snake1 || Board.U2_place == Board.snake2 || Board.U2_place == Board.snake3 || Board.U2_place == Board.snake4 || Board.U2_place == Board.snake5 || Board.U2_place == Board.snake6 || Board.U2_place == Board.snake7) {
				cout << U2.name << " has encoutered a snake. To save yourself you must pay: " << ((U2.if_premium) ? 5 : 10) << endl;
				cout << "To save yourself press 1, to go down the snake press anyother charachter." << endl;
				cin >> choice;
				if (choice == '1') {
					U2p -= penaltySnake2;
				}
				else {
					Board.U2_place -= 10;
					PrintSnakesBoard(Board);
				}
			}
			else if (Board.U2_place == Board.lader1 || Board.U2_place == Board.lader2 || Board.U2_place == Board.lader3 || Board.U2_place == Board.lader4 || Board.U2_place == Board.lader5) {
				cout << U2.name << " has encoutered a ladder. To go up the ladder you must pay: " << ((U2.if_premium) ? 3 : 5) << endl;
				cout << "To go up press 1, to skip the ladder press any other charachter." << endl;
				cin >> choice;
				if (choice == '1') {
					U2p -= penaltyLadder2;
					Board.U2_place += 10;
					PrintSnakesBoard(Board);
				}
			}
		}
	}

}