#include"TodoRepo.h"

using namespace std;

TodoRepoFile::TodoRepoFile()
{
	output = ofstream();
	input = ifstream();
	dir = "./data";
}


unsigned int TodoRepoFile::saveArray(vector<Todo> data)
{
	int i = 0;
	lock.lock();
	output.open(dir, ios::binary | ios::app);
	output.seekp(ios::beg);
	for (i = 0; i < data.size(); i++) {
		output.write((char*)(&data[i]), sizeof(Todo));
	}
	output.close();
	lock.unlock();

	return i;
}

void TodoRepoFile::load(vector<Todo>& res)
{
	lock.lock();
	input.open(dir, ios::in | ios::binary );
	if (!input.is_open()) {
		output.open(dir, ios::out | ios::binary);
		output.close();
		lock.unlock();

		return;
	}
	input.seekg(ios::beg);
	vector<Todo> tmp;

	while (!input.eof()) {

		if (input.tellg() != ios::beg) {

			input.seekg(-1, ios::cur);
		}
		Todo *buf = new Todo();
		input.read(reinterpret_cast<char*>(buf), sizeof(Todo));
		input.get();
		Todo save = Todo(buf->getId(),
			buf->getUserName(), buf->getContent(),
			buf->getInsertDate(), buf->getDueDate(),
			buf->getIsDone(), buf->getIsFin());
		tmp.push_back(save);
	}
	res.swap(tmp);

	input.close();
	lock.unlock();

}
