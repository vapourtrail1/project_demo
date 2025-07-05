#include "ManagementSystem.h"
#include "Salesman.h"
#include "Manager.h"
#include "SalesManager.h"
#include <iostream>
#include <fstream>
using namespace std;

ManagementSystem::ManagementSystem() {
	StaffNum = 0;
	fileIn();//���ļ��м���Ա������
}

ManagementSystem::~ManagementSystem() {//����������Ȼ��Ҫ�����������
	for (int i = 0; i < vec.size(); i++) {
		delete vec[i].staff;//�ͷŵ����б�Ա������ռ�õ��ڴ�
	}//new�����ڶ��ڴ洴���� ������Ҫdelete�ֶ��ͷ�
}
//ջ�ڴ�����ڴ�
/*
stack���ص㣺ϵͳ�Զ����� �ٶȿ� �ռ�С ����������������������Զ��ͷ�
�磺int a =10 ��������ʱ  a�Զ�����

heap�� �ص㣺new�ֶ����� delete�ֶ��ͷ� �����Զ��ͷ�
��:staff* s = new Salesman("001",....)
   delele s;  
   ������д���ڴ�й©
*/

void ManagementSystem::fileIn() {
	ifstream infile("G:\\code\\project\\staff.txt");//
	//�����ļ��� input file stream �Ӵ��̵��ļ���ȡ����
	// infile ������  �൱�ڴ�����һ�� ��ȡ�ļ��ı���
	if (!infile) {
		cout << "�Ҳ��� staff.txt���Ժ���½�\n";
		return;
	}
	string no, name, title;
	int age;
	double sales;
	while (infile >> no >> name >> age >> title) {//���δ��ļ���ȡ�ĸ��ֶΣ��ÿո�ֿ����ֱ�ֵ�� no��name��age��title��
		if (hasSales(title)) {//salesman���ص���true
			infile >> sales;//������������ȥ
		}
		else {
			sales = 0;
		}
		hire(no, name, age, title, sales);//��ȡ��һ���˵�������Ϣ Ȼ�������뵽������ һ���˵���Ϣ��������� �ٰѵڶ����˵���Ϣ���뵽�����������Ӷ
	}
}

bool ManagementSystem::hire(string no, string name, int age, string title, double sales) {
	Staff* p = nullptr;
	//bool ManagementSystem::isSalesman(string t) const { return t == "Salesman"; }
	if (isSalesman(title)) {
		p = new Salesman(no, name, age, sales);
	}
	else if (isManager(title)) {
		p = new Manager(no, name, age);
	}
	else if (isSalesManager(title)) {
		p = new SalesManager(no, name, age, sales);
	}
	else {
		cout << "ְλ����: " << title << endl;
		return false;
	}//�����жϺ���new���������
	Node node;//��ʾһ����
	node.staff = p;//�ѡ�Ա����������
	node.isEmployed = true;//��ʾԱ����ְ
	vec.push_back(node);//������vec������һ����
	StaffNum++;//��һ���� ��Ȼ��Ա��������һ
}

void ManagementSystem::showStaff() const {
	for (int i = 0; i < vec.size(); i++) {
		cout << "��ְ:" << vec[i].isEmployed << " ";//�����isEmployed�����ݳ�Ա bool�͵� ���Է��ص���ֵ �����Ǻ���  t1 f0
		vec[i].staff->showData();//staff��ָ�룬����node��һ����Ա ������Staff* ��ָ��ĳ��Ա������ĸ���ָ��
	}//����ʵ��ָ������Ա ���� ���۾���
}

/*
 ����
 vec[0].staff = new Salesman("001", "����", 28, 8000);
 vec[1].staff = new Manager("002",....)

 vec[0].staff->showdata();  // ����salesman::showdata()
 */

void ManagementSystem::showCount() const {
	int s = 0, sm = 0, m = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		string t=vec[i].staff->getTitle();
		if (t=="Salesman")
		{
			s++;
		}
		if (t == "SalesManager")
		{
			sm++;
		}
		if (t == "Manager")
		{
			m++;
		}
	}
	cout << "������:" << StaffNum<<" "
		<< "Salesman:" << s<<" "
		<< "Manager:" << m<<" "
		<< "Salesmanage:" << sm<<" "
		<< endl;
		
}//ͳ�Ƹ���ְλ������  ����ʾ������ ����������hire()����� 

void ManagementSystem::searchStaff() const {//����Ա��ͨ�����
	cout << "������Ҫ���ҵ�Ա����ţ�";
	string key;
	cin >> key;
	for (int i = 0; i < vec.size(); i++) {
		if (key == vec[i].staff->getNo()) {
			cout << "��ְ:" << vec[i].isEmployed << " ";
			vec[i].staff->showData();
			return;//ֱ���˳���������searchStaff�������������˵��Ľ��棿
		}
	}
	cout << "û�ҵ�������\n";
	
}

void ManagementSystem::addData() {
	cout << "���Ա������ʽ����� ���� ���� ְλ [���۶�]�������� # �˳�\n";
	while (true)
	{
		
		string no;
		cin >> no;
		if (no == "#") {
			break;
		}

		string name;
		int age;
		string title;
		double sales = 0;
		
		if (!(cin >> name >> age >> title)) {//����ĸ�ʽҪ��ȷ
			cout << "�����ʽ�������� ���� ְλ��������������\n";
			cin.clear();//�������״̬ 
			cin.ignore(10000, '\n');//������ʣ�µĴ��󶪵�
			continue;//ֱ�������������ѭ��ʣ�µ����в���,���´�while��

		}
		if (hasSales(title))
		{
			cin >> sales;//��������title  ֱ�Ӱ����۽������
		}
		if (hasRepeated(no)) {
			cout << "����ظ�" << endl;
			cin.ignore(10000, '\n');
			continue;
		}
		if (hire(no, name, age, title, sales)) {
			cout << "�����" << endl;
		}
		else {
			cout << "���ʧ��" << endl;
		}
		cin.ignore(10000, '\n');
	}
}



void ManagementSystem::updateStaff() {
	cout << "�������޸�Ա���ı��" << endl;
	string key;//���ܳ�ͻ
	cin >> key;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].staff->getNo() == key)
		{
			cout << "1.�ı�� 2.������ 3.������  4.�����۶� 0.�˳�\n";//�����¹���
			int c;//���ù��ܵĺ���
			cin >> c;
			if (c==1)
			{
				vec[i].staff->setNo(key);
			}
			if (c == 2)
			{
				cout << "��������" << endl;
				string name1;
				cin >> name1;
				vec[i].staff->setName(name1);
			}
			if (c == 3)
			{
				cout << "��������" << endl;
				int age1;
				cin >> age1;
				vec[i].staff->setAge(age1);
			}
			if (c == 4&& vec[i].staff->getTitle() != "Manager")
			{
					double sals;
					cin >> sals;
					vec[i].staff->setSales(sals);
			}
			else {
				cout << "Manager�����޸����۶�" << endl;
			}
            cout << "�����ɹ�" << endl;
		    return;
		}
	}
	cout << "û�ҵ�\n";
}


void ManagementSystem::markStaffToBeFired() {
	cout << "��������Ҫ�����Ա���ı��" << endl;
	string key;
	cin >> key;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].staff->getNo() == key) {
			vec[i].isEmployed = false;
			cout << "ismarked" << endl;
			return;
		}
	}
	cout << "not found" << endl;
}

void ManagementSystem::fireStaffs() {
	// ɾ�� isEmployed == false �Ľڵ�
	bool anyFired = false;
	for (int i = 0; i < vec.size();)
	{
		if (vec[i].isEmployed == false) {
			delete vec[i].staff;
			vec.erase(vec.begin() + i);//vec.erase(iterator) ���յĲ����������ֵ�����
			StaffNum--;//tips:vec.begin()��ʾ��һ��λ�� ����i�Ǵ�0��ʼ ���Ե�һ��λ�õ�Ԫ����vec.begin() + 0��i=0 ��һ��λ�õ�Ԫ�أ�   �ڶ�����vec.begin() + 1
			anyFired = true;
		}
		else {
			i++;//���û�ҵ� i�����ƶ�
		}
	}
	if (anyFired)
	{
		cout << "��ɽ��" << endl;
	}
	
}

void ManagementSystem::recombineFile() {
	ofstream out("G:\\code\\project\\staff.txt");
	for (int i = 0; i < vec.size(); i++)
	{
		Staff* p = vec[i].staff;
		out << p->getNo() << " "
			<< p->getName() << " "
			<< p->getAge() << " "
			<< p->getTitle();
		if (hasSales(p->getTitle()))
		{
			out << " " << p->getSales();
		}
		out << '\n';
	}
	cout << "����ɹ�" << endl;
}

bool ManagementSystem::hasRepeated(string no) const {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i].staff->getNo() == no) {
			return true;
		}
		else {

			return false;
		}
}

bool ManagementSystem::inTitles(string t) const {
	return t == "Salesman" || t == "Manager" || t == "SalesManager";
}

//����һ��
bool ManagementSystem::hasSales(string t) const {//boolֻ�᷵��t or f
	
	if (t == "Salesman" || t == "SalesManager")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ManagementSystem::isSalesman(string t) const { return t == "Salesman"; }
bool ManagementSystem::isManager(string t) const { return t == "Manager"; }
bool ManagementSystem::isSalesManager(string t) const { return t == "SalesManager"; }

void ManagementSystem::SelectFunction() {//ѡ���� 
	while (true) {
		cout << "\n1:������ 2:�鵥�� 3:���� 4:��ǽ�� 5:ִ�н��\n"
			<< "6:��� 7:�޸� 0:�����˳�\n��ѡ��";
		int c; cin >> c;
		if (c == 1) showStaff();
		else if (c == 2) searchStaff();
		else if (c == 3) showCount();
		else if (c == 4) markStaffToBeFired();
		else if (c == 5) fireStaffs();
		else if (c == 6) addData();
		else if (c == 7) updateStaff();
		else if (c == 0) { recombineFile(); break; }
		else cout << "�������\n";
	}
}
