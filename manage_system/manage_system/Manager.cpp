#include "Manager.h"
#include <iostream>
using namespace std;

Manager::Manager(string no, string name, int age)
	: Staff(no, name, age) {}

Manager::~Manager() {}

void Manager::showData() const {
	cout << "���:" << no
		<< " ����:" << name
		<< " ����:" << age
		<< " ְ��:Manager"
		<< endl;
}

string Manager::getTitle() const { return "Manager"; }
