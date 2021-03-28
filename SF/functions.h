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

//Отображение возможных действий в меню
void showOptions(); 

//Отображение возможных действий в меню, если пользователь авторизован
void showOptionsLogedIn(); 

//Проверка имени пользователя на доступность
bool isBusy(const string& username, vector<User>& user); 

//Ищет пользователя по логину и паролю и авторизует его
string logIn(const string& username, const string& password, vector<User>& user); 

//Проверяет наличие указаного пользователя
string findUser(const string& username, vector<User>& user);

//возвращает номер ячейки массива указанного пользователя
int findSessionNum(vector<User>& user, const string& userSession);

//возвращает текущее время
string getTime();