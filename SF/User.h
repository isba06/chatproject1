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
	vector<Message> _message;
	int _notification = 0;
	int _privateNotification = 0;
	vector <string> _notificationUsername;
	vector <string> _privateNotificationUsername;
public:
	void registr(std::string name, std::string username, std::string password);
	User() = default;
	~User() = default;

	void changePassword(string pass)
	{
		_password = pass;
		cout << "Password changed!" << endl << endl;
	}

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

	void sendMessage(const string sender, const string reciever, const string message, unsigned int countMessage, bool isPrivate);
	void showPrivateMessage(User& sender);
	void showMessage();

	int getNotification()
	{
		return _notification;
	}

	int getPrivateNotification()
	{
		return _privateNotification;
	}

	void addNotifications()
	{
		++_notification;
	}

	void addPrivateNotifications()
	{
		++_privateNotification;
	}

	void setNotifications(int notif)
	{
		_notification = notif;
	}

	void setPrivateNotifications(int notif)
	{
		_privateNotification = notif;
	}

	size_t SizeVectorNotificationUsername()
	{
		return _notificationUsername.size();
	}

	size_t SizeVectorPrivateNotificationUsername()
	{
		return _privateNotificationUsername.size();
	}

	void ResizeVectorNotificationUsername(int countVector)
	{
		_notificationUsername.resize(countVector);
	}

	void ResizeVectorPrivateNotificationUsername(int countVector)
	{
		_privateNotificationUsername.resize(countVector);
	}

	void setUsernameNotification(string username, int index)
	{
		_notificationUsername[index] = username;
	}

	void setPrivateUsernameNotification(string username, int index)
	{
		_privateNotificationUsername[index] = username;
	}

	string getUsernameNotification(int index)
	{
		return _notificationUsername[index];
	}

	string getPrivateUsernameNotification(int index)
	{
		return _privateNotificationUsername[index];
	}

	void deleteUsername(string username) {
		string tmp;
		for (int i = 0; i < _privateNotificationUsername.size(); i++) {
			if (_privateNotificationUsername[i] == username) {
				_privateNotificationUsername[i] = _privateNotificationUsername[_privateNotificationUsername.size() - 1];
				_privateNotificationUsername.pop_back();
			}
		}

	}
};