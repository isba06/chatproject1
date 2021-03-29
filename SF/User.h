#pragma once
#include <string>
#include <vector>
#include "Message.h"
#include <vector>
using namespace std;

class User
{
private:
	std::string _name;
	std::string _username;
	std::string _password;
	vector<Message> _message; //вектор хранящий объект класса месседж, в котором время, сообщение, от кого и кому
	int _notification=0;
	vector <string> _notificationUsername;
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

	size_t getMessagesNum() {
		return _message.size();
	}

	void sendMessage(const string sender, const string reciever, const string message, unsigned int countMessage, bool isPrivate); //отправка сообщения
	void showPrivateMessage(User sender); // показать личные сообщения
	void showMessage(); // показать общие сообщение

	int getNotification()
	{
		return _notification;
	}

	void addNotifications()
	{
		++_notification;
	}

	void setNotifications(int notif)
	{
		_notification = notif;
	}

	size_t SizeVectorNotificationUsername()
	{
		return _notificationUsername.size();
	}

	void ResizeVectorNotificationUsername(int countVector)
	{
		_notificationUsername.resize(countVector);
	}

	void setUsernameNotification(string username, int index)
	{
				_notificationUsername[index] = username;
	}

	bool checkConsidenceUsernameNotification(string username)
	{
		for (auto a : _notificationUsername)
			if (a == username)
				return true;
		return false;
	}

	string getUsernameNotification(int index)
	{
		return _notificationUsername[index];
	}
	/*
	void AddValueNotification()
	{
		_value++;
	}

	int getValueNotification()
	{
		return _value;
	}

	void setValueNotification(int value)
	{
		_value = value;
	}
	*/
};