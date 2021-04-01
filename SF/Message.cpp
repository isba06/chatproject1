#include "Message.h"
#include <string>

using namespace std;


string Message::getSender() const
{
	return _sender;
}

string Message::getAddressee() const
{
	return _addressee;
}

string Message::getMessage() const
{
	return _message;
}

string Message::getTime() const
{
	return _time;
}

void Message::setSender(const string& sender) {
	_sender = sender;
}

void Message::setAddressee(const string& addressee) {
	_addressee = addressee;
}

void Message::setMessage(const string& message) {
	_message = message;
}

void Message::setTime(const string& time) {
	_time = time;
}