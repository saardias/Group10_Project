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
	bool if_manager;
	bool if_premium;
	string name;
	long password;
};

struct Card {
	int card_name;
	int num_of_card;
};

struct CardPackage {
	Card Card_Package[12];
	int pack_size;
};

