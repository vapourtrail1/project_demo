#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman(string no, string name, int age, double sales)
	: Staff(no, name, age), sales(sales) {}
//父类的构造函数必须在子类构造函数的初始化列表里被调用
//“Salesman(...) 是用来接收传进来的数据的，
//: Staff(...), sales(...) 是用来把这些数据一开始就初始化给对应的成员变量的。”
Salesman::~Salesman() {}

void Salesman::showData() const {//重写函数
	cout << "编号:" << no
		<< " 姓名:" << name
		<< " 年龄:" << age
		<< " 职称:Salesman"
		<< " 销售额:" << sales
		<< endl;
}

string Salesman::getTitle() const { return "Salesman"; }//展示职称

double Salesman::getSales() const { return sales; }//返回薪水
void Salesman::setSales(double s) { sales = s; }
