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
	bool _isPrivateMessage {false};
public:
	string getSender() const;
	string getAddressee() const;
	string getMessage() const;
	string getTime() const;
	void setSender(const string& sender);
	void setAddressee(const string& addressee);
	void setMessage(const string& message);
	void setTime(const string& time);
	void setIsPrivateMessage(const bool isPrivateMessage)
	{
		_isPrivateMessage = isPrivateMessage;
	}

	bool getIsPrivateMessage() const
	{
		return _isPrivateMessage;
	}
};

