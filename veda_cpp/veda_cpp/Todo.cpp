#include "Todo.h"
#include <sstream>

using namespace std;

Todo::Todo(unsigned int id,
	string userName, string content,
	string insertDate, string dueDate,
	bool isDone, bool isFin)
{
	this->id = id;
	this->userName = userName;
	this->content = content;
	this->insertDate = insertDate;
	this->dueDate = dueDate;
	this->isDone = isDone;
	this->isFin = isFin;
}
void Todo::setId(unsigned int id)
{
	this->id = id;
}
void Todo::setContent(string content)
{
	this->content = content;
}
void Todo::setUserName(string userName)
{
	this->userName = userName;
}
void Todo::setInsertDate(string date)
{
	// 0123456789
	// YYYY-MM-DD
	int y = date.find_first_of('-');
	int m = date.find_last_of('-');
	
	if (y != -1 && m != -1) {
		this->insertDate = date;
	}
}
void Todo::setDueDate(string date)
{
	// 0123456789
	// YYYY-MM-DD
	int y = date.find_first_of('-');
	int m = date.find_last_of('-');

	if (y != -1 && m != -1) {
		this->dueDate = date;
	}
}
void Todo::setIsDone(bool isDone)
{
	this->isDone = isDone;
}
void Todo::setIsFin(bool isFin)
{
	this->isFin = isFin;
}

unsigned int Todo::getId() const
{
	return this->id;
}

string Todo::getUserName() const
{
	return this->userName;
}

string Todo::getContent() const
{
	return this->content;
}

string Todo::getInsertDate() const
{
	return this->insertDate;
}

string Todo::getDueDate() const
{
	return this->dueDate;
}

bool Todo::getIsDone() const
{
	return this->isDone;
}

bool Todo::getIsFin() const
{
	return this->isFin;
}

string Todo::toString() const
{
	stringstream ss;

	ss << id << "#";
	ss << userName << "#" << content << "#";
	ss << insertDate << "#" << dueDate << "#";
	ss << isDone << "#" << isFin << "$";
	return ss.str();
}