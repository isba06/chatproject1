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

string logIn(const string& username, const string& password, vector<User>& user);

string findUser(const string& username, vector<User>& user);

int findSessionNum(vector<User>& user, const string& userSession);

string getTime();