#pragma once
#include <string>
#include <vector>
class User
{
private:
	std::string _id;
	std::string _name;
	std::string _username;
	std::string _password;
	int _countInMessage; //порядковый номер для входящего сообщения
	int _countOutMessage;
	std::vector<std::string> _in_message;
	std::vector<std::string> _out_message;
public:
	User(std::string id, std::string name, std::string username, std::string password) : _id(id), _name(name), _username(username), _password(password), _countInMessage(0), _countOutMessage(0)
	{

	}

	~User() = default;
	
	void inMessage(std::string);
	void OutMessage(std::string);
	bool cmp(std::string username, std::string password);
	bool checkAvailability(std::string username); 
};