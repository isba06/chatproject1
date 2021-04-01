#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include "User.h"
#include "functions.h"
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string tmpUsername, tmpName, tmpPassword, reciever, sender, message, currentUser;
	char ans {0};
	size_t countMessage {0}, countPrivateNotification {0}, countNotification {0};
	size_t sessionNum {0}, notifNum {0}, recieverNum {0} ;
	bool logedIn {false};
	vector<User> user;

	do {
		//меню и действия до авторизцаии
		if (!logedIn) {

			showOptions();
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

				user.emplace_back(User(tmpName, tmpUsername, tmpPassword));
				break;

			case '2':
				cout << "Input username: ";
				cin >> tmpUsername;
				cout << "Input password: ";
				cin >> tmpPassword;
				cout << endl;

				if (checkPasswordUsername(tmpUsername, tmpPassword, user)) {
					logedIn = true;//идентификатор авторизации
					currentUser = tmpUsername;
					notifNum = user[getIndexUser(currentUser, user)].getPrivateNotification() + user[getIndexUser(currentUser, user)].getNotification();
					cout << "Hello, " << user[findSessionNum(user, currentUser)].getName() << ", welcome back" << endl << endl;
					cout << "You have " << notifNum << " new messages "<<endl;
					if (notifNum) {
						cout << "from:" << endl;
						//уведомления личных сообщений
						for (size_t i = 0; i < user[getIndexUser(currentUser, user)].SizeVectorPrivateNotificationUsername(); i++) {
							cout << "-" << user[getIndexUser(currentUser, user)].getPrivateUsernameNotification(i) << endl;
						}
						//уведомления групповых
						for (size_t i = 0; i < user[getIndexUser(currentUser, user)].SizeVectorNotificationUsername(); i++) {
							cout << "-" << user[getIndexUser(currentUser, user)].getUsernameNotification(i) << endl;
						}
						cout << endl;
					}
					else { cout << endl; }
				}
				else {
					cout << "Incorrect username or password" << endl;
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

		//после авторизации
		if (logedIn) {
			sessionNum = findSessionNum(user, currentUser);
			showOptionsLogedIn();
			cout << "Select action: ";
			cin >> ans;
			cout << endl;
			switch (ans) {

				//регистрация
			case '1':
				cout << "Input reciever's username: ";
				cin >> tmpUsername;
				cout << endl;

				reciever = findUser(tmpUsername, user);

				if (reciever == "Not found") {
					cout << "User not found" << endl << endl;
					reciever.clear();
					break;
				}
				recieverNum = findSessionNum(user, reciever);

				cout << "To exit enter '-e'" << endl;
				while (message != "-e") {
					cout << getTime() << " | " << "You: ";
					getline(cin, message);
					if (message == "-e") {
						message.clear();
						break;
					}
					if (message.empty())
						getline(cin, message);
					//запись в поле(вектор класса messege) и отправителю и получателю
					user[sessionNum].sendMessage(currentUser, reciever, message, ++countMessage, true);
					user[recieverNum].sendMessage(currentUser, reciever, message, countMessage, true);

					user[recieverNum].ResizeVectorPrivateNotificationUsername(++countPrivateNotification);
					user[recieverNum].setPrivateUsernameNotification(user[sessionNum].getUsername(), countPrivateNotification);
				}
				user[recieverNum].addPrivateNotifications();
				++countPrivateNotification;
				cout << endl;
				message.clear();
				break;

				//отправка сообщений всем участникам
			case '2':
				cout << "To exit enter '-e'" << endl;
				while (message != "-e") {
					cout << getTime() << " | " << "You: ";
					getline(cin, message);
					if (message == "-e") {
						message.clear();
						break;
					}
					if (message.empty())
						getline(cin, message);
					for (unsigned int i = 0; i < user.size(); i++) {
						user[i].sendMessage(user[sessionNum].getUsername(), user[i].getUsername(), message, ++countMessage, false);
						if (i != sessionNum) {
							user[i].addNotifications();
							user[i].ResizeVectorNotificationUsername(++countNotification);
							user[i].setUsernameNotification("Group:: " + user[sessionNum].getUsername(), countNotification);
						}
						else { continue; }

					}
				}
				cout << endl;
				break;

				//вывод личных сообщений от конкретного пользователя
			case '3':
				cout << "Input username: ";
				cin >> tmpUsername;
				cout << endl;

				sender = findUser(tmpUsername, user);
				if (sender == "Not found") {
					cout << "User not found" << endl << endl;
					sender.clear();
					break;
				}
				user[sessionNum].showPrivateMessage(user[findSessionNum(user, sender)]);
				user[sessionNum].setPrivateNotifications(--countPrivateNotification);
				user[sessionNum].deleteUsername(sender);
				break;

				//вывод групповых сообщений
			case '4':
				user[sessionNum].showMessage();
				user[sessionNum].setNotifications(0);
				user[sessionNum].ResizeVectorNotificationUsername(0);
				break;

			case '5':
				cout << "Signed out" << endl << endl;
				logedIn = false;
				break;
			case '6':
				
				user[sessionNum].changePassword();
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