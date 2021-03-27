#include <iostream>
#include "User.h"



void User::inMessage(std::string in_message)
{
	_in_message[_countInMessage++] = in_message;
}



bool User::cmp(std::string username, std::string password)
{
	if ((_username == username) && (password == _password))
		return true;
	else return false;

}



void User::OutMessage(std::string out_message)
{
	_out_message[_countOutMessage++] = out_message;
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
	_countInMessage = 0;
	_countOutMessage = 0;
}

