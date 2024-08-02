#ifndef __DATA_MANAGE_H
#define __DATA_MANAGE_H
#include <map>
#include <string>
#include "UserTodo.h"
#include "TodoRepo.h"
#include "Todo.h"
#include "UserTodoConverter.h"

class Datamanage {
	std::map<std::string, UserTodo> userTodoData;
	TodoRepo *todoStorage;
	UserTodoConverter *converter;
	
public:
	Datamanage() = default;
	Datamanage(TodoRepo* storage, UserTodoConverter* convert);
	~Datamanage();
	bool getUserData(std::vector<Todo>& res, std::string name);
	Todo addTodoData(std::string name, Todo data);
	bool removeTodoData(std::string name, unsigned int id);
	/*Todo modifiyTodoList(std::string name, Todo data, unsigned int id);*/
};

#endif