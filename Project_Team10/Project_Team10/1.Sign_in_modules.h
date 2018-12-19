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
	char choice;
	bool exists = 0, admin = 0, premium = 0, admin_temp, prem_temp, logged = false;
	ifstream users_in;
	ofstream users_out, temp_out, changed;
	string user_name, temp_name;
	long int pass, temp_pass, log_temp;
	users_out.open("user_data.txt", ios::out | ios::app);
	users_in.open("user_data.txt", ios::in);
	cout << "for sign-up press 1\nfor log-in press 2" << endl;
	cin >> choice;
	if (choice == '1') {
		get_user_data(user_name, pass, admin);
		if (users_in.peek() == std::ifstream::traits_type::eof()) { //if file is empty
			users_out << user_name << "\n";
			player.name = user_name;
			users_out << pass << "\n";
			player.password = pass;
			users_out << 1 << "\n";
			player.logins = 1;
			users_out << admin << "\n";
			player.if_manager = admin;
			users_out << premium;
			player.if_premium = premium;
			users_in.close();
			users_out.close();
			return true;
		}
		else {
			while (!users_in.eof()) {
				users_in >> temp_name;
				users_in >> temp_pass;
				users_in >> log_temp;
				users_in >> admin_temp;
				users_in >> prem_temp;
				
				if (user_name == temp_name) {
					cout << "Name already exists!\n";
					users_in.close();
					users_out.close();
					return false;
				}
			}
			users_out << "\n";
			users_out << user_name << "\n";
			player.name = user_name;
			users_out << pass << "\n";
			player.password = pass;
			users_out << 1 << "\n";
			player.logins = 1;
			users_out << admin << "\n";
			player.if_manager = admin;
			users_out << premium;
			player.if_premium = premium;
			users_in.close();
			users_out.close();
			return true;
		}
	}
	else if (choice == '2') {
		get_user_data(user_name, pass, admin);
		if (users_in.peek() == std::ifstream::traits_type::eof()) {
			cout << "User doesn't exist!\n";
			return false;
		}
		else {
			while (!users_in.eof()) {
				users_in >> temp_name;
				users_in >> temp_pass;
				users_in >> log_temp;
				users_in >> admin_temp;
				users_in >> prem_temp;
				
				if (user_name == temp_name && pass == temp_pass) {
					player.if_manager = admin_temp;
					player.if_premium = prem_temp;
					player.name = user_name;
					player.password = pass;
					player.logins = log_temp + 1;
					logged = true;
				}
				if (user_name == temp_name && pass != temp_pass) {
					cout << "wrong password!" << endl;
					users_in.close();
					users_out.close();
					return false;
				}
			}
			if (logged == true) {
				users_in.seekg(0, ios::beg);
				temp_out.open("temp_data.txt", ios::out | ios::app);
				while (!users_in.eof()){
					users_in >> temp_name;
					users_in >> temp_pass;
					users_in >> log_temp;
					users_in >> admin_temp;
					users_in >> prem_temp;
					if (user_name == temp_name)
						log_temp++;
					temp_out << temp_name << "\n";
					temp_out << temp_pass << "\n";
					temp_out << log_temp << "\n";
					temp_out << admin_temp << "\n";
					temp_out << prem_temp;
					if (users_in.peek() != std::ifstream::traits_type::eof())
						temp_out << "\n";
				}
				users_out.close();
				users_in.close();
				temp_out.close();
				remove("user_data.txt");
				rename("temp_data.txt", "user_data.txt");
				return true;
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
	char choice;
	cout << "signing player 1 " << endl;
	while (!sign_in(p1)) {}
	do {
		cout << "To play against a signed player, press 1\nTo play against guest-players press 2\n";
		cin >> choice;
		if (choice == '2') {
			p2.if_manager = false;
			p2.if_premium = false;
			p2.name = "Guest";
			p2.password = 0;
			break;
		}
		else if (choice == '1') {
			cout << "signing player 2 " << endl;
			while (!sign_in(p2)) {}
		}
		else
			cout << "Wrong input!" << endl;
	} while (choice != '1' && choice != '2');
}

void get_user_data(string& user_name, long int& pass, bool& admin) {
	cout << "Please enter name" << endl;
	cin >> user_name;
	cout << "Please enter password" << endl;
	cin >> pass;
	if (pass == admin_pass)
		admin = 1;
}


void ChangeUserToPremium(string name)
{
	bool flag = true;
	ifstream users_in;
	ofstream users_out;
	User temp;
	users_in.open("user_data.txt");
	users_out.open("temp.txt");
	while (!users_in.eof()) {
		users_in >> temp.name;
		users_in >> temp.password;
		users_in >> temp.logins;
		users_in >> temp.if_manager;
		users_in >> temp.if_premium;
		if (temp.name == name)
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << temp.logins << endl;
			users_out << temp.if_manager << endl;
			users_out << 1;
			if (users_in.peek() != std::ifstream::traits_type::eof())
				users_out << endl;
		}
		else
		{
			users_out << temp.name << endl;
			users_out << temp.password << endl;
			users_out << temp.logins << endl;
			users_out << temp.if_manager << endl;
			users_out << temp.if_premium;
		}
	}
	users_in.close();
	users_out.close();
	remove("user_data.txt");
	rename("temp.txt", "user_data.txt");
}
