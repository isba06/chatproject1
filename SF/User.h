#pragma once
#include <string>
#include <vector>
using namespace std;



class User
{
private:
	//std::string _id;
	std::string _name;
	std::string _username;
	std::string _password;
	int _countInMessage; //порядковый номер для входящего сообщения
	int _countOutMessage;
	std::vector<std::string> _in_message;
	std::vector<std::string> _out_message;
public:
	void registr(std::string name, std::string username, std::string password);
	User() = default;
	~User() = default;
	void inMessage(std::string);
	void OutMessage(std::string);
	bool cmp(std::string username, std::string password);
	std::string getName();
	std::string getUsername();
};