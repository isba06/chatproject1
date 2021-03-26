#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector>
#include "User.h"
using namespace std;

void showOptions() {
	cout << "1. Sign in" << endl
		<< "2. Log in" << endl
		<< "0. Exit" << endl;
}

void showOptionsLogedIn() {
	cout<< "2. Log out" << endl
		<< "3. Send message to user" << endl
		<< "4. Send message to everyone" << endl
		<< "0. Exit" << endl;
}

bool isAvailable(const string username, vector<User> user) {
	for (unsigned int i = 0; i < user.size(); i++) {
		if (username == user[i].getUsername())
			return false;
	}
	return true;
}

int logIn(const string& username, const string& password, vector<User> &user) {
	for (unsigned int i = 0; i < user.size(); i++) {
		if (user[i].cmp(username, password)) 
			return i;
		}
	cout << "Incorrect username or password" << endl << endl;
	return -1;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string tmpUsername, tmpName, tmpPassword;
	int ans, count = 0, size = 0, id = -1;
	bool logedIn = false;
	vector<User> user(size);

	do {
		if (logedIn) {
			showOptionsLogedIn();
		} else {
			showOptions();
		}
		cout << "Select action: ";
		cin >> ans;
		cout << endl;

		switch (ans)
		{
		case 1:
			cout << "Input name: ";
			cin >> tmpName;

			cout << "Input username: ";
			cin >> tmpUsername;
			if (!isAvailable(tmpUsername, user)) {
				cout << "This username is already taken" << endl << endl;
				break;
			}

			cout << "Input password: ";
			cin >> tmpPassword;
			cout << endl;

			user.resize(++size);
			user[count].registr(tmpName, tmpUsername, tmpPassword);
			break;

		case 2:
			if (!logedIn) {
				cout << "Input username: ";
				cin >> tmpUsername;
				cout << "Input password: ";
				cin >> tmpPassword;
				cout << endl;
				id = logIn(tmpUsername, tmpPassword, user);
				if(id > -1) {
					cout << "Hello, " << tmpUsername << ", welcome back" << endl << endl;
				logedIn = true;
				} else {
				cout << "Incorrect username or password" << endl << endl;
			    }

			} else {
				cout << "Signed out" << endl << endl;
				id = -1;
				logedIn = false;
			}
			break;

		case 3:
			if (!logedIn) {
				cout << "Select action from the list" << endl << endl;
				break;
			}
			cout << "Input reciever's username: ";

			break;

		case 4:
			if (!logedIn) {
				cout << "Select action from the list" << endl << endl;
				break;
			}
			break;

		case 0:
			ans = 0;
			break;

		default:
			cout << "Select action from the list" << endl << endl;
			break;
		}
	} while (ans != 0);

	return 0;
}