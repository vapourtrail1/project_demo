#ifndef SALESMAN_H
#define SALESMAN_H

#include "Staff.h"
//ѧϰ���̳������д����ӿڣ���ôʵ�� getTitle()��showData()
//ÿ�� .h ͷ�ļ����ǡ���ŵ��������Ҫ����Ӧ�� .cpp ��ȥ�������֡���
class Salesman :virtual public Staff {//��̳У�
protected:
	double sales;  // ���۶�

public:
	Salesman(string no, string name, int age, double sales);
	virtual ~Salesman();

	// ��д���ി�麯��
	void showData() const override;
	string getTitle() const override;

	// ��д���۶�ӿ�
	double getSales() const override;
	void setSales(double sales) override;
};

#endif // SALESMAN_H
