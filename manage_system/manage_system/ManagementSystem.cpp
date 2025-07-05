#include "ManagementSystem.h"
#include "Salesman.h"
#include "Manager.h"
#include "SalesManager.h"
#include <iostream>
#include <fstream>
using namespace std;

ManagementSystem::ManagementSystem() {
	StaffNum = 0;
	fileIn();//从文件中加载员工数据
}

ManagementSystem::~ManagementSystem() {//析构函数仍然需要作用域运算符
	for (int i = 0; i < vec.size(); i++) {
		delete vec[i].staff;//释放掉所有被员工对象占用的内存
	}//new都是在堆内存创建的 所以需要delete手动释放
}
//栈内存与堆内存
/*
stack：特点：系统自动管理 速度快 空间小 生命周期随着作用域结束自动释放
如：int a =10 函数结束时  a自动销毁

heap： 特点：new手动分配 delete手动释放 不会自动释放
如:staff* s = new Salesman("001",....)
   delele s;  
   不这样写会内存泄漏
*/

void ManagementSystem::fileIn() {
	ifstream infile("G:\\code\\project\\staff.txt");//
	//输入文件流 input file stream 从磁盘的文件读取数据
	// infile 变量名  相当于创建了一个 读取文件的变量
	if (!infile) {
		cout << "找不到 staff.txt，稍后会新建\n";
		return;
	}
	string no, name, title;
	int age;
	double sales;
	while (infile >> no >> name >> age >> title) {//依次从文件读取四个字段，用空格分开，分别赋值给 no、name、age、title。
		if (hasSales(title)) {//salesman返回的是true
			infile >> sales;//把销售量读进去
		}
		else {
			sales = 0;
		}
		hire(no, name, age, title, sales);//读取了一个人的所有信息 然后在输入到变量里 一个人的信息输入结束后 再把第二个人的信息输入到变量里继续雇佣
	}
}

bool ManagementSystem::hire(string no, string name, int age, string title, double sales) {
	Staff* p = nullptr;
	//bool ManagementSystem::isSalesman(string t) const { return t == "Salesman"; }
	if (isSalesman(title)) {
		p = new Salesman(no, name, age, sales);
	}
	else if (isManager(title)) {
		p = new Manager(no, name, age);
	}
	else if (isSalesManager(title)) {
		p = new SalesManager(no, name, age, sales);
	}
	else {
		cout << "职位错误: " << title << endl;
		return false;
	}//利用判断函数new出子类对象
	Node node;//表示一个人
	node.staff = p;//把“员工”给对象
	node.isEmployed = true;//表示员工在职
	vec.push_back(node);//在容器vec中推入一个人
	StaffNum++;//加一个人 ，然后员工人数加一
}

void ManagementSystem::showStaff() const {
	for (int i = 0; i < vec.size(); i++) {
		cout << "在职:" << vec[i].isEmployed << " ";//这里的isEmployed是数据成员 bool型的 所以返回的是值 而不是函数  t1 f0
		vec[i].staff->showData();//staff是指针，它是node的一个成员 类型是Staff* ，指向某种员工对象的父类指针
	}//可能实际指向销售员 经理 销售经理
}

/*
 假设
 vec[0].staff = new Salesman("001", "张三", 28, 8000);
 vec[1].staff = new Manager("002",....)

 vec[0].staff->showdata();  // 调用salesman::showdata()
 */

void ManagementSystem::showCount() const {
	int s = 0, sm = 0, m = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		string t=vec[i].staff->getTitle();
		if (t=="Salesman")
		{
			s++;
		}
		if (t == "SalesManager")
		{
			sm++;
		}
		if (t == "Manager")
		{
			m++;
		}
	}
	cout << "总人数:" << StaffNum<<" "
		<< "Salesman:" << s<<" "
		<< "Manager:" << m<<" "
		<< "Salesmanage:" << sm<<" "
		<< endl;
		
}//统计各个职位的人数  并显示总人数 总人数已在hire()里完成 

void ManagementSystem::searchStaff() const {//查找员工通过编号
	cout << "请输入要查找的员工编号：";
	string key;
	cin >> key;
	for (int i = 0; i < vec.size(); i++) {
		if (key == vec[i].staff->getNo()) {
			cout << "在职:" << vec[i].isEmployed << " ";
			vec[i].staff->showData();
			return;//直接退出整个函数searchStaff，返回整个主菜单的界面？
		}
	}
	cout << "没找到这个编号\n";
	
}

