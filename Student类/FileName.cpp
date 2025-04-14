#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
class Student
{
private:
	string name;
	string specialty;//רҵ 
	long id;// ѧ�� 
	double creditPoint; //ѧ�ֻ��� 
public:
	Student(string n, string s, long i, double c):name(n), specialty(s), id(i), creditPoint(c)
	{
	}
	void setCreditPoint(double c)
	{
		creditPoint = c;
	}
	double getCreditPoint()const
	{
		return creditPoint;
	}
	string getName()const
	{
		return name;
	}
	long getId()const
	{
		return id;
	}
	string getSpecialty()const 
	{
		return specialty;
	}
	friend std::ostream& operator<<(std::ostream& out, const Student& s);
};
ostream& operator<<(ostream& out, const Student& s)
{
	out << "Name:" << s.name << endl;
	out << "  Id:" << s.id << endl;
	out << "  Specialty:" << s.specialty << endl;
	out << "  CreditPoint:" << s.creditPoint << endl;
	return out;
}
//������
class StudentManage
{
public:
	enum SortType//ö������,��Ȳ��Ǻ���Ҳ�������ݳ�Ա,���Ƕ�����һ��ö������,�൱�ڶ�����һ�������һ���ṹ��,���а����ĸ���Ա�ֱ���name id specialty��crditpoint
	{
		BY_NAME, BY_ID, BY_SPECIALTY, BY_CRDITPOINT//�ֱ�����ʼֵ0123
	};
	StudentManage() = default;//�����ù��캯��
	void addStudent();
	void removeStudent();
	void setSortType(SortType st);//Ҫ������һ��SortType���͵�����st,���ڸ��ݸ��������潲�������������Ҫ����������,����ûʲô��Ҫinsert����
	void findStudent();
	int size()const
	{
		return students.size();
	}
	friend std::ostream& operator<<(std::ostream& out, const StudentManage& sm);
private:
	vector<Student> students;//students����ΪStudentManage�����ݳ�Ա?��Ӧ��ֻ����Ƕ��,�������ݳ�Ա������������Ǵ��,������һ��ע��
	SortType sortType = BY_ID;//������һ��SortType���sortType����,�����������BY_ID
};
void StudentManage::addStudent()//����һ��main�����ĳ���,���addstudentֻ���൱���п��ٿռ�Ĺ���
{
	string n;
	string s;
	long i;
	double c;
	cin >> n >> s >> i >> c;
	Student a(n, s, i, c);
	students.push_back(a);//�����������������ô����,Ҫ������һ��student��ȫ������,Ȼ���student���a�����б��ʼ��,��ʹ��pushback��students��������һ��a,����pushback�䵱�˿��ٿռ�Ĺ���
	setSortType(sortType);//�����������������,Ҫ����������һ��ö�ٱ���sortType,Ĭ����sortType=id����һ������id��������,��main�����п��Խ��и���
}
void StudentManage::removeStudent()
{
	int b = 0;
	long a;
	cin >> a;//���ﲻ����ô��.Ĭ���������ѧ��
	for (auto it = students.begin(); it != students.end(); ++it)//����ʹ�����������������ĸ�ʽ,Ҫ������
	{
		if (students[b].getId() == a)
		{
			int c = b;//ccb
			break;//û��breakҲ�в��������
		}
		b = b + 1;
	}//��һ�󲿷ֺ�����Ĳ���һ��,����Ϊ���ҵ��˲����Ƴ�
	students.erase(students.begin() + b);//ִ��ɾ������
}
void StudentManage::findStudent()
{
	int b = 0;
	long a;
	cin >> a;//���ﲻ����ô��.Ĭ���������ѧ��
	for (auto it = students.begin(); it != students.end(); ++it)//����ʹ�����������������ĸ�ʽ,Ҫ������
	{
		if (students[b].getId() == a)
		{
			cout << students[b].getName() << ' ' << students[b].getSpecialty() << ' ' << students[b].getId() << ' ' << students[b].getCreditPoint() << endl;
			break;
		}
		b = b + 1;
	}
}//��κ�������˼��,Ҫ������һ��ѧ��,Ȼ���studentmanage�µ�vector�µ�student���в���
std::ostream& operator<<(std::ostream& out, const StudentManage& sm)
{
	int b = 0;
	for (auto it = sm.students.begin(); it != sm.students.end(); ++it)//����ʹ�����������������ĸ�ʽ,Ҫ������
	{
		out << sm.students[b].getName() << ' ' << sm.students[b].getSpecialty() << ' ' << sm.students[b].getId() << ' ' << sm.students[b].getCreditPoint() << endl;
		b = b + 1;
	}
	return out;
}//��ȫ��studentmanage�������
//������
void StudentManage::setSortType(SortType st)//����ͨ������һ��SortType���͵�st�������������setSortType����,���������������Ҫ����������
{
	function <bool(const Student&, const Student&)> f;//����һ��function����,�������functionalͷ�ļ�,���ﴴ����һ������functionģ���f��
	switch (st)
	{
		case BY_ID: f = [](const Student& s1, const Student& s2)
		{
			return s1.getName() < s2.getName();
		};
		break;
		case BY_NAME:f = [](const Student& s1, const Student& s2)
		{
			return s1.getId() < s2.getId();
		};
		break;
		case BY_SPECIALTY:f = [](const Student& s1, const Student& s2)
		{
			return s1.getSpecialty() < s2.getSpecialty();
		};
		break;
		case BY_CRDITPOINT:f = [](const Student& s1, const Student& s2)
		{
			return s1.getCreditPoint() < s2.getCreditPoint();
		};
		break;
	}
	sort(students.begin(), students.end(), f);
}
int main()
{
	StudentManage sm;//sm���г�Ա��student��Ϊ���͵�����students,ʹ��students�洢student������
	sm.addStudent();//������һ��ע��,ϣ����ÿһ��addstudentʱpushbackһ��Ԫ��,����μ�addstudent�ı�д
	sm.addStudent();
	sm.addStudent();
	sm.addStudent();
	cout << "sort type(0-name,1-id,2-specialty,3-creditpoint):";
	int choice;
	cin >> choice;
	sm.setSortType(static_cast<StudentManage::SortType>(choice));
	cout << sm;
	sm.findStudent();
	sm.removeStudent();
	cout << sm;
	return 0;
}
//��������ṹ��������ͼ,������˵��student���ڰ���creditpoint��id��name��specialty;studentmanage�ڰ���student������
//������һ��ע��,ĳ�̶ֳ���������������ݳ�Ա
//�����������Ľṹ������̳���,�����ڴ����п��Է���С��,С��ĺ���Ҳ���Է����Լ�
//�������ж���һ��ö��,������?��������к�����û����ϵ,���ò���,ֻ������������ö��,˵�����ö��ֻ�����������������ݳ�Ա,��仰�����������������ж���һ��vector
//�ɹ����Ҳ�
//������һ�ۿ�����������ͷ��,������Ȼд������addstudent��removestudent��findstudent����,˵���Ѿ������,����Ľ���ע�Ͳ���׸��