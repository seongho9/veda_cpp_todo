#define _CRT_SECURE_NO_WARNINGS

#include "UserTodo.h"
#include <ctime>
#include <iostream>
using namespace std;

UserTodo::UserTodo(std::string userName, std::vector<Todo> data, std::vector<Todo> finish)
{
	this->userName = userName;
	this->data = data;
	this->finishData = finish;
}
UserTodo::UserTodo(const UserTodo& obj)
{
	this->userName = obj.userName;
	this->data = obj.data;
	this->finishData = obj.finishData;
}

string UserTodo::getUserName()
{
	return this->userName;
}

vector<Todo>& UserTodo::getData()
{
	return this->data;
}
vector<Todo>& UserTodo::getFinishData()
{
	return this->finishData;
}

void UserTodo::setData(vector<Todo> data)
{
	this->data = data;
}

void UserTodo::setUserName(string userName)
{
	this->userName = userName;
}

void UserTodo::moveToFinish(unsigned int id)
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	for (auto todo : this->data) {
		
		string due = todo.getDueDate();
		int y_idx = due.find_first_of('-');
		int m_idx = due.find_last_of('-');

		int year = stoi(due.substr(0, 4)) - t->tm_year - 1900;
		int month = stoi(due.substr(y_idx + 1, m_idx - y_idx - 1)) - (t->tm_mon + 1);
		int day = stoi(due.substr(m_idx + 1, 2)) - t->tm_mday;

		if (((year < 0) || (month < 0) || (day < 0))) {
			todo.setIsFin(true);
			finishData.push_back(todo);
		}
	}
}