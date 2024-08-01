#include "DataManage.h"
#include "DataVisualConsole.h"
#include "Todo.h"
using namespace std;

Datamanage::Datamanage(TodoRepo* storage, UserTodoConverter* convert)
{
	this->todoStorage = storage;
	this->converter = convert;

}

vector<Todo> Datamanage::getUserData(string name)
{
	UserTodo userData = userTodoData[name];
	return userData.getData();
}

Todo Datamanage::addTodoData(string name, Todo data)
{
	vector<Todo> tmp = userTodoData[name].getData();
	tmp.push_back(data);
	return todoStorage->save(data);
}

Todo Datamanage::removeTodoData(string name, unsigned int id) {
	vector<Todo> tmp = userTodoData[name].getData();
	Todo trash_val(0, "", "NO", " ", " ", false, false);
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].getId() == id) {
			Todo data = tmp[i];
			tmp.erase(tmp.begin() + i);
			todoStorage->deleteById(id);
			return data;
		}

	}
	return trash_val;
}

Todo Datamanage::modifiyTodoList(string name, Todo target_data, unsigned int id)
{
	Todo trash_val(0, "", "NO", " ", " ", false, false);
	vector<Todo> tmp = userTodoData[name].getData();
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].getId() == id) {
			Todo data = tmp[i];
			tmp[i] = target_data;
			return data;
		}
	}
	return trash_val;
}

//void Datamanage::showAllUserTodoList(std::string name) 
//{
//	DataVisual show;
//	vector<Todo> tmp = userTodoData[name].getData();
//	for (auto it : tmp) {
//		show.showTodo(it);
//		
//	}
//
//}
