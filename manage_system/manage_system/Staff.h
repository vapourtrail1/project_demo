#ifndef STAFF_H
#define STAFF_H
#include <string>

using namespace std;  

class Staff {
protected:
	string no;    // 员工编号
	string name;  // 员工姓名
	int age;      // 员工年龄

public:
	// 构造函数
	Staff(string no, string name, int age);
	// 虚析构，保证子类删除干净
	virtual ~Staff();

	// 纯虚函数：所有派生类都要实现  纯虚函数是不需要定义函数体的特殊虚函数
	virtual void showData() const = 0;//只是接口
	virtual string getTitle() const = 0;

	// 可选的“销售额”接口，默认没用
	virtual double getSales() const { return 0; }
	//// 在基类里定义一个虚函数，返回销售额；默认所有员工都没有销售额，返回 0。
	virtual void setSales(double) {}
	// 在基类里定义一个虚函数，用来设置销售额；默认不做任何操作。

	// 属性的 get/set
	string getNo() const;
	void setNo(string no);
	string getName() const;
	void setName(string name);
	int getAge() const;
	void setAge(int age);
};

#endif // STAFF_H
