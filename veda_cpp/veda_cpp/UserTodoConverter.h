#ifndef _USER_TODO_CONVERT_H
#include <vector>
#include <map>
#include "UserTodo.h"
#include "Todo.h"

class UserTodoConverter
{
	virtual std::vector<UserTodo> load() = 0;
	virtual unsigned int save(std::map<std::string, UserTodo> data) = 0;
};
#endif // !_USER_TODO_CONVERT_H
