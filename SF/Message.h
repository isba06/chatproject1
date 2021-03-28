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
	bool _isPrivateMessage;
public:
	string getSender();
	string getAddressee();
	string getMessage();
	string getTime();
	void setSender(string sender);
	void setAddressee(string addressee);
	void setMessage(string message);
	void setTime(string time);
	void setIsPrivateMessage(bool isPrivateMessage)
	{
		_isPrivateMessage = isPrivateMessage;
	}

	bool getIsPrivateMessage()
	{
		return _isPrivateMessage;
	}
};

