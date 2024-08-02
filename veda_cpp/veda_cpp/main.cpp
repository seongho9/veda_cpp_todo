#include <iostream>
#include <string>
#include <vector>
#include "Todo.h"
#include "DataVisualConsole.h"


int main()
{
	TodoRepo* repo = new TodoRepoFile();
	UserTodoConverter* converter = new UserTodoConverterImpl(repo);
	Datamanage* manager = new Datamanage(repo, converter);
	DataVisualConsole* console = new DataVisualConsole(manager);

	console->start();

	delete console;
	delete manager;
	delete converter;
	delete repo;

	return 0;
}