#ifndef __DATA_MANAGE_H
#define __DATA_MANAGE_H
#include <map>
#include <string>
#include "UserTodo.h"
#include "TodoRepo.h"
#include "Todo.h"
#include "UserTodoConverter.h"

class DataManage 
{
	//std::map<std::string, UserTodo> userTodoData;
	//TodoRepo *todoStorage;
	//UserTodoConverter *converter;
	
public:
	DataManage() = default;
	virtual ~DataManage() = default;
	virtual bool getCurrentData(std::vector<Todo>& res, std::string name) = 0;
	virtual bool getFinishedData(std::vector<Todo>& res, std::string name) = 0;
	virtual Todo addTodoData(std::string name, Todo data) = 0;
	virtual bool removeTodoData(std::string name, unsigned int id) = 0;
};

class DataManageImpl : public DataManage
{
	std::map<std::string, UserTodo> userTodoData;
	TodoRepo* todoRepo;
	UserTodoConverter* converter;

	DataManageImpl() = delete;
	DataManageImpl(TodoRepo* todoRepo, UserTodoConverter* converter);

	~DataManageImpl() = default;

	bool getCurrentData(std::vector<Todo>& res, std::string name) override;
	bool getFinishedData(std::vector<Todo>& res, std::string name) override;
	Todo addTodoData(std::string name, Todo data) override;
	bool removeTodoData(std::string name, unsigned int id) override;
};
#endif