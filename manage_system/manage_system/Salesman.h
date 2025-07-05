#ifndef SALESMAN_H
#define SALESMAN_H

#include "Staff.h"
//学习单继承如何重写父类接口：怎么实现 getTitle()、showData()
//每个 .h 头文件都是「承诺」，你需要到对应的 .cpp 里去看「兑现」：
class Salesman :virtual public Staff {//虚继承，
protected:
	double sales;  // 销售额

public:
	Salesman(string no, string name, int age, double sales);
	virtual ~Salesman();

	// 重写父类纯虚函数
	void showData() const override;
	string getTitle() const override;

	// 重写销售额接口
	double getSales() const override;
	void setSales(double sales) override;
};

#endif // SALESMAN_H
