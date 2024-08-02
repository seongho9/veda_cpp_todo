#ifndef __USER_TODO_H
#define __USER_TODO_H
#include<string>
#include<vector>
#include"Todo.h"

class UserTodo
{
	std::string userName;
	std::vector<Todo> data;
	std::vector<Todo> finishData;
public:

	UserTodo() = default;
	UserTodo(std::string userName, std::vector<Todo> data, std::vector<Todo> finish);
	UserTodo(const UserTodo& obj);

	std::string getUserName();
	std::vector<Todo> getData();
	std::vector<Todo> getFinishData();

	void setUserName(std::string userName);
	void setData(std::vector<Todo> data);

	/// <summary>
	/// data에 있는 정보 중 해당 데이터가 만료일이 지났으면, finishData 벡터로 옮김
	/// </summary>
	/// <param name="id"> finishData로 옮길 Todo 객체의 id</param>
	void moveToFinish(unsigned int id);
};
#endif // !__USER_TODO_H
