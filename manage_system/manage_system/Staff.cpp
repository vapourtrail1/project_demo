#include "Staff.h"

Staff::Staff(string no, string name, int age) {
	this->no = no;
	this->name = name;
	this->age = age;
}

Staff::~Staff() {}

// 简单返回／修改成员
string Staff::getNo() const { return no; }
void Staff::setNo(string no) { this->no = no; }//把外面传进来的编号，写进这个具体的对象的编号字段里
//传入的编号 ，设置成自己的编号
//把传入的东西赋值给当前对象的数据成员/成员变量no
string Staff::getName() const { return name; }
void Staff::setName(string name) { this->name = name; }

int Staff::getAge() const { return age; }
void Staff::setAge(int age) { this->age = age; }//this指向的是当前类所对应的对象
//这句话的意思就是把传进来的参数age赋值给当前对象的成员变量age
