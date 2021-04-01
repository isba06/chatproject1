#include <iostream>
#include "User.h"
#include "functions.h"





void User::sendMessage(const string& sender, const string& reciever, const string& message, size_t countMessage, bool isPrivate)
{
	_message.resize(countMessage);
	_message[countMessage - 1].setSender(sender);
	_message[countMessage - 1].setAddressee(reciever);
	_message[countMessage - 1].setMessage(message);
	_message[countMessage - 1].setTime(getTime());
	_message[countMessage - 1].setIsPrivateMessage(isPrivate);
}

void User::showPrivateMessage(const User& sender) {
	for (const auto& a : _message) {
		if (a.getMessage().empty())
			continue;
		if (a.getIsPrivateMessage()) {
			for (const auto& m : sender._message)
			{
				if (a.getAddressee() == m.getAddressee() && a.getSender() == m.getSender()) {
					cout << a.getTime() << " | " << a.getSender() << ": " << a.getMessage() << endl;
					break;
				}
			}
		}
		else continue;
	}
	cout << endl;
}

void User::showMessage() {
	for (const auto& a : _message) {
		if (a.getMessage().empty())
			continue;
		if (!a.getIsPrivateMessage())
			cout << a.getTime() << " | " << a.getSender() << ": " << a.getMessage() << endl;
		else continue;
	}
	cout << endl;
}
