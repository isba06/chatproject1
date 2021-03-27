#include <iostream>
#include "User.h"



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