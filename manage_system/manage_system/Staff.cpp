#include "Staff.h"

Staff::Staff(string no, string name, int age) {
	this->no = no;
	this->name = name;
	this->age = age;
}

Staff::~Staff() {}

// �򵥷��أ��޸ĳ�Ա
string Staff::getNo() const { return no; }
void Staff::setNo(string no) { this->no = no; }//�����洫�����ı�ţ�д���������Ķ���ı���ֶ���
//����ı�� �����ó��Լ��ı��
//�Ѵ���Ķ�����ֵ����ǰ��������ݳ�Ա/��Ա����no
string Staff::getName() const { return name; }
void Staff::setName(string name) { this->name = name; }

int Staff::getAge() const { return age; }
void Staff::setAge(int age) { this->age = age; }//thisָ����ǵ�ǰ������Ӧ�Ķ���
//��仰����˼���ǰѴ������Ĳ���age��ֵ����ǰ����ĳ�Ա����age
