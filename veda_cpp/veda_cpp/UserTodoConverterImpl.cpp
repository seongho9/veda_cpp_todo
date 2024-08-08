#define _CRT_SECURE_NO_WARNINGS

#include "UserTodoConverter.h"
#include <ctime>
using namespace std;

UserTodoConverterImpl::UserTodoConverterImpl(TodoRepo* repo)
{
	this->repo = repo;
}

unsigned int UserTodoConverterImpl::save(map<string, UserTodo> data)
{
	unsigned int i = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++) {

		vector<Todo> todo = iter->second.getData();

		repo->saveArray(todo);

		i++;
	}

	return i;
}

bool UserTodoConverterImpl::load(map<std::string, UserTodo>& res)
{
	vector<Todo> data;

	this->repo->load(data);

	if (data.empty()) {
		return false;
	}
	
	for (auto todo : data) {

		if (res.find(todo.getUserName()) == res.end()) {

			vector<Todo> data;
			vector<Todo> fin;

			UserTodo user = UserTodo(todo.getUserName(), data, fin);

			res.insert({ todo.getUserName(), user});
		}

		vector<Todo>& userData = (res[todo.getUserName()].getData());
		userData.push_back(todo);
		
	}
	return true;
}