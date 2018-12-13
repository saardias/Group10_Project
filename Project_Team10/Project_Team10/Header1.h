#pragma once

#include <iostream>
#include <time.h>
#include "Structs.h"
#include"visuals.h"
#include <cstdlib>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
// war
int Random() {
	//return random number 0<=rand<=12
	//used to take out rando card from user package
	unsigned int rand = time(NULL) % 1000;

	rand = rand % 12;
	return rand;
}
//test
/*^^^^^^^^^^^^unfinished^^^^^^^^^^^*/
void PrintPack(CardPackage pack) {//for tests
	/*print all cards in package*/
	for (int i = 0; i < 13; i++) {
		cout << pack.Card_Package[i].num_of_card << " num of type " << pack.Card_Package[i].card_name << endl;
	}
}
void OneRoundWinner(User win, User looser) {
	cout << "winner of this round is: " << win.name << endl;
	cout << looser.name << " you such a looser go home" << endl;
}
void WarGameWinner(User win, User looser) {
	cout << "\n\n and the big winner of the game is: " << win.name << endl;
	cout << looser.name << " go home you are stupid" << endl;
}
void PlayWar(User U1, User U2, int num_of_turns = 26) {
	/*this is the game*/
	CardPackage pack;
	int tmp, u1_wins_ctr = 0, u2_wins_ctr = 0, u1_sum = 0, u2_sum = 0;
	Card u1_card, u2_card;

	// reset pack so the pack contain 4 cards from any type of card
	pack.pack_size = 0;
	for (int i = 0; i < 13; i++) {
		pack.Card_Package[i].card_name = i + 2;
		pack.Card_Package[i].num_of_card = 4;
		pack.pack_size += 4;// unnesessery we know its 52 in the end
	}
	// the main player choose to play against computer or against user2
	char choice = 'u';
	string tmp_u2_name;
	bool u2_is_computer;
	do {
		cout << "to play against " << U2.name << " press 1" << endl;
		cout << "to play against computer press 2" << endl;
		cin >> choice;
	} while (choice != '1'&&choice != '2');
	if (choice == '1') { u2_is_computer = false; }
	if (choice == '2') { u2_is_computer = true; tmp_u2_name = U2.name; U2.name = "watson"; }

	/*********************game start here**************************/
	for (int ctr_turns = 0; ctr_turns < num_of_turns; ctr_turns++) {//
		/******************START OF U1 TURN***********************************/
		cout << "\n\nround number " << ctr_turns + 1 << "\nits " << U1.name << " turn" << endl;
		//U1 pull out card
		cout << "press enter to draw card" << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		tmp = Random();
		while (pack.Card_Package[tmp].num_of_card < 1 || pack.Card_Package[tmp].num_of_card>4)
		{
			//find legal card
			tmp++;
			tmp = tmp % 13;

		}
		u1_card.card_name = pack.Card_Package[tmp].card_name;
		pack.Card_Package[tmp].num_of_card--;
		u1_card.num_of_card = pack.Card_Package[tmp].num_of_card;
		u1_sum += u1_card.card_name;
		//ifpremium-need to do
		cout << U1.name << " card is:";
		PrintCard(u1_card.card_name);
		/******************END OF U1 TURN***********************************/

		/******************START OF U2 TURN***********************************/
		cout << "now its " << U2.name << " turn" << endl;
		//U2 pull out card
		if (!u2_is_computer) {
			cout << "press enter to draw card" << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
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
		pack.Card_Package[tmp].num_of_card--;
		u2_card.num_of_card = pack.Card_Package[tmp].num_of_card;
		u2_sum += u2_card.card_name;
		//ifpremium-need to do
		cout << U2.name << " card is:" << endl;
		PrintCard(u2_card.card_name);
		/******************END OF U2 TURN***********************************/
		cout << endl;
		/************* BATTLE BEGIN ****************/
		cout << "		/************* BATTLE BEGIN ****************/" << endl;
		if (u1_card.card_name > u2_card.card_name) {
			OneRoundWinner(U1, U2);
			u1_wins_ctr++;
		}
		else if (u1_card.card_name < u2_card.card_name) {
			OneRoundWinner(U2, U1);
			u2_wins_ctr++;
		}
		else { //war state
			cout << U1.name << " have " << u1_sum << " points in the pocket" << endl;
			cout << U2.name << " have " << u2_sum << " points in the pocket" << endl;
			if (u1_sum > u2_sum) {
				OneRoundWinner(U1, U2);

				u1_wins_ctr++;
			}
			if (u1_sum < u2_sum) {
				OneRoundWinner(U2, U1);
				u2_wins_ctr++;
			}
			if (u1_sum == u2_sum) {
				cout << "no one win in this battle" << endl;//rare after beggining
			}
			cout << "		/************* BATTLE END ****************/" << endl;

			/************* BATTLE END ****************/

		}
	}
	/*****WarGameWinner******/
	if (u1_wins_ctr > u2_wins_ctr) { WarGameWinner(U1, U2); }
	if (u1_wins_ctr < u2_wins_ctr) { WarGameWinner(U2, U1); }
	if (u1_wins_ctr == u2_wins_ctr) { cout << "both of you are loosers" << endl; }//rare 

	U2.name = tmp_u2_name;
}