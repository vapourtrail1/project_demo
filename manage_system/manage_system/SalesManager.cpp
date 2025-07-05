#include "SalesManager.h"
#include <iostream>
using namespace std;

SalesManager::SalesManager(string no, string name, int age, double sales)
	: Staff(no, name, age)
	, Salesman(no, name, age, sales)//�Ѹ���Ĺ��캯�����ó�ʼ����
	, Manager(no, name, age)
{}

SalesManager::~SalesManager() {}

void SalesManager::showData() const {
	cout << "���:" << no
		<< " ����:" << name
		<< " ����:" << age
		<< " ְ��:SalesManager"
		<< " ���۶�:" << sales
		<< endl;
}

string SalesManager::getTitle() const { return "SalesManager"; }
