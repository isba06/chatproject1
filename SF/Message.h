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
};

