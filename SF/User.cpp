#include <iostream>
#include "User.h"
#include "functions.h"





void User::registr(std::string name, std::string username, std::string password)
{
	_name = name;
	_username = username;
	_password = password;
}

void User::sendMessage(const string sender, const string reciever, const string message, unsigned int countMessage, bool isPrivate)
{
	_message.resize(countMessage);
	_message[countMessage - 1].setSender(sender);
	_message[countMessage - 1].setAddressee(reciever);
	_message[countMessage - 1].setMessage(message);
	_message[countMessage - 1].setTime(getTime());
	_message[countMessage - 1].setIsPrivateMessage(isPrivate);
}

void User::showPrivateMessage(User& sender) {
	for (auto a : _message) {
		if (a.getMessage() == "")
			continue;
		if (a.getIsPrivateMessage()) {
			for (int i = 0; i < sender._message.size(); i++)
			{
				if (a.getAddressee() == sender._message[i].getAddressee() && a.getSender() == sender._message[i].getSender())
					cout << a.getTime() << " | " << a.getSender() << ": " << a.getMessage() << endl;
			}
		}
		else continue;
	}
	cout << endl;
}

void User::showMessage() {
	for (auto a : _message) {
		if (a.getMessage() == "")
			continue;
		if (!a.getIsPrivateMessage())
			cout << a.getTime() << " | " << "Group:: " << a.getSender() << ": " << a.getMessage() << endl;
		else continue;
	}
	cout << endl;
}
