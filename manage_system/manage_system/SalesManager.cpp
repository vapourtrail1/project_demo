#include "SalesManager.h"
#include <iostream>
using namespace std;

SalesManager::SalesManager(string no, string name, int age, double sales)
	: Staff(no, name, age)
	, Salesman(no, name, age, sales)//把父类的构造函数都得初始化了
	, Manager(no, name, age)
{}

SalesManager::~SalesManager() {}

void SalesManager::showData() const {
	cout << "编号:" << no
		<< " 姓名:" << name
		<< " 年龄:" << age
		<< " 职称:SalesManager"
		<< " 销售额:" << sales
		<< endl;
}

string SalesManager::getTitle() const { return "SalesManager"; }
