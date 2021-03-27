#include <iostream>
#include "User.h"



bool User::cmp(std::string username, std::string password)
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

void User::sendMessage(Message message)
{	
	
	_message[_countMessage++] = message;
}