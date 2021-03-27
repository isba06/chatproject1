#include "Message.h"
#include <iostream>
#include <string>
#include "functions.h"

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

void Message::setSender(string sender) {
	_sender = sender;
}

void Message::setAddressee(string addressee) {
	_addressee = addressee;
}

void Message::setMessage(string message) {
	_message = message;
}

void Message::setTime(string time) {
	_time = time;
}