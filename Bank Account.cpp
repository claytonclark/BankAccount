// Bank Account.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct Users {
	string userName;
	string userPassword;
	int pin[4];
};
void login();
void createUser();
bool confirmPassword(string pass);
void optAfterCreate();

string n;
const int maxUsers = 20;
int currentUserNum = 0;
Users userArray[maxUsers];
bool started = false;

int main()
{
	int option;
	if (started == false) {
		cout << "\n   ********Welcome to Your Personal Bank********" << endl << endl;
		started = true;
	}
	cout << "\n   ***Please select what you would like to do***" << endl;
	cout << "\n--Enter 1 --> To access current account" << endl;
	cout << "--Enter 2 --> To create a new account" << endl;
	cout << "--Enter 3 --> To change a existing account" << endl << "\n";
	cin >> option;
	switch (option) {
		case 1:
			//for login
			login();
			break;
		case 2:
			createUser();
			if (currentUserNum == maxUsers) {
				cout << "\nThe maximum number of users have been reached" << endl;
			}
			cout << "\n***YOUR ACCOUNT WAS SUCCESFULLY CREATED***\n" << endl;
			cout << "Your username is " << userArray[currentUserNum].userName << endl;
			cout << "Your password is " << userArray[currentUserNum].userPassword << endl << endl;
			currentUserNum++;
			optAfterCreate();
			break;
		case 3:
			//for appending account
			break;
	}
}

void login() {
	string name;
	string pass;
	bool correct = false;
	cout << "Please Enter Username and Password\n" << endl;
	cout << "Username: ";
	cin >> name;
	cout << "\nPassword: ";
	cin >> pass;
	for (int i = 0; i < maxUsers; i++) {
		if (name == userArray[i].userName && pass == userArray[i].userPassword) {
			cout << "\n***LOGIN SUCCESSFUL***\n";
			correct = true;
		}
	}
	if (correct == false) {
		cout << "\n***YOUR USERNAME OR PASSWORD IS INCORRECT***\n";
		return login();
	}
}

void createUser()
{
	string passTemp;
	Users currentUser;
	bool check = true;
	cout << "--Please enter a username you would like to use--" << endl;
	cin >> currentUser.userName;
	while (check) {
		cout << "\n--Please enter a password you would like to use--" << endl;
		cin >> passTemp;
		if (confirmPassword(passTemp) == true) {
			currentUser.userPassword = passTemp;
			check = false;
		}
	}
	cout << "\n  --Please enter a pin to use one digit at a time. After each digit hit enter--" << endl;
	for (int i = 0; i < 4; i++) {
		cin >> currentUser.pin[i];
	}
	userArray[currentUserNum] = currentUser;
}

bool confirmPassword(string pass) {
	string passConfirm;
	cout << "\n  --Please enter your password again to confirm--" << endl;
	cin >> passConfirm;
	if (pass == passConfirm) {
		return true;
	}
	else {
		cout << "\n   ***The passwords entered do not match***\n";
		cout << "\n   ***Please try again***\n";
		return false;
	}
}

void optAfterCreate() {
	int num;
	cout << "\n   ***Please select what you would like to do***" << endl;
	cout << "\nEnter 1 --> To go back to main menu" << endl;
	cout << "Enter 2 --> To login" << endl;
	cin >> num;
	switch (num) {
		case 1:
			main();
			break;
		case 2:
			login();
			break;
		default:
			optAfterCreate();
			break;
	}
}