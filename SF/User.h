#pragma once
#include <string>
#include <vector>
class User
{
private:
	std::string _id;
	std::string _name;
	std::string _surname;
	std::vector<std::string> _in_message;
	std::vector<std::string> _out_message;
public:
	User(std::string id, std::string name, std::string surname) : _id(id), _name(name), _surname(surname)
	{

	}
	User(std::string id, std::string name) : _id(id), _name(name)
	{

	}
	~User() = default;

};