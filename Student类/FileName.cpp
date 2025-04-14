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
	string specialty;//专业 
	long id;// 学号 
	double creditPoint; //学分积点 
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
//剪切线
class StudentManage
{
public:
	enum SortType//枚举类型,这既不是函数也不是数据成员,这是定义了一个枚举类型,相当于定义了一个类或者一个结构体,其中包含四个成员分别是name id specialty和crditpoint
	{
		BY_NAME, BY_ID, BY_SPECIALTY, BY_CRDITPOINT//分别代表初始值0123
	};
	StudentManage() = default;//不给用构造函数
	void addStudent();
	void removeStudent();
	void setSortType(SortType st);//要求输入一个SortType类型的数据st,由于根据辅导书里面讲的这个函数的主要作用是排序,所以没什么主要insert作用
	void findStudent();
	int size()const
	{
		return students.size();
	}
	friend std::ostream& operator<<(std::ostream& out, const StudentManage& sm);
private:
	vector<Student> students;//students类作为StudentManage的数据成员?这应该只是类嵌套,不算数据成员——这个解释是错的,详见最后一行注释
	SortType sortType = BY_ID;//定义了一个SortType类的sortType变量,这个变量等于BY_ID
};
void StudentManage::addStudent()//看了一下main函数的程序,这个addstudent只能相当于有开辟空间的功能
{
	string n;
	string s;
	long i;
	double c;
	cin >> n >> s >> i >> c;
	Student a(n, s, i, c);
	students.push_back(a);//来看看这个函数是怎么做的,要求输入一个student的全套数据,然后对student类的a进行列表初始化,再使用pushback在students组后面添加一个a,这里pushback充当了开辟空间的功能
	setSortType(sortType);//根据这个函数的声明,要求输入该类的一个枚举变量sortType,默认是sortType=id所以一般会根据id进行排序,在main函数中可以进行更改
}
void StudentManage::removeStudent()
{
	int b = 0;
	long a;
	cin >> a;//这里不管那么多.默认输入的是学号
	for (auto it = students.begin(); it != students.end(); ++it)//这是使用容器遍历迭代器的格式,要背下来
	{
		if (students[b].getId() == a)
		{
			int c = b;//ccb
			break;//没有break也行不过最好有
		}
		b = b + 1;
	}//有一大部分和下面的查找一样,是因为查找到了才能移除
	students.erase(students.begin() + b);//执行删除操作
}
void StudentManage::findStudent()
{
	int b = 0;
	long a;
	cin >> a;//这里不管那么多.默认输入的是学号
	for (auto it = students.begin(); it != students.end(); ++it)//这是使用容器遍历迭代器的格式,要背下来
	{
		if (students[b].getId() == a)
		{
			cout << students[b].getName() << ' ' << students[b].getSpecialty() << ' ' << students[b].getId() << ' ' << students[b].getCreditPoint() << endl;
			break;
		}
		b = b + 1;
	}
}//这段函数的意思是,要求输入一个学号,然后对studentmanage下的vector下的student进行查找
std::ostream& operator<<(std::ostream& out, const StudentManage& sm)
{
	int b = 0;
	for (auto it = sm.students.begin(); it != sm.students.end(); ++it)//这是使用容器遍历迭代器的格式,要背下来
	{
		out << sm.students[b].getName() << ' ' << sm.students[b].getSpecialty() << ' ' << sm.students[b].getId() << ' ' << sm.students[b].getCreditPoint() << endl;
		b = b + 1;
	}
	return out;
}//对全体studentmanage进行输出
//剪切线
void StudentManage::setSortType(SortType st)//这里通过输入一个SortType类型的st数据来激活这个setSortType函数,但是这个函数的主要作用是排序
{
	function <bool(const Student&, const Student&)> f;//这是一个function容器,必须包含functional头文件,这里创造了一个基于function模板的f类
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
	StudentManage sm;//sm中有成员以student类为类型的容器students,使用students存储student类数据
	sm.addStudent();//基于上一句注释,希望在每一次addstudent时pushback一个元素,具体参见addstudent的编写
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
//程序整体结构参照类视图,具体来说是student类内包含creditpoint、id、name、specialty;studentmanage内包含student类容器
//根据上一行注释,某种程度上类可以算是数据成员
//这种类包含类的结构不是类继承类,而是在大类中可以访问小类,小类的函数也可以访问自己
//对于类中定义一个枚举,如何理解?这和在类中和类外没多大关系,照用不误,只是在类中声明枚举,说明这个枚举只能用来定义该类的数据成员,这句话可以类比上面的在类中定义一个vector
//成功了我操
//本来第一眼看这个程序毫无头绪,不过既然写出来的addstudent、removestudent、findstudent函数,说明已经理解了,多余的解释注释不再赘述