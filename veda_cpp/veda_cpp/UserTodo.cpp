#define _CRT_SECURE_NO_WARNINGS

#include "UserTodo.h"
#include <ctime>
#include <iostream>
using namespace std;

UserTodo::UserTodo()
{

}
UserTodo::UserTodo(unsigned int lastIdx, std::string userName, std::vector<Todo> data, std::vector<Todo> finish)
{
	this->lastIdx = lastIdx;
	this->userName = userName;
	this->currentData = data;
	this->finishedData = finish;
}
UserTodo::UserTodo(const UserTodo& obj)
{
	this->lastIdx = obj.lastIdx;
	this->userName = obj.userName;
	this->currentData = obj.currentData;
	this->finishedData = obj.finishedData;
}

unsigned int UserTodo::getId()
{
	unsigned int retVal;
	idxLock.lock();
	retVal = lastIdx;
	idxLock.unlock();

	return retVal;
}

void UserTodo::setId(unsigned int idx)
{
	idxLock.lock();
	lastIdx = idx;
	idxLock.unlock();
}
string UserTodo::getUserName()
{
	return this->userName;
}

vector<Todo> UserTodo::getCurrentData()
{
	return this->currentData;
}
vector<Todo> UserTodo::getFinishedData()
{
	return this->finishedData;
}

void UserTodo::setCurrentData(vector<Todo> data)
{
	this->currentData = data;
}

void UserTodo::setUserName(string userName)
{
	this->userName = userName;
}

void UserTodo::insertData(Todo data)
{
	idxLock.lock();
	currentData.push_back(data);
	if (lastIdx < (data.getId()+1)) {
		lastIdx = data.getId() + 1u;
	}
	idxLock.unlock();
}

void UserTodo::removeData(unsigned int id)
{
	for (auto iter = currentData.begin(); iter != currentData.end(); iter++) {
		if (iter->getId() == id) {
			currentData.erase(iter);

			return;
		}
	}

	for (auto iter = finishedData.begin(); iter != finishedData.end(); iter++) {
		if (iter->getId() == id) {
			finishedData.erase(iter);

			return;
		}
	}
}

void UserTodo::convertData()
{
	time_t timer = time(NULL);
	// YYYY-MM-DD
	struct tm* currentTime = localtime(&timer);

	int day = currentTime->tm_mday;
	int month = (currentTime->tm_mon) + 1;
	int year = currentTime->tm_year + 1900;
	for (auto iter = currentData.begin(); iter != currentData.end(); iter++) {
		string dueDate = iter->getDueDate();

		int firstDash = dueDate.find_first_of('-');
		int secondDash = dueDate.find_last_of('-');

		int dueYear = stoi(dueDate.substr(0, firstDash));
		int dueMonth = stoi(dueDate.substr(firstDash + 1, 2));
		int dueDay = stoi(dueDate.substr(secondDash + 1, 2));
		if (year - dueYear > 0) {
			finishedData.push_back(*iter);
		}
		else if (month - dueMonth > 0) {
			finishedData.push_back(*iter);
		}
		else if (day - dueDay > 0) {
			finishedData.push_back(*iter);
		}
	}
}