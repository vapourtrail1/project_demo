#ifndef MANAGEMENTSYSTEM_H
#define MANAGEMENTSYSTEM_H

#include <vector>//Ա���б��� vector ��
#include <string>
#include "Staff.h"//������staffָ��
using namespace std;

struct Node {//��ʾΪһ����
	Staff* staff;      // ָ����� Staff ��������
	bool isEmployed;   // true = ��ְ��false = �����
	//���������� Staff* �� ˵����ֻ�ܴ� Staff ��̳���������ĵ�ַ
};

//Staff* p = new Salesman("001", "����", 25, 8000);
//p->showData();  // ���õ��� Salesman �� showData()
//��� p ʵ����ָ����һ�� Salesman��
//�������� Staff* ����ݴ��ڵģ�
//
// ���� ������ָ��ָ��������󡱣��� C++ ��̬�ĺ��Ĳ�����

class ManagementSystem {
public:
	ManagementSystem();
	~ManagementSystem();

	void SelectFunction();  // �������˵�

private:
	vector<Node> vec;  // ������Ա��
	int StaffNum;      // Ա������

	void fileIn();
	/*  ���ã����ļ��ж�ȡԱ�����ݣ���ʼ��ϵͳ
		����������һ��.txt �ļ���ͨ���� staff.txt��
		ÿһ����һλԱ������š����������䡢ְλ�����۶�
		�������ݶ����������ɶ��󣬼��뵽 vector<Node> ��*/
	void showStaff() const;
	void showCount() const;
	void searchStaff() const;
	void addData();
	void markStaffToBeFired();
	void updateStaff();
	void fireStaffs();
	void recombineFile();

	// ����
	bool hire(string no, string name, int age, string title, double sales = 0);
	bool hasRepeated(string no) const;
	bool inTitles(string title) const;
	bool hasSales(string title) const;
	bool isSalesman(string title) const;
	bool isManager(string title) const;
	bool isSalesManager(string title) const;
};

#endif // MANAGEMENTSYSTEM_H
