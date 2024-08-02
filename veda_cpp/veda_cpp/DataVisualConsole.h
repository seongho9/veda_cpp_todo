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
	virtual void start () = 0;
	virtual ~DataVisual() = default;
};

class DataVisualConsole : public DataVisual
{
	Datamanage* manage;

	std::vector<Todo> setUserData();
	void ShowOneData(Todo TodoData);
	void showUserData(std::vector<Todo> v);
public:
	DataVisualConsole() = delete;
	DataVisualConsole(Datamanage* manage);
	void start();
	~DataVisualConsole() = default;
};



#endif // !__DATA_VISUAL_CONSOLE_H