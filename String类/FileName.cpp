#include <iostream> 
#include <cstring> 
using namespace std;
class MyString {
public:
	MyString(const char* s)//唯一初始化方法
	{  //分配独立的内存空间 
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	MyString()
	{
		str = nullptr;
	}
	MyString(const MyString& s);  //分配独立的内存空间
	MyString(MyString&& s);  //直接获取现有的内存空间,这里规定做到二维
	~MyString(void);
	MyString& operator=(const MyString& s);  //分配独立的内存空间 
	MyString& operator=(MyString&& s);  //直接获取现有的内存空间 
	int size(void)const;
	MyString operator+(const MyString& s)const;
	char& operator[](int index);
	const char& operator[](int index)const;
	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
private:
	char* str;
};
MyString::MyString(const MyString& s)//传入一个s,有str成员,右值引用
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}
	str = new char[size + 1];//这里注意size+1个数值,但是下面那句末尾赋0必须是移位size,这里特别注意数组变换
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//就这样完成了复制构造函数,这里是深拷贝,即给定新内存,这this的str应该是size+1
}
MyString::MyString(MyString&& s)//二维数组的深拷贝?感觉还是一样的,输入一个二维数组,返回一个mystring对象(是不是右值引用?我管你这那的)
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}
	str = new char[size + 1];//这里注意size+1个数值,但是下面那句末尾赋0必须是移位size,这里特别注意数组变换
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//就这样完成了复制构造函数,这里是深拷贝,即给定新内存,这this的str应该是size+1
}
MyString::~MyString(void)
{
}
MyString& MyString::operator=(const MyString& s)//注意对象是this,这里this直接指向左值,所以等于直接对左值进行操作,这里直接returnthis即可
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}//统计
	str = new char[size + 1];//这里注意size+1个数值,但是下面那句末尾赋0必须是移位size,这里特别注意数组变换
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//就这样完成了复制构造函数,这里是深拷贝,即给定新内存,这this的str应该是size+1
	return *this;
}
MyString& MyString::operator=(MyString&& s)//右值引用
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}//统计
	str = new char[size + 1];//这里注意size+1个数值,但是下面那句末尾赋0必须是移位size,这里特别注意数组变换
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//就这样完成了复制构造函数,这里是深拷贝,即给定新内存,这this的str应该是size+1
	return *this;
}
int MyString::size(void)const
{
	int size = 0;
	int c = 0;
	while ((str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}
	return c + 1;
}
MyString MyString::operator+(const MyString& s)const//类比上面的等于号重载,this指针指向左值,或许可以把=看作单目运算符?这里不能简单返回this
{
	int size1 = 0;
	while (s[size1] != 0)
	{
		size1 = size1 + 1;
	}//测量本身数组的长度,这里没检测0
	int size2 = 0;
	while (s[size2] != 0)
	{
		size2 = size2 + 1;
	}//测量输入数组的长度,这里没检测0
	MyString a;
	a.str = new char[size1 + size2 + 1];
	a.str[size1 + size2] = 0;
	int size3 = 0;
	while (this->str[size3] != 0)
	{
		a[size3] = this->str[size3];//注意this.str是一个语法错误,因为this不是一个对象,而是一个对象指针,获取它的成员必须使用->运算符
		size3 = size3 + 1;
	}
	int size4 = 0;
	while (s[size4] != 0)
	{
		a[size3 + size4] = s[size4];
		size4 = size4 + 1;
	}
	return a;
}
char& MyString::operator[](int index)
{
	return str[index];
}
const char& MyString::operator[](int index)const
{
	return str[index];
}
std::ostream& operator<<(std::ostream& out, const MyString& s)//注意这是友元函数定义输出流,所以不会有this指针
{
	int a = 0;
	while (1)
	{
		out << s.str[a];
		a = a + 1;
		if (s.str[a] == 0)
		{
			break;
		}
	}
	return out;
}
int main() {
	MyString s("Hello");
	cout << s << endl;
	MyString s2 = s + "World";
	cout << s2 << endl;
	cout << "Index 5:" << s2[5] << endl;
	MyString s3(move(s2));
	cout << s3 << endl;
	return 0;
}