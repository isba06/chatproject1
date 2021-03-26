#include "User.h"
#include <iostream>

using namespace std;

void User::registr(string name, string username, string password) {
	_name = name;
	_username = username;
	_password = password;
	cout << "Регистрация успешна!" << endl << endl;
}

bool User::cmp(string username, string password) {
	if (username == _username && password == _password)
		return true;
	return false;
}

string User::getName() {
	return this->_name;
}

string User::getUsername() {
	return this->_username;
}

bool User::checkAvailability(string username) {
	if (_username == username)
		return false;
	return true;
}