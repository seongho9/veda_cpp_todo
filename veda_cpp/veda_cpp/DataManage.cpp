#include "DataManage.h"

using namespace std;

Datamanage::Datamanage(TodoRepo* storage, UserTodoConverter* convert)
{
	this->todoStorage = storage;
	this->converter = convert;
	this->converter->load(this->userTodoData);
}
Datamanage::~Datamanage()
{
	this->converter->save(this->userTodoData);
}
bool Datamanage::getUserData(vector<Todo>& res, string name)
{
	//if (userTodoData.find(name) == userTodoData.end()) {
	//	//	입력한 데이터가 없는 경우
	//	
	//	vector<Todo> retval;
	//	return retval;
	//}
	UserTodo userData = userTodoData[name];
	res = userData.getData();
	return true;
}

Todo Datamanage::addTodoData(string name, Todo data)
{
	if (userTodoData.find(name) == userTodoData.end()) {
		vector<Todo> vec;
		vector<Todo> fin;
		UserTodo userData = UserTodo(name, vec, fin);
		userData.getData().push_back(data);
		userTodoData.insert({name, userData});

		return data;
	}

	vector<Todo> todoData = userTodoData[name].getData();
	todoData.push_back(data);

	Todo saveData = todoStorage->save(data);

	return saveData;
}

bool Datamanage::removeTodoData(string name, unsigned int id) {

	vector<Todo> todos = userTodoData[name].getData();
	

	for (int i = 0; i < todos.size(); i++) {
		if (todos[i].getId() == id) {
			todos.erase(todos.begin() + i);
			unsigned int removedId = todoStorage->deleteById(id);

			return (removedId == id) ? true : false;
		}
	}
	return false;
}

//Todo Datamanage::modifiyTodoList(string name, Todo target_data, unsigned int id)
//{
//	Todo trash_val(0, "", "NO", " ", " ", false, false);
//	vector<Todo> tmp = userTodoData[name].getData();
//	for (int i = 0; i < tmp.size(); i++) {
//		if (tmp[i].getId() == id) {
//			Todo data = tmp[i];
//			tmp[i] = target_data;
//			return data;
//		}
//	}
//	return trash_val;
//}

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
