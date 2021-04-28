#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "User.h"



using namespace std;

void showOptions() {
	cout << "1. Sign in" << endl
		<< "2. Log in" << endl
		<< "0. Exit" << endl << endl;
}

void showOptionsLogedIn() {

	cout << "1. Send message to user" << endl
		<< "2. Send message to everyone" << endl
		<< "3. Show history with certain user" << endl
		<< "4. Show history with all users" << endl
		<< "5. Log Out" << endl 
		<<"6. Change Password"<<endl
		<< "0. Exit" << endl << endl;
}

bool isBusy(const string& username, const vector<User>& user) {
	for (const auto& n : user) 
		if (username == n.getUsername())
			return true;
	return false;
}

bool checkPasswordUsername(const string& username, const string& password, const vector<User>& user)
{
	for (const auto& n : user)
		if ((n.getUsername() == username) && (n.getPassword() == password))
			return true;

	cout << "Incorrect username or password" << endl << endl;
	return false;

}

size_t getIndexUser(const string& username, vector<User>& user)
{
	for (size_t i = 0; i < user.size(); i++) {
		if (!(user[i].getUsername().compare(username)))
			return i;
	}
	return 0; // было -1, но это небезопасно
}


string& findUser(string& username, const vector<User>& user) {

	for (const auto& n : user)
		if (n.getUsername() == username) 
			return username;
	string n = "Not found";
	return n;
}

size_t findSessionNum(vector<User>& user, const string& userSession) {
	for (size_t i = 0; i < user.size(); i++) {
		if (user[i].getUsername() == userSession)
			return i;
	}
	return 0; // было -1, но это небезопасно
}

string getTime() {
	const auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	stringstream ss;
	auto *const ptm = localtime(&in_time_t);
	ss << put_time(ptm, "%d-%m-%y %R");
	return ss.str();
}