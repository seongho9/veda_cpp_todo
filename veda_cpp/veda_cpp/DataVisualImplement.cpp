#include "DataVisualConsole.h"
#include "iostream"
#include <string>
#include <vector>
using namespace std;
vector<Todo> DataVisualConsole::setUserData() {
	string name;
	cin >> name;
	return manage->getUserData(name);
}

void DataVisualConsole::showUserDate(vector<Todo> v) {
	vector<Todo> temp = v;
	for (auto iter : temp) {
		cout << "ID : " << iter.getId() << ", name : " << iter.getUserName() << ", Content : " << iter.getContent() <<
			", InsertDate :" << iter.getInsertDate() << ", DueDate : " << iter.getDueDate() << ", Is Done?" << boolalpha << iter.getIsDone() <<
			" Is Finished?" << boolalpha << iter.getIsFin() << endl;
	}
}
