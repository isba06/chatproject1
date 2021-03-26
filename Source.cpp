#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector>
#include "User.h"
using namespace std;

string tmpUsername, tmpName, tmpPassword;
int ans, count = 0, size = 0, id = -1;
bool logedIn = false;
vector<User> user(::size);

void showOptions() {
	cout << "1. Регистрация" << endl
		<< "2. Вход" << endl
		<< "0. Выйти из программы" << endl;
}

void showOptionsLogedIn() {
	cout<< "2. Выход" << endl
		<< "3. Отправить сообщение пользователю" << endl
		<< "4. Отправить сообщение всем пользователям" << endl
		<< "0. Выйти из программы" << endl;
}

bool isAvailable(string username, vector<User> user) {
	for (int i = 0; i < user.size(); i++) {
		if (username == user[i].getUsername())
			return false;
	}
	return true;
}

bool signup() {
	cout << "Введите имя: ";
	cin >> tmpName;

	cout << "Введите логин: ";
	cin >> tmpUsername;
	if (!isAvailable(tmpUsername, user)) {
		cout << "Этот логин уже используется" << endl << endl;
		return false;
	}

	cout << "Введите пароль: ";
	cin >> tmpPassword;
	cout << endl;

	user.resize(++::size);
	user[::count].registr(tmpName, tmpUsername, tmpPassword);
	return true;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		if (logedIn) {
			showOptionsLogedIn();
		} else {
			showOptions();
		}
		cout << "Выберете действие: ";
		cin >> ans;
		cout << endl;

		switch (ans)
		{
		case 1:
			signup();
			break;

		case 2:
			if (!logedIn) {
				cout << "Введите логин: ";
				cin >> tmpUsername;
				cout << "Введите пароль: ";
				cin >> tmpPassword;
				cout << endl;

				for (int i = 0; i < user.size(); i++) {
					if (user[i].cmp(tmpUsername, tmpPassword)) {
						cout << "Здравствуйте, " << user[i].getName() << ", вы вошли в систему" << endl << endl;
						logedIn = true;
						id = i;
					}
					else {
						cout << "Неправильный логин или пароль" << endl << endl;
					}
				}

			} else {
				cout << "Вы вышли из системы" << endl << endl;
				id = -1;
				logedIn = false;
			}
			break;

		case 3:
			if (!logedIn) {
				cout << "Выберете действие из списка" << endl << endl;
				break;
			}
			cout << "Введите логин пользователя: ";

			break;

		case 4:
			if (!logedIn) {
				cout << "Выберете действие из списка" << endl << endl;
				break;
			}
			break;

		case 0:
			ans = 0;
			break;

		default:
			cout << "Выберете действие из списка" << endl << endl;
			break;
		}
	} while (ans != 0);

	return 0;
}