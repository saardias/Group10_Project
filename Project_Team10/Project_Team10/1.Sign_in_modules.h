#define CRT_SECURE_NO_WARNINGS
#define admin_pass 77766613
#include <string>
#include <iostream>
#include <fstream> 
using namespace std;
//function for signing in
bool sign_in() {
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
	cout << "Please enter name" << endl;
	cin >> user_name;
	cout << "Please enter password" << endl;
	cin >> pass;
	if (pass == admin_pass)
		admin = 1;
	switch (choice) {
	case 1:
		if (users_in.peek() == std::ifstream::traits_type::eof()) {
			users_out << admin << "\n";
			users_out << premium << "\n";
			users_out << user_name << "\n";
			users_out << pass << "\n";
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
					exists = 1;
					break;
				}
			}
			if (exists == 0) {
				users_out << admin << "\n";
				users_out << premium << "\n";
				users_out << user_name << "\n";
				users_out << pass << "\n";
				users_in.close();
				users_out.close();
				return true;
			}
			else {
				users_in.close();
				users_out.close();
				return false;
			}
		}
		break;
	case 2:
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
					exists = 1;
					break;
				}
			}
			if (exists == 1) {
				users_in.close();
				users_out.close();
				return true;
			}
			else {
				cout << "User already exist!" << endl;
				users_in.close();
				users_out.close();
				return false;
			}
		}
		break;
	default:
		cout << "Wrong input!" << endl;
		users_in.close();
		users_out.close();
		return false;
		break;
	}
}
