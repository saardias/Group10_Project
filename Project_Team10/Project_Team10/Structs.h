#pragma once
#include<iostream>
#include <string>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
/*this file will include all structs for the kit:
***********ADMINASTRATION***************
- user

*********************WAR****************
-card
- package (of cards)

*/
struct User {
	/*this is general struct for all users
	the differance between users will apear as a saved data in this struct
	*/
	string name;
	bool if_manager;
	bool if_premium;
	long password;
	int score;
};

struct Card {
	int card_name;
	int num_of_card;
};

struct CardPackage {
	Card Card_Package[13];
	int pack_size;
};
struct SnakesBoard {
	int snake1, snake2, snake3, snake4, snake5, snake6, snake7;
	int lader1, lader2, lader3, lader4, lader5;
	int U1_place, U2_place;
	//int money1, money2;
};

struct cube {
	int num;
	bool up_lader, down_lader, up_snake, down_snake, u1_in, u2_in;
};