#pragma once

#include <string>
#include <vector>
#include "User.h"

void showOptions();

void showOptionsLogedIn();

bool isBusy(const string& username, const vector<User>& user);

bool checkPasswordUsername(const std::string& username, const std::string& password, const vector<User>& user); //�������� ������������ ������ � ������

string& findUser(string& username, const vector<User>& user);

size_t getIndexUser(const string&, vector<User>& user);

size_t findSessionNum(vector<User>& user, const string& userSession);

string getTime();