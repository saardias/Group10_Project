#pragma once

#include <iostream>
#include <time.h>
#include "Structs.h"
#include"visuals.h"
#include <cstdlib>
#include "MainManu.h"
#include "Statistics.h"
#include "ScoreBoard.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
void Pre_Lost(User &pre, User &NewPre);

// war
int Random() {
	//return random number 0<=rand<=12
	//used to take out rando card from user package
	unsigned int rand = time(NULL) % 1000;

	rand = rand % 12;
	return rand;
}
void PrintPack(CardPackage pack) {//for tests
	/*print all cards in package*/
	for (int i = 0; i < 13; i++) {
		std::cout << pack.Card_Package[i].num_of_card << " num of type " << pack.Card_Package[i].card_name << endl;
	}
}
void OneRoundWinner(User &win, User &looser) {
	std::cout << "winner of this round is: " << win.name << endl;
	std::cout << looser.name << " you such a looser go home" << endl;
}
void WarGameWinner(User &win, User &looser, int winner_points, int looser_points) {
	std::cout << "\n\n\n========- GAME OVER -========" << endl;

	std::cout << "\n\n and the big winner of the game is: " << win.name << endl;
	std::cout << " winner points: " << winner_points << endl;
	std::cout << looser.name << " go home you are stupid" << endl;
	std::cout << " looser points: " << looser_points << endl;
	std::cout << "====================================" << endl;

	Set_Cards_Battle_Statistics(win.name, looser.name);
	Set_Cards_Score_Board(win.name, winner_points);
	std::cout << "press enter to exit" << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');


}
void PlayWar(User &U1, User &U2, int num_of_turns = 26) {
	/*this is the game*/
	CardPackage pack;
	int tmp, u1_wins_ctr = 0, u2_wins_ctr = 0, u1_sum = 0, u2_sum = 0, ctr_p_changes=3;
	Card u1_card, u2_card;

	// reset pack so the pack contain 4 cards from any type of card
	pack.pack_size = 0;
	for (int i = 0; i < 13; i++) {
		pack.Card_Package[i].card_name = i + 2;
		pack.Card_Package[i].num_of_card = 4;
		pack.pack_size += 4;// unnesessery we know its 52 in the end
	}
	// the main player choose to play against computer or against user2
	string choice = "u";
	string tmp_u2_name;
	bool u2_is_computer;
	do {
		std::cout << "to play against " << U2.name << " press 1" << endl;
		std::cout << "to play against computer press 2" << endl;
		cin >> choice;
	} while (choice != "1"&&choice != "2");
	if (choice == "1") { u2_is_computer = false; }
	if (choice == "2") { u2_is_computer = true; tmp_u2_name = U2.name; U2.name = "computer"; }

	/*********************game start here**************************/
	for (int ctr_turns = 0; ctr_turns < num_of_turns; ctr_turns++) {//
		/******************START OF U1 TURN***********************************/
		std::cout << "\n\nround number " << ctr_turns + 1 << "\nits " << U1.name << " turn" << endl;
		//U1 pull out card
		
				std::cout << "press 1 to pause\nor any other key to draw card" << endl;
				cin >> choice;
				if(choice=="1"){
				cout << "press E to exit\nor any other key to continue\n";
				cin >> choice;
				if(choice=="E"||choice=="e"){return;}
				}
		
		//std::cout << "press enter to draw card" << endl;
		//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		tmp = Random();
		while (pack.Card_Package[tmp].num_of_card < 1 || pack.Card_Package[tmp].num_of_card>4)
		{
			//find legal card
			tmp++;
			tmp = tmp % 13;

		}
		u1_card.card_name = pack.Card_Package[tmp].card_name;
		if (U1.if_premium) {
			std::cout << "\n\n" << U1.name << " you are a premium member \n do you want to draw another card?" << endl;
			std::cout << "you can do it " << ctr_p_changes << " times in this game" << endl;
			std::cout << "press 1 to draw card" << endl;
			std::cout << "press 2 to pass" << endl;
	//		int choice;
			cin >> choice;
			if (choice == "1") {
				//U1 pull out card
				ctr_p_changes--;
				tmp = Random();
				while (pack.Card_Package[tmp].num_of_card < 1 || pack.Card_Package[tmp].num_of_card>4)
				{
					//find legal card
					tmp++;
					tmp = tmp % 13;

				}
				if (u1_card.card_name < pack.Card_Package[tmp].card_name) { u1_card.card_name = pack.Card_Package[tmp].card_name; }
			}
		}
		pack.Card_Package[u1_card.card_name-2].num_of_card--;
		u1_card.num_of_card = pack.Card_Package[tmp].num_of_card;
		u1_sum += u1_card.card_name;
		//ifpremium-need to do
		std::cout << U1.name << " card is:";
		PrintCard(u1_card.card_name);
		/******************END OF U1 TURN***********************************/

		/******************START OF U2 TURN***********************************/
		std::cout << "now its " << U2.name << " turn" << endl;
		//U2 pull out card
		if (!u2_is_computer) {
		
		std::cout << "press 1 to pause\nor any other key to draw card" << endl;
		cin>>choice;
		if(choice=="1"){
		cout<<"press E to exit\nor any other key to continue\n";
		cin>>choice;
		if(choice=="E"||choice=="e"){return;}
		}
		}
		
			std::cout << "press enter to draw card" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		tmp = Random();
		if(tmp%3==0){ tmp +=3; }
		if (tmp % 3 == 1) { tmp -= 2; }
		if (tmp % 3 == 2) { tmp -= 4; }
		tmp = tmp % 13;

		while (pack.Card_Package[tmp].num_of_card < 1 || pack.Card_Package[tmp].num_of_card>4)
		{
			//find legal card
			tmp++;
			tmp = tmp % 13;
		}
		u2_card.card_name = pack.Card_Package[tmp].card_name;
		if (U2.if_premium&& !u2_is_computer) {
			std::cout << "\n\n" << U2.name << " you are a premium member \n do you want to draw another card?" << endl;
			std::cout << "you can do it " << ctr_p_changes << " times in this game" << endl;
			std::cout << "press 1 to draw card" << endl;
			std::cout << "press 2 to pass" << endl;
			//int choice;
			cin >> choice;
			if (choice == "1") {
				//U1 pull out card
				ctr_p_changes--;
				tmp = Random();
				while (pack.Card_Package[tmp].num_of_card < 1 || pack.Card_Package[tmp].num_of_card>4)
				{
					//find legal card
					tmp++;
					tmp = tmp % 13;

				}
				if (u2_card.card_name < pack.Card_Package[tmp].card_name) { u2_card.card_name = pack.Card_Package[tmp].card_name; }
			}
		}

		pack.Card_Package[u2_card.card_name-2].num_of_card--;
		u2_card.num_of_card = pack.Card_Package[tmp].num_of_card;
		u2_sum += u2_card.card_name;
		std::cout << U2.name << " card is:" << endl;
		PrintCard(u2_card.card_name);
		/******************END OF U2 TURN***********************************/
		std::cout << endl;
		/************* BATTLE BEGIN ****************/
		std::cout << "		/************* BATTLE BEGIN ****************/" << endl;
		if (u1_card.card_name > u2_card.card_name) {
			OneRoundWinner(U1, U2);
			u1_wins_ctr++;
		}
		else if (u1_card.card_name < u2_card.card_name) {
			OneRoundWinner(U2, U1);
			u2_wins_ctr++;
		}
		else { //war state
			std::cout << U1.name << " have " << u1_sum << " points in the pocket" << endl << endl;
			std::cout << U2.name << " have " << u2_sum << " points in the pocket" << endl;
			if (u1_sum > u2_sum) {
				OneRoundWinner(U1, U2);

				u1_wins_ctr++;
			}
			if (u1_sum < u2_sum) {
				OneRoundWinner(U2, U1);
				u2_wins_ctr++;
			}
			if (u1_sum == u2_sum) {
				std::cout << "no one win in this battle" << endl;//rare after beggining
			}
			std::cout << "		/************* BATTLE END ****************/" << endl;

			/************* BATTLE END ****************/

		}
	}
	/*****WarGameWinner******/
	if (u1_wins_ctr > u2_wins_ctr) { WarGameWinner(U1, U2, u1_wins_ctr, u2_wins_ctr); if (U2.if_premium) { Pre_Lost(U2, U1); } }
	if (u1_wins_ctr < u2_wins_ctr) { WarGameWinner(U2, U1, u2_wins_ctr, u1_wins_ctr); if (U1.if_premium) { Pre_Lost(U1, U2); } }
	if (u1_wins_ctr == u2_wins_ctr) { std::cout << "its a tie, no one win" << endl; }//rare 

	if (u2_is_computer) { U2.name = tmp_u2_name; }
}