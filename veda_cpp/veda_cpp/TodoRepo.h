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
	virtual unsigned int saveArray(std::vector<Todo> data) = 0;
	virtual void load(std::vector<Todo>& res) = 0;
};

class TodoRepoFile : public TodoRepo
{
private:
	std::ofstream output;
	std::ifstream input;
	std::string dir;
	std::mutex lock;
public:

	TodoRepoFile();
	unsigned int saveArray(std::vector<Todo> data);
	void load(std::vector<Todo>& res);

};
#endif // !_TODO_REPO_H
