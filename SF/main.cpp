#define _CRT_SECURE_NO_WARNINGS

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
#include "functions.h"
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string tmpUsername, tmpName, tmpPassword, reciever = "", sender, message;
	char ans;
	unsigned int count = 0, size = 0, sessionNum = -1, countMessage = 0;
	bool logedIn = false;
	vector<User> user(size);


	do {

		if (!logedIn) {			
		
		showOptions();
		sessionNum = -1;
		cout << "Select action: ";
		cin >> ans;
		cout << endl;
			switch (ans)
			{
				
			case '1':
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
				user[count++].registr(tmpName, tmpUsername, tmpPassword);
				break;

			case '2':
				cout << "Input username: ";
				cin >> tmpUsername;
				cout << "Input password: ";
				cin >> tmpPassword;
				cout << endl;

				if (checkPasswordUsername(tmpUsername, tmpPassword, user)) {
					cout << "Hello, " << tmpUsername << ", welcome back" << endl << endl;
					logedIn = true;
					break;
				}
				break;
			case '0':
				ans = 0;
				break;

			default:
				cout << "Select action from the list" << endl << endl;
				break;
			}
		}

		if(logedIn){
			showOptionsLogedIn();
			sessionNum = findSessionNum(user, tmpUsername);
			cout << "Select action: ";
			cin >> ans;
			cout << endl;
			switch (ans){
				case '1':
					cout << "Input reciever's username: ";
					cin >> tmpUsername;
					cout << endl;

					reciever = findUser(tmpUsername, user);
					if (reciever == "Not found") {
						cout << "User not found" << endl << endl;
						reciever = "";
						break;
					}

					cout << "To exit input 0" << endl;
					while (message != "0") {
						cout << getTime() << " | " << "You: ";
						getline(cin, message);
						if (message == "0") {
							message = "";		//зачем
							break;
						}
						if (message == "")
							getline(cin, message);
						user[sessionNum].sendMessage(user[sessionNum].getUsername(), reciever, message, ++countMessage, true);
						user[findSessionNum(user, reciever)].sendMessage(user[sessionNum].getUsername(), reciever, message, ++countMessage, true);
					}
					cout << endl;
					break;

				case '2':
					cout << "To exit input 0" << endl;
					while (message != "0") {
						cout << getTime() << " | " << "You: ";
						getline(cin, message);
						if (message == "0") {
							message = "";
							break;
						}
						if (message == "")
							getline(cin, message);
						for (unsigned int i = 0; i < user.size(); i++) {
							user[i].sendMessage(user[sessionNum].getUsername(), user[i].getUsername(), message, ++countMessage, false);
						}
					}
					cout << endl;
					break;				


				case '3':
					cout << "Input username: ";
					cin >> tmpUsername;
					cout << endl;

					sender = findUser(tmpUsername, user);
					if (reciever == "Not found") {
						cout << "User not found" << endl << endl;
						reciever = "";
						break;
					}
					user[sessionNum].showPrivateMessage(sender);
					break;

				case '4':
					user[sessionNum].showMessage();
					break;

				case '5':
					cout << "Signed out" << endl << endl;
					logedIn = false;
					break;

				case '0':
					ans = 0;
					break;

				default:
					cout << "Select action from the list" << endl << endl;
					break;
			}
		}

	} while (ans != 0);

	return 0;
}