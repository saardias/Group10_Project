#pragma once

#include <iostream>
#include "Structs.h"

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
// war
CardPackage ResetNewPackage() {
	// reset pack so the pack contain 4 cards from any type of card
	CardPackage pack;
	pack.pack_size = 0;
	for (int i = 0; i < 13; i++) {
		pack.Card_Package[i].card_name = i + 2;
		pack.Card_Package[i].num_of_card = 4;
		pack.pack_size += 4;// unnesessery we know its 52 in the end
	} return pack;
}
int Random(int test) {
	/*******************delete test************************/
	//return random number 0<=rand<=12
	//used to take out rando card from user package
	int rand;
	rand = test;
	return rand;
}
/*^^^^^^^^^^^^unfinished^^^^^^^^^^^*/

void PlayWarAgainstUser(User U1, User U2) {

}
