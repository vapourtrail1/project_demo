#ifndef MANAGEMENTSYSTEM_H
#define MANAGEMENTSYSTEM_H

#include <vector>//员工列表用 vector 存
#include <string>
#include "Staff.h"//方便用staff指针
using namespace std;

struct Node {//表示为一个人
	Staff* staff;      // 指向具体 Staff 派生对象
	bool isEmployed;   // true = 在职，false = 待解雇
	//它的类型是 Staff* → 说明它只能存 Staff 或继承它的子类的地址
};

//Staff* p = new Salesman("001", "张三", 25, 8000);
//p->showData();  // 调用的是 Salesman 的 showData()
//这个 p 实际上指向了一个 Salesman，
//但它是以 Staff* 的身份存在的！
//
// 这是 “父类指针指向子类对象”，是 C++ 多态的核心操作。

class ManagementSystem {
public:
	ManagementSystem();
	~ManagementSystem();

	void SelectFunction();  // 进入主菜单

private:
	vector<Node> vec;  // 存所有员工
	int StaffNum;      // 员工总数

	void fileIn();
	/*  作用：从文件中读取员工数据，初始化系统
		这个函数会打开一个.txt 文件（通常叫 staff.txt）
		每一行是一位员工：编号、姓名、年龄、职位、销售额
		它把数据读进来，生成对象，加入到 vector<Node> 中*/
	void showStaff() const;
	void showCount() const;
	void searchStaff() const;
	void addData();
	void markStaffToBeFired();
	void updateStaff();
	void fireStaffs();
	void recombineFile();

	// 辅助
	bool hire(string no, string name, int age, string title, double sales = 0);
	bool hasRepeated(string no) const;
	bool inTitles(string title) const;
	bool hasSales(string title) const;
	bool isSalesman(string title) const;
	bool isManager(string title) const;
	bool isSalesManager(string title) const;
};

#endif // MANAGEMENTSYSTEM_H
