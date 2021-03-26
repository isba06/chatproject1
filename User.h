#pragma once
#include <string>
using namespace std;
class User
{
public:
	string getName();
	string getUsername();
	void registr(string name, string username, string password);
	bool cmp(string username, string password);
	bool checkAvailability(string username);

private:
	string _name;
	string _username;
	string _password;
};