void ManagementSystem::addData() {
	cout << "添加员工（格式：编号 姓名 年龄 职位 [销售额]），输入 # 退出\n";
	while (true)
	{
		
		string no;
		cin >> no;
		if (no == "#") {
			break;
		}

		string name;
		int age;
		string title;
		double sales = 0;
		
		if (!(cin >> name >> age >> title)) {//输入的格式要正确
			cout << "输入格式错误（姓名 年龄 职位），请重新输入\n";
			cin.clear();//清除错误状态 
			cin.ignore(10000, '\n');//把这行剩下的错误丢掉
			continue;//直接跳过后面这次循环剩下的所有操作,重新从while来

		}
		if (hasSales(title))
		{
			cin >> sales;//是那两个title  直接把销售金额输入
		}
		if (hasRepeated(no)) {
			cout << "编号重复" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		if (hire(no, name, age, title, sales)) {
			cout << "已添加" << endl;
		}
		else {
			cout << "添加失败" << endl;
		}
		cin.ignore(10000, '\n');
	}
}



void ManagementSystem::updateStaff() {
	cout << "请输入修改员工的编号" << endl;
	string key;//不能冲突
	cin >> key;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].staff->getNo() == key)
		{
			cout << "1.改编号 2.改姓名 3.改年龄  4.改销售额 0.退出\n";//有如下功能
			int c;//调用功能的函数
			cin >> c;
			if (c==1)
			{
				vec[i].staff->setNo(key);
			}
			if (c == 2)
			{
				cout << "输入姓名" << endl;
				string name1;
				cin >> name1;
				vec[i].staff->setName(name1);
			}
			if (c == 3)
			{
				cout << "输入年龄" << endl;
				int age1;
				cin >> age1;
				vec[i].staff->setAge(age1);
			}
			if (c == 4&& vec[i].staff->getTitle() != "Manager")
			{
					double sals;
					cin >> sals;
					vec[i].staff->setSales(sals);
			}
			else {
				cout << "Manager不能修改销售额" << endl;
			}
            cout << "操作成功" << endl;
		    return;
		}
	}
	cout << "没找到\n";
}


void ManagementSystem::markStaffToBeFired() {
	cout << "请输入需要被解雇员工的编号" << endl;
	string key;
	cin >> key;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].staff->getNo() == key) {
			vec[i].isEmployed = false;
			cout << "ismarked" << endl;
			return;
		}
	}
	cout << "not found" << endl;
}

void ManagementSystem::fireStaffs() {
	// 删除 isEmployed == false 的节点
	bool anyFired = false;
	for (int i = 0; i < vec.size();)
	{
		if (vec[i].isEmployed == false) {
			delete vec[i].staff;
			vec.erase(vec.begin() + i);//vec.erase(iterator) 接收的参数就是这种迭代器
			StaffNum--;//tips:vec.begin()表示第一个位置 而且i是从0开始 所以第一个位置的元素是vec.begin() + 0（i=0 第一个位置的元素）   第二个是vec.begin() + 1
			anyFired = true;
		}
		else {
			i++;//如果没找到 i往后移动
		}
	}
	if (anyFired)
	{
		cout << "完成解雇" << endl;
	}
	
}

void ManagementSystem::recombineFile() {
	ofstream out("G:\\code\\project\\staff.txt");
	for (int i = 0; i < vec.size(); i++)
	{
		Staff* p = vec[i].staff;
		out << p->getNo() << " "
			<< p->getName() << " "
			<< p->getAge() << " "
			<< p->getTitle();
		if (hasSales(p->getTitle()))
		{
			out << " " << p->getSales();
		}
		out << '\n';
	}
	cout << "保存成功" << endl;
}

bool ManagementSystem::hasRepeated(string no) const {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i].staff->getNo() == no) {
			return true;
		}
		else {

			return false;
		}
}

bool ManagementSystem::inTitles(string t) const {
	return t == "Salesman" || t == "Manager" || t == "SalesManager";
}

//上下一样
bool ManagementSystem::hasSales(string t) const {//bool只会返回t or f
	
	if (t == "Salesman" || t == "SalesManager")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ManagementSystem::isSalesman(string t) const { return t == "Salesman"; }
bool ManagementSystem::isManager(string t) const { return t == "Manager"; }
bool ManagementSystem::isSalesManager(string t) const { return t == "SalesManager"; }

void ManagementSystem::SelectFunction() {//选择功能 
	while (true) {
		cout << "\n1:查所有 2:查单个 3:人数 4:标记解雇 5:执行解雇\n"
			<< "6:添加 7:修改 0:保存退出\n请选择：";
		int c; cin >> c;
		if (c == 1) showStaff();
		else if (c == 2) searchStaff();
		else if (c == 3) showCount();
		else if (c == 4) markStaffToBeFired();
		else if (c == 5) fireStaffs();
		else if (c == 6) addData();
		else if (c == 7) updateStaff();
		else if (c == 0) { recombineFile(); break; }
		else cout << "输入错误\n";
	}
}
