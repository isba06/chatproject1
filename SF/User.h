#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Message.h"
using namespace std;

class User
{
private:
	string _name;
	string _username;
	string _password;
	vector<Message> _message;
	size_t _notification = 0;
	size_t _privateNotification = 0;
	vector <string> _notificationUsername;
	vector <string> _privateNotificationUsername;
public:
	User(const string& name, const string& username, const string& password) : _name(name), _username(username),  // NOLINT(modernize-pass-by-value)
	                                                                           _password(password)
	{
	}
	User() = default;
	~User() = default;
	
	void changePassword()
	{
		string pass, newpass;
		cout << "Enter 0 to cancel" << endl;
		cout << "Enter old password: ";
		cin >> pass;
		if (pass == "0")
			return;
		if (pass == _password) {
			cout << "Enter new password: ";
			cin >> newpass;
			_password = newpass;
			cout << "Password changed!" << endl << endl;
		}
		else { cout << "Incorrect password" << endl << endl; }
	}

	std::string getName() const
	{
		return _name;
	}

	std::string getUsername() const
	{
		return _username;
	}

	std::string getPassword() const
	{
		return _password;
	}

	size_t getMessagesNum() const {
		return _message.size();
	}

	void sendMessage(const string& sender, const string& reciever, const string& message, size_t countMessage, bool isPrivate);
	void showPrivateMessage(const User& sender);
	void showMessage();

	size_t getNotification() const
	{
		return _notification;
	}

	size_t getPrivateNotification() const
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

	void setNotifications(const size_t notif)
	{
		_notification = notif;
	}

	void setPrivateNotifications(const size_t notif)
	{
		_privateNotification = notif;
	}

	size_t SizeVectorNotificationUsername() const
	{
		return _notificationUsername.size();
	}

	size_t SizeVectorPrivateNotificationUsername() const
	{
		return _privateNotificationUsername.size();
	}

	void ResizeVectorNotificationUsername(const size_t countVector)
	{
		_notificationUsername.resize(countVector);
	}

	void ResizeVectorPrivateNotificationUsername(const size_t countVector)
	{
		_privateNotificationUsername.resize(countVector);
	}

	void setUsernameNotification(const string& username, const size_t index)
	{
		_notificationUsername[index] = username;
	}

	void setPrivateUsernameNotification(const string& username, const size_t index)
	{
		_privateNotificationUsername[index] = username;
	}

	string getUsernameNotification(const size_t index)
	{
		return _notificationUsername[index];
	}

	string getPrivateUsernameNotification(const size_t index)
	{
		return _privateNotificationUsername[index];
	}

	void deleteUsername(const string& username) {
		for (auto const it = _privateNotificationUsername.begin(); it != _privateNotificationUsername.end(); )
			if (*it == username) {
				_privateNotificationUsername.erase(it);
				break;
			}
	}
};