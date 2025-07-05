#ifndef SALESMANAGER_H
#define SALESMANAGER_H

#include "Salesman.h"
#include "Manager.h"

// SalesManager ���� Salesman������ Manager
class SalesManager : public Salesman, public Manager {//ֻ������ 
public://���۾������������Ǿ��� ���Զ�̳�
	SalesManager(string no, string name, int age, double sales);
	virtual ~SalesManager();

	void showData() const override;
	string getTitle() const override;
};

#endif // SALESMANAGER_H
