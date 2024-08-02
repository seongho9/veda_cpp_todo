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
public:
	Todo() = default;
	Todo(unsigned int id,
		std::string userName, std::string content,
		std::string insertDate, std::string dueDate,
		bool isDone, bool isFin);
	void setId(unsigned int id);
	void setUserName(std::string userName);
	void setContent(std::string content);
	void setInsertDate(std::string date);
	void setDueDate(std::string date);
	void setIsDone(bool isDone);
	void setIsFin(bool isFin);

	unsigned int getId() const;
	std::string getUserName() const;
	std::string getContent() const;
	std::string getInsertDate() const;
	std::string getDueDate() const;
	bool getIsDone() const;
	bool getIsFin() const;
};
#endif // !__TODO_H
