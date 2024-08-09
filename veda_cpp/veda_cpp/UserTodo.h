#ifndef __USER_TODO_H
#define __USER_TODO_H
#include<string>
#include<vector>
#include<mutex>
#include"Todo.h"

class UserTodo
{
	std::string userName;
	unsigned int lastIdx;

	std::vector<Todo> currentData;
	std::vector<Todo> finishedData;
	std::mutex idxLock;

public:


	UserTodo();
	UserTodo(unsigned int lastIdx, std::string userName, std::vector<Todo> current, std::vector<Todo> finish);
	UserTodo(const UserTodo& obj);

	std::string getUserName();
	std::vector<Todo> getCurrentData();
	std::vector<Todo> getFinishedData();

	unsigned int getId();
	void setId(unsigned int idx);

	void setUserName(std::string userName);
	void setCurrentData(std::vector<Todo> data);

	/// <summary>
	///		Todo를 해당 자료구조에 추가,
	///		이 때, 추가하는 자료구조의 ID가 저장하고 있는 값보다 높으면 갱신
	/// </summary>
	/// <param name="data">추가하고자 하는 데이터</param>
	void insertData(Todo data);
	void removeData(unsigned int id);
	void convertData();
};
#endif // !__USER_TODO_H
