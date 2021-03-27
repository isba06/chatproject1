#include <iostream>
#include "User.h"
#include "functions.h"


bool User::checkPasswordUsername(std::string username, std::string password)
{
	if ((_username == username) && (password == _password))
		return true;
	else return false;

}


std::string User::getName()
{
	return _name;
}



std::string User::getUsername()
{
	return _username;
}



void User::registr(std::string name, std::string username, std::string password)
{
	//_id = id;
	_name = name;
	_username = username;
	_password = password;
}

void User::sendMessage(const string sender, const string reciever, const string message, unsigned int countMessage)
{	
	_message.resize(countMessage);
	_message[countMessage - 1].setSender(sender);
	_message[countMessage - 1].setAddressee(reciever);
	_message[countMessage - 1].setMessage(message);
	_message[countMessage - 1].setTime(getTime());
	
}

void User::showMessage() {
	for (auto a : _message) { //что тут делается
		if (a.getMessage() == "")
			continue;
		cout << a.getTime() << " | " << a.getSender() << ": " << a.getMessage() << endl;
	}
	cout << endl;
}