#include "DataManage.h"
#include <ctime>

using namespace std;

DataManageImpl::DataManageImpl(TodoRepo* todoRepo, UserTodoConverter* converter)
{
	this->todoRepo = todoRepo;
	this->converter = converter;

	this->converter->load(this->userTodoData);
}
DataManageImpl::~DataManageImpl()
{
	this->converter->save(this->userTodoData);
}
bool DataManageImpl::getCurrentData(vector<Todo>& res, string name)
{
	if (userTodoData.find(name) == userTodoData.end()) {
		//	입력한 데이터가 없는 경우
		return false;
	}
	UserTodo userData = userTodoData[name];
	res = userData.getCurrentData();

	return true;
}

bool DataManageImpl::getFinishedData(vector<Todo>& res, string name)
{
	if (userTodoData.find(name) == userTodoData.end()) {
		//	입력한 데이터가 없는 경우
		return false;
	}
	UserTodo userData = userTodoData[name];
	res = userData.getFinishedData();

	return true;
}

Todo DataManageImpl::addTodoData(string name, Todo data)
{
	time_t timer = time(NULL);
	// YYYY-MM-DD
	struct tm* currentTime = localtime(&timer);

	// 처음추가하는 유저인 경우
	if (userTodoData.find(name) == userTodoData.end()) {
		vector<Todo> current;
		vector<Todo> finish;

		
		UserTodo userData = UserTodo(0, name, current, finish);
		data.setId(0);
		userData.insertData(data);

		userTodoData.insert({name, userData});

		return data;
	}

	// 기존의 유저인 경우
	unsigned int id = userTodoData[name].getId();
	data.setId(id);

	userTodoData[name].insertData(data);
	

	return data;
}

bool DataManageImpl::removeTodoData(string name, unsigned int id) {

	if (userTodoData.find(name) == userTodoData.end()) {
		return false;
	}
	
	userTodoData[name].removeData(id);

	return true;
}