#include <iostream>
#include <string>
#include "Todo.h"

int main()
{
	Todo t1;
	t1.setId(1);
	t1.setContent("sleeping");
	t1.setUserName("hong");
	t1.setInsertDate("2024-08-01");
	t1.setDueDate("2024-12-25");
	t1.setIsDone(true);
	t1.setIsFin(false);
}