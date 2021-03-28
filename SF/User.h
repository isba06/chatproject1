#pragma once
#include <string>
#include <vector>
#include "Message.h"
using namespace std;

class User
{
private:
	std::string _name;
	std::string _username;
	std::string _password;
	vector<Message> _message; //вектор хранящий объект класса месседж, в котором время, сообщение, от кого и кому
public:
	void registr(std::string name, std::string username, std::string password); //функция регистрации пользователя
	User() = default;
	~User() = default;
	

	std::string getName()
	{
		return _name;
	}

	std::string getUsername()
	{
		return _username;
	}

	std::string getPassword()
	{
		return _password;
	}
	void sendMessage(const string sender, const string reciever, const string message, unsigned int countMessage, bool isPrivate); //отправка сообщения
	void showMessage(); // показать сообщение
};