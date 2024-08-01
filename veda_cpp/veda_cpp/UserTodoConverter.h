#ifndef _USER_TODO_CONVERT_H
#define _USET_TODO_CONVERT_H
#include <vector>
#include <map>
#include "TodoRepo.h"
#include "UserTodo.h"
#include "Todo.h"

class UserTodoConverter
{
	virtual bool load(std::map<std::string, UserTodo>& res) = 0;
	virtual unsigned int save(std::map<std::string, UserTodo> data) = 0;
};

class UserTodoConverterImpl : public UserTodoConverter
{
	TodoRepo* repo;

	void calculateFinish(std::vector<Todo> data, std::vector<Todo> finish);
public:
	UserTodoConverterImpl(TodoRepo* repo);

	bool load(std::map<std::string, UserTodo>& res) override;
	unsigned int save(std::map<std::string, UserTodo> data) override;
};
#endif // !_USER_TODO_CONVERT_H
