#ifndef _USER_TODO_CONVERT_H
#define _USER_TODO_CONVERT_H

#include <vector>
#include <map>
#include "TodoRepo.h"
#include "UserTodo.h"
#include "Todo.h"

class UserTodoConverter
{
public:
	UserTodoConverter() = default;
	virtual bool load(std::map<std::string, UserTodo>& res) = 0;
	virtual unsigned int save(std::map<std::string, UserTodo> data) = 0;
	virtual ~UserTodoConverter() = default;
};

class UserTodoConverterImpl : public UserTodoConverter
{
	TodoRepo* repo;

	Todo calculateFinish(Todo& data);

public:
	UserTodoConverterImpl() = default;
	UserTodoConverterImpl(TodoRepo* repo);

	bool load(std::map<std::string, UserTodo>& res) override;
	unsigned int save(std::map<std::string, UserTodo> data) override;

	virtual ~UserTodoConverterImpl() {	};
};
#endif // !_USER_TODO_CONVERT_H
