#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman(string no, string name, int age, double sales)
	: Staff(no, name, age), sales(sales) {}
//����Ĺ��캯�����������๹�캯���ĳ�ʼ���б��ﱻ����
//��Salesman(...) ���������մ����������ݵģ�
//: Staff(...), sales(...) ����������Щ����һ��ʼ�ͳ�ʼ������Ӧ�ĳ�Ա�����ġ���
Salesman::~Salesman() {}

void Salesman::showData() const {//��д����
	cout << "���:" << no
		<< " ����:" << name
		<< " ����:" << age
		<< " ְ��:Salesman"
		<< " ���۶�:" << sales
		<< endl;
}

string Salesman::getTitle() const { return "Salesman"; }//չʾְ��

double Salesman::getSales() const { return sales; }//����нˮ
void Salesman::setSales(double s) { sales = s; }
