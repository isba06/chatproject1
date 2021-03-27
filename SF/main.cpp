#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
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
		if (user[i].cmp(username, password))
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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string tmpUsername, tmpName, tmpPassword, reciever = "", sender, message, userSession;
	unsigned int ans, count = 0, size = 0, sessionNum = -1;
	bool logedIn = false;
	vector<User> user(size);
	vector<string>::iterator it;

	do {
		if (logedIn) {
			showOptionsLogedIn();
		}
		else {
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
			if (isBusy(tmpUsername, user)) {
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
				userSession = logIn(tmpUsername, tmpPassword, user);
				if (userSession != "") {
					cout << "Hello, " << tmpUsername << ", welcome back" << endl << endl;
					logedIn = true;
				}
				else {
					break;
				}

			}
			else {
				cout << "Signed out" << endl << endl;
				userSession = "";
				logedIn = false;
			}
			break;

		case 3:
			if (!logedIn) {
				cout << "Select action from the list" << endl << endl;
				break;
			}
			cout << "Input reciever's username: ";
			cin >> tmpUsername;
			cout << endl;

			reciever = findUser(tmpUsername, user);
			if (reciever == "Not found") {
				cout << "User not found" << endl << endl;
				reciever = "";
				break;
			}

			sessionNum = findSessionNum(user, userSession);

			cout << "To exit input 0" << endl;

				//user[sessionNum].sendMessage(reciever);
			while (message != "0")
			{
				cout << "Message: ";
				getline(cin, message);
			}

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