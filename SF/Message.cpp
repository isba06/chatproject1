#include "Message.h"
#include <iostream>
#include <string>

using namespace std;


string Message::getSender()
{
	return _sender;
}

string Message::getAddressee()
{
	return _addressee;
}

string Message::getMessage()
{
	return _message;
}

string Message::getTime()
{
	return _time;
}