#define _CRT_SECURE_NO_WARNINGS

#include "UserTodoConverter.h"
#include <ctime>
#include <map>
using namespace std;

UserTodoConverterImpl::UserTodoConverterImpl(TodoRepo* repo)
{
	this->repo = repo;
}

unsigned int UserTodoConverterImpl::save(map<string, UserTodo> data)
{
	unsigned int i = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++) {

		vector<Todo> currentTodo = iter->second.getCurrentData();
		repo->saveArray(currentTodo);

		vector<Todo>  finishTodo = iter->second.getFinishedData();
		repo->saveArray(finishTodo);

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

		//	map에 유저가 없으면 추가
		if (res.find(todo.getUserName()) == res.end()) {

			vector<Todo> data;
			vector<Todo> fin;
			
			UserTodo user = UserTodo(0U, todo.getUserName(), data, fin);

			res.insert({ todo.getUserName(), user});
		}

		//	todo를 해당 UserTodo에 추가
		res[todo.getUserName()].insertData(todo);

	}
	//	이미 끝난일 분류
	for (auto userTodo : res) {
		userTodo.second.convertData();
	}
	return true;
}