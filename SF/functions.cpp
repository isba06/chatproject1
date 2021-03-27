#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "User.h"

using namespace std;

void showOptions() {
	cout << "1. Sign in" << endl
		<< "2. Log in" << endl
		<< "0. Exit" << endl;
}

void showOptionsLogedIn() {
	cout << "2. Log out" << endl
		<< "3. Send message to user" << endl
		<< "4. Send message to everyone" << endl
		<< "5. Show history" << endl //закончить
		<< "0. Exit" << endl;
}

bool isBusy(const string& username, vector<User>& user) {
	for (unsigned int i = 0; i < user.size(); i++) {
		if (username == user[i].getUsername())
			return true;
	}
	return false;
}

string logIn(const string& username, const string& password, vector<User>& user) {
	for (unsigned int i = 0; i < user.size(); i++) {
		if (user[i].checkPasswordUsername(username, password))
			return user[i].getUsername();
	}
	cout << "Incorrect username or password" << endl << endl;
	return "";
}

string findUser(const string& username, vector<User>& user) {
	string reciever;
	for (unsigned int i = 0; i < user.size(); i++) {
		reciever = user[i].getUsername();
		if (reciever == username) {
			return reciever;
		}
	}
	return "Not found";
}

int findSessionNum(vector<User>& user, const string& userSession) {
	for (unsigned int i = 0; i < user.size(); i++) {
		if (user[i].getUsername() == userSession)
			return i;
	}
	return -1;
}

string getTime() {
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	stringstream ss;
	struct tm* ptm = localtime(&in_time_t);
	ss << put_time(ptm, "%d-%m-%y %R");
	return ss.str();
}
