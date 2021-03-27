#pragma once
#include <string>
using namespace std;

class Message
{
private:
	string _sender;
	string _addressee;
	string _message;
	string _time;
public:
	string getSender();
	string getAddressee();
	string getMessage();
	string getTime();
	void setSender(string sender);
	void setAddressee(string addressee);
	void setMessage(string message);
	void setTime(string time);
};

