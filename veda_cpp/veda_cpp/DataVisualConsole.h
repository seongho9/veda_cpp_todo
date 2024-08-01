#ifndef __DATA_VISUAL_CONSOLE_H
#define __DATA_VISUAL_CONSOLE_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "UserTodo.h"
#include "Todo.h"
#include "UserTodoConverter.h"
#include "DataManage.h"

class DataVisual
{
public:
	DataVisual() = default;	
	virtual std::vector<Todo> setUserData();
	virtual void showUserDate(std::vector<Todo> v);
	virtual ~DataVisual() = default;
};

class DataVisualConsole : public DataVisual
{
	Datamanage* manage;

public:
	DataVisualConsole() = default;
	std::vector<Todo> setUserData();
	void showUserDate(std::vector<Todo> v);
	~DataVisualConsole() = default;
};



#endif // !__DATA_VISUAL_CONSOLE_H