#pragma once

#include "functions.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "User.h"

void showOptions();

void showOptionsLogedIn();

bool isBusy(const string& username, vector<User>& user);

bool checkPasswordUsername(std::string username, std::string password, vector<User>& user); //проверка корректности пароля и логина

string findUser(const string& username, vector<User>& user);
int getIndexUser(string, vector<User>& user);

int findSessionNum(vector<User>& user, const string& userSession);

string getTime();

void showUnreadMessages(const vector<User> user, const int reciever);