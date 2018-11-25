#include "MainManu.h"

int main()
{
	User one, two;
	one.if_manager = 0;
	one.if_premium = 1;
	one.name[0] = 'A';
	one.name[1] = '\0';
	one.password = 123456;
	two.if_manager = 0;
	two.if_premium = 1;
	two.name[0] = 'B';
	two.name[1] = '\0';
	two.password = 123456;
	MainMenu(one,two);
	return 0;
}