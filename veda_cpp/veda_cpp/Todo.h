#ifndef __TODO_H
#define __TODO_H
#include <string>

class Todo
{
	unsigned int id;

	std::string userName;
	std::string content;

	std::string insertDate;
	std::string dueDate;

	bool isDone;
	bool isFin;

	void setId(unsigned int id);
	void setUserName(std::string userName);
	void setContent(std::string content);
	void setinsertDate(std::string date);
	void setdueDate(std::string date);
	void setIsDone(bool isDone);
	void setIsFin(bool isFin);

	unsigned int getId();
	std::string getUserName();
	std::string getContent();
	std::string getInsertDate();
	std::string getDueDate();
	bool getIsDone();
	bool getIsFin();
};
#endif // !__TODO_H
