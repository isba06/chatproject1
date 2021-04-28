#include <iostream>
#include "User.h"
#include "functions.h"





void User::sendMessage(const string& sender, const string& reciever, const string& message, bool isPrivate)
{
	Message a;
	_message.push_back(a);
	_message.back().setSender(sender);
	_message.back().setAddressee(reciever);
	_message.back().setMessage(message);
	_message.back().setTime(getTime());
	_message.back().setIsPrivateMessage(isPrivate);
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
