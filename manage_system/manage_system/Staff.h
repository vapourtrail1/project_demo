#ifndef STAFF_H
#define STAFF_H
#include <string>

using namespace std;  

class Staff {
protected:
	string no;    // Ա�����
	string name;  // Ա������
	int age;      // Ա������

public:
	// ���캯��
	Staff(string no, string name, int age);
	// ����������֤����ɾ���ɾ�
	virtual ~Staff();

	// ���麯�������������඼Ҫʵ��  ���麯���ǲ���Ҫ���庯����������麯��
	virtual void showData() const = 0;//ֻ�ǽӿ�
	virtual string getTitle() const = 0;

	// ��ѡ�ġ����۶�ӿڣ�Ĭ��û��
	virtual double getSales() const { return 0; }
	//// �ڻ����ﶨ��һ���麯�����������۶Ĭ������Ա����û�����۶���� 0��
	virtual void setSales(double) {}
	// �ڻ����ﶨ��һ���麯���������������۶Ĭ�ϲ����κβ�����

	// ���Ե� get/set
	string getNo() const;
	void setNo(string no);
	string getName() const;
	void setName(string name);
	int getAge() const;
	void setAge(int age);
};

#endif // STAFF_H
