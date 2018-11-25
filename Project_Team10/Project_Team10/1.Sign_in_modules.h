#define CRT_SECURE_NO_WARNINGS
#define admin_pass 77766613

#include <string>
#include <iostream>
#include <fstream>
#include "Structs.h"
using namespace std;

bool sign_in(User& player);
void create_user(User& p1, User& p2);
void get_user_data(string& user_name, long int& pass, bool& admin);
//function for signing in
bool sign_in(User& player) {
	int choice;
	bool exists = 0, admin = 0, premium = 0, admin_temp, prem_temp;
	ifstream users_in;
	ofstream users_out;
	string user_name, temp;
	long int pass, temp_pass;
	users_out.open("user_data.txt", ios::out | ios::app);
	users_in.open("user_data.txt", ios::in);
	cout << "for sign-in press 1\nfor log-in press 2" << endl;
	cin >> choice;
	if (choice == 1) {
		get_user_data(user_name, pass, admin);
		if (users_in.peek() == std::ifstream::traits_type::eof()) {
			users_out << admin << "\n";
			player.if_manager = admin;
			users_out << premium << "\n";
			player.if_premium = premium;
			users_out << user_name << "\n";
			player.name = user_name;
			users_out << pass << "\n";
			player.password = pass;
			users_in.close();
			users_out.close();
			return true;
		}
		else {
			while (!users_in.eof()) {
				users_in >> admin_temp;
				users_in >> prem_temp;
				users_in >> temp;
				users_in >> temp_pass;
				if (user_name == temp) {
					cout << "Name already exists!\n";
					users_in.close();
					users_out.close();
					return false;
				}
			}
			users_out << admin << "\n";
			player.if_manager = admin;
			users_out << premium << "\n";
			player.if_premium = premium;
			users_out << user_name << "\n";
			player.name = user_name;
			users_out << pass << "\n";
			player.password = pass;
			users_in.close();
			users_out.close();
			return true;
		}
	}
	else if (choice == 2) {
		get_user_data(user_name, pass, admin);
		if (users_in.peek() == std::ifstream::traits_type::eof()) {
			cout << "User doesn't exist!\n";
			return false;
		}
		else {
			while (!users_in.eof()) {
				users_in >> admin_temp;
				users_in >> prem_temp;
				users_in >> temp;
				users_in >> temp_pass;
				if (user_name == temp && pass == temp_pass) {
					users_in.close();
					users_out.close();
					return true;
				}
				if (user_name == temp && pass != temp_pass) {
					cout << "wrong password!" << endl;
					users_in.close();
					users_out.close();
					return false;
				}
			}
			cout << "User doesn't exist!" << endl;
			users_in.close();
			users_out.close();
			return false;
		}
	}
	else {
		cout << "Wrong input!" << endl;
		users_in.close();
		users_out.close();
		return false;
	}

}

void create_user(User& p1, User& p2) {
	int choice;
	cout << "signing player 1 " << endl;
	while (!sign_in(p1)) {}
	do {
		cout << "To play against a computer press 1\nTo play against a second player press 2" << endl;
		cin >> choice;
		if (choice == 1) {
			p2.if_manager = false;
			p2.if_computer = true;
			p2.if_premium = false;
			p2.name = "Computer";
			p2.password = 0;
			break;
		}
		else if (choice == 2) {
			cout << "signing player 2 " << endl;
			while (!sign_in(p2)) {}
		}
		else
			cout << "Wrong input!" << endl;
	} while (choice != 1 && choice != 2);
}

void get_user_data(string& user_name, long int& pass, bool& admin) {
	cout << "Please enter name" << endl;
	cin >> user_name;
	cout << "Please enter password" << endl;
	cin >> pass;
	if (pass == admin_pass)
		admin = 1;
}
