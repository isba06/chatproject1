#pragma once
#include <string>
#include <vector>
#include "Message.h"
using namespace std;



class User
{
private:
	//std::string _id;
	std::string _name;
	std::string _username;
	std::string _password;
	vector<Message> _message;
	static int _countMessage;
public:
	void registr(std::string name, std::string username, std::string password);
	User() = default;
	~User() = default;
	void inMessage(std::string);
	void OutMessage(std::string);
	bool cmp(std::string username, std::string password);
	std::string getName();
	std::string getUsername();
	void sendMessage(Message message);
};