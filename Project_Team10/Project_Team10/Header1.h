#pragma once

#include <iostream>
#include <time.h>
#include "Header.h"

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
// war
int Random() {
	/*******************delete test************************/
	//return random number 0<=rand<=12
	//used to take out rando card from user package
	unsigned int rand = time(NULL) % 1000;
	rand = rand%12;
	return rand;
}
//test
/*^^^^^^^^^^^^unfinished^^^^^^^^^^^*/
void PrintCard(Card card) {//maybe int
	cout << "card: " << card.card_name << endl;
	cout << card.num_of_card << " cards of type " << card.card_name << " are left in pack" << endl; //for test only
																									/*need to make cool prints for cards by type*/
}
void PrintPack(CardPackage pack) {//for tests
	/*print all cards in package*/
	for (int i = 0; i < 13; i++) {
		cout << pack.Card_Package[i].num_of_card << " num of type " << pack.Card_Package[i].card_name << endl;
	}																	
}
void OneRoundWinner(User win, User looser) {
	cout << "winner is: " << win.name << endl;
	cout << looser.name << " you such a looser go home" << endl;
}
void WarGameWinner(User win, User looser) {
	cout << "winner is: " << win.name << endl;
	cout << looser.name << " go home you are stupid" << endl;
}
void PlayWarAgainstUser(User U1, User U2, int num_of_turns = 26) {
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
	PrintPack(pack);//test, need 4 cards from  types 2-14

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
			tmp = tmp % 13;//13?

		}
		u1_card.card_name = pack.Card_Package[tmp].card_name;
		pack.Card_Package[tmp].num_of_card--;
		u1_card.num_of_card = pack.Card_Package[tmp].num_of_card;
		u1_sum += u1_card.card_name;
		//ifpremium-need to do
		cout << U1.name << " card is:" << endl;
		PrintCard(u1_card);
		/******************END OF U1 TURN***********************************/

		/******************START OF U2 TURN***********************************/
		cout <<"now its " << U2.name << " turn" << endl;
		//U2 pull out card
		cout << "press enter to draw card" << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		tmp = Random();
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
		PrintCard(u2_card);
		/******************END OF U2 TURN***********************************/
		cout <<  "\n pack:" << endl;
		PrintPack(pack);
		cout <<endl;
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
					cout << U1.name << "win in this battle" << endl; u1_wins_ctr++;
				}
				if (u1_sum < u2_sum) {
					cout << U2.name << "win in this battle" << endl; u2_wins_ctr++;
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
		if (u1_wins_ctr == u2_wins_ctr) { cout << "both of you are loosers" << endl; }

	
}