#include <string>
#include <vector>
#include "DataVisualConsole.h"
#include "iostream"
#include "DataManage.h"
#include <vector>
using namespace std;

DataVisualConsole::DataVisualConsole(Datamanage* manage)
{
	this->manage = manage;
}

vector<Todo> DataVisualConsole::setUserData() {
	string name;
	cout << "이름을 입력해 주세요.";
	cin >> name;
	vector<Todo> res;
	manage->getUserData(res, name);
	return res;
}

void DataVisualConsole::ShowOneData(Todo TodoData) {
	cout
		<< "ID : " << TodoData.getId()
		<< ", name : " << TodoData.getUserName()
		<< ", Content : " << TodoData.getContent()
		<< ", InsertDate :" << TodoData.getInsertDate()
		<< ", DueDate : " << TodoData.getDueDate()
		<< ", Is Done?" << boolalpha << TodoData.getIsDone() <<
		" Is Finished?" << boolalpha << TodoData.getIsFin() << endl;
}

void DataVisualConsole::showUserData(vector<Todo> v) {
	if (v.size() == 0) {
		cout << "입력된 데이터가 없습니다." << endl;
		return;
	}
	for (auto iter : v) {
		ShowOneData(iter);
	}
}

void DataVisualConsole::start()
{
	cout << "Todo 프로그램 입니다." << endl;
	int i = -1;
	do {
		cout << "출력 : 1, 입력 : 2, 제거 : 3 종료 : -1 \n ---메뉴를 선택하세요---" << endl;
		cout << "번호 입력 : ";
		cin >> i;
		if (i == 1) {
			vector<Todo> UserDatas = setUserData();
			showUserData(UserDatas);
		}
		else if (i == 2) {
			cout << "삽입할 데이터를 입력해 주세요"<<endl;
			unsigned int id;
			string userName, content, insertDate, dueDate;
			cout << "이름 >> ";
			cin >> userName;
			cout << userName << endl;
			cout << "아이디 >> ";
			cin >> id;
			cout << id << endl;
			cout << (unsigned int)id << endl;
			cout << "내용 >> ";
			cin >> content;
			cout << content << endl;
			cout << "추가일자 >> ";
			cin >> insertDate;
			cout << insertDate << endl;
			cout << "마감일자 >> ";
			cin >> dueDate;
			cout << dueDate << endl;
			Todo Data;
			Data.setId(id);
			Data.setUserName(userName);
			Data.setContent(content);
			Data.setInsertDate(insertDate);
			Data.setDueDate(dueDate);
			Data.setIsDone(false);
			Data.setIsDone(false);
			Todo resultData = this->manage->addTodoData(userName, Data);
			ShowOneData(resultData);
		}
		else if (i == 3) {
			cout << "제거할 데이터를 입력해 주세요";
			int id;
			string userName;
			cin >> userName >> id;
			bool result = this->manage->removeTodoData(userName, id);
			cout << "Result : " << boolalpha << result << endl;
		}
	} while (i != -1);

}
