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

		vector<Todo> data;
		vector<Todo> fin;

		if (res.find(todo.getUserName()) == res.end()) {


			UserTodo user = UserTodo(todo.getUserName(), data, fin);

			res.insert({ todo.getUserName(), user});
		}

		res[todo.getUserName()].getData().push_back(todo);

		Todo finishTodo = calculateFinish(todo);

		if (finishTodo.getDueDate() != "-1") {
			res[todo.getUserName()].getFinishData().push_back(finishTodo);
		}
	}

	return true;
}
Todo UserTodoConverterImpl::calculateFinish(Todo& data)
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);


	string due = data.getDueDate();
	int y_idx = due.find_first_of('-');
	int m_idx = due.find_last_of('-');

	int year = stoi(due.substr(0, 4)) - t->tm_year + 1900;
	int month = stoi(due.substr(y_idx + 1, m_idx - y_idx - 1)) - t->tm_mon + 1;
	int day = stoi(due.substr(m_idx + 1, 2)) - t->tm_mday;

	if (!((year < 0) || (month < 0) || (day < 0))) {
		return data;
	}
	else {
		Todo fail = Todo();
		fail.setDueDate("-1");

		return fail;
	}
}