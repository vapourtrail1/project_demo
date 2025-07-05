#ifndef SALESMANAGER_H
#define SALESMANAGER_H

#include "Salesman.h"
#include "Manager.h"

// SalesManager 既是 Salesman，又是 Manager
class SalesManager : public Salesman, public Manager {//只是声明 
public://销售经理即是销售又是经理 所以多继承
	SalesManager(string no, string name, int age, double sales);
	virtual ~SalesManager();

	void showData() const override;
	string getTitle() const override;
};

#endif // SALESMANAGER_H
