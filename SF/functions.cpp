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
	cout<< "1. Sign in" << endl
		<< "2. Log in" << endl
		<< "0. Exit" << endl<<endl;
}

void showOptionsLogedIn() {

	cout<< "1. Send message to user" << endl
		<< "2. Send message to everyone" << endl
		<< "3. Show history with certan user" << endl
		<< "4. Show history with all users" << endl
		<< "5. Log Out" << endl
		<< "0. Exit" << endl<<endl;
}

bool isBusy(const string& username, vector<User>& user) {
	for (unsigned int i = 0; i < user.size(); i++) {
		if (username == user[i].getUsername())
			return true;
	}
	return false;
}

bool checkPasswordUsername(string username, string password, vector<User>& user)
{
	for (unsigned int i = 0; i < user.size(); i++) {
		if ((user[i].getUsername() == username) && (user[i].getPassword() == password))
			return true;
	}
	return false;
	cout << "Incorrect username or password" << endl << endl;
}

int getIndexUser(string username, vector<User>& user)
{
	for (unsigned int i = 0; i < user.size(); i++) {
		if ((user[i].getUsername() == username))
			return i;
	}
	return -1;
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