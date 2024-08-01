#ifndef __DATA_MANAGE_H
#define __DATA_MANAGE_H
#include <map>
#include <string>
#include "UserTodo.h"
#include "TodoRepo.h"
#include "UserTodoConverter.h"

class Datamanage {
	std::map<std::string, UserTodo> userTodoData;
	TodoRepo *todoStorage;
	UserTodoConverter *converter;
	
public:
	Datamanage(TodoRepo* storage, UserTodoConverter* convert);
	~Datamanage() = default;
	std::vector<Todo> getUserData(std::string name);
	Todo addTodoData(std::string name, Todo data);
	Todo removeTodoData(std::string name, unsigned int id);
	Todo modifiyTodoList(std::string name, Todo data, unsigned int id);
	void showAllUserTodoList(std::string name);
};

#endif