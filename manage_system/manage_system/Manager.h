#ifndef MANAGER_H
#define MANAGER_H
#include "Staff.h"

class Manager : virtual public Staff {
public:
	Manager(string no, string name, int age);
	virtual ~Manager();

	void showData() const override;
	string getTitle() const override;
};

#endif // MANAGER_H
