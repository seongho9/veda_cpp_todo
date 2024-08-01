#ifndef _TODO_REPO_H
#define _TODO_REPO_H
#include "Todo.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <mutex>

class TodoRepo
{
public:
	TodoRepo() = default;
	virtual ~TodoRepo() = default;
	/// <summary>
	/// Todo 데이터 1개 영구 저장
	/// </summary>
	/// <param name="data"> 저장할 Todo 객체</param>
	/// <returns>저장된 Todo 객체</returns>
	virtual Todo& save(Todo& data) = 0;
	/// <summary>
	/// vector<Todo>에 존재하는 모든 데이터를 영구 저장
	/// 프로그램 종료시 호출
	/// </summary>
	/// <param name="data"> 저장할 Todo 배열</param>
	/// <returns>저장된 객체 수</returns>
	virtual unsigned int saveArray(std::vector<Todo> data) = 0;
	/// <summary>
	/// Todo의 id를 넣으면 해당하는 Todo를 영구 저장소에서 삭제
	/// </summary>
	/// <param name="id">Todo의 id</param>
	/// <returns>삭제한 객체의 id</returns>
	virtual unsigned int deleteById(unsigned int id) = 0;
	/// <summary>
	/// 프로그램 시작 시 영구 저장소의 Todo 데이터 모두 가져옴
	/// </summary>
	/// <returns> Todo 데이터의 배열</returns>
	virtual std::vector<Todo>& load() = 0;
	/// <summary>
	/// Todo 데이터를 수정
	/// </summary>
	/// <param name="id"> 수정하고자 하는 Todo의 id</param>
	/// <param name="data">수정하고자하는 완전한 Todo 객체</param>
	/// <returns> 저장한 Todo객체</returns>
	virtual Todo& modify(unsigned int id, Todo data) = 0;
};

class TodoRepoFile : public TodoRepo
{
private:
	std::fstream file;
	std::mutex lock;

public:

	Todo& save(Todo& data);

	unsigned int saveArray(std::vector<Todo> data);
	unsigned int deleteById(unsigned int id);
	std::vector<Todo>& load();
	Todo& modify(unsigned int id, Todo data);

};
#endif // !_TODO_REPO_H
