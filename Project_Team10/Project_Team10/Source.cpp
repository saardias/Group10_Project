#include "Colors.h"
#include "MainManu.h"
#include "1.Sign_in_modules.h"

int main()
{
	User one, two;
	create_user(one, two);
	MainMenu(one, two);
	return 0;
}