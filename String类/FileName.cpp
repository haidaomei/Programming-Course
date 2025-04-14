#include <iostream> 
#include <cstring> 
using namespace std;
class MyString {
public:
	MyString(const char* s)//Ψһ��ʼ������
	{  //����������ڴ�ռ� 
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	MyString()
	{
		str = nullptr;
	}
	MyString(const MyString& s);  //����������ڴ�ռ�
	MyString(MyString&& s);  //ֱ�ӻ�ȡ���е��ڴ�ռ�,����涨������ά
	~MyString(void);
	MyString& operator=(const MyString& s);  //����������ڴ�ռ� 
	MyString& operator=(MyString&& s);  //ֱ�ӻ�ȡ���е��ڴ�ռ� 
	int size(void)const;
	MyString operator+(const MyString& s)const;
	char& operator[](int index);
	const char& operator[](int index)const;
	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
private:
	char* str;
};
MyString::MyString(const MyString& s)//����һ��s,��str��Ա,��ֵ����
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}
	str = new char[size + 1];//����ע��size+1����ֵ,���������Ǿ�ĩβ��0��������λsize,�����ر�ע������任
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//����������˸��ƹ��캯��,���������,���������ڴ�,��this��strӦ����size+1
}
MyString::MyString(MyString&& s)//��ά��������?�о�����һ����,����һ����ά����,����һ��mystring����(�ǲ�����ֵ����?�ҹ������ǵ�)
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}
	str = new char[size + 1];//����ע��size+1����ֵ,���������Ǿ�ĩβ��0��������λsize,�����ر�ע������任
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//����������˸��ƹ��캯��,���������,���������ڴ�,��this��strӦ����size+1
}
MyString::~MyString(void)
{
}
MyString& MyString::operator=(const MyString& s)//ע�������this,����thisֱ��ָ����ֵ,���Ե���ֱ�Ӷ���ֵ���в���,����ֱ��returnthis����
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}//ͳ��
	str = new char[size + 1];//����ע��size+1����ֵ,���������Ǿ�ĩβ��0��������λsize,�����ر�ע������任
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//����������˸��ƹ��캯��,���������,���������ڴ�,��this��strӦ����size+1
	return *this;
}
MyString& MyString::operator=(MyString&& s)//��ֵ����
{
	int size = 0;
	int b = 0, c = 0;
	while ((s.str)[c] != 0)
	{
		size = size + 1;
		c = c + 1;
	}//ͳ��
	str = new char[size + 1];//����ע��size+1����ֵ,���������Ǿ�ĩβ��0��������λsize,�����ر�ע������任
	this->str[size] = 0;
	while ((s.str)[b] != 0)
	{
		(this->str)[b] = (s.str)[b];
		b = b + 1;
	}//����������˸��ƹ��캯��,���������,���������ڴ�,��this��strӦ����size+1
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
MyString MyString::operator+(const MyString& s)const//�������ĵ��ں�����,thisָ��ָ����ֵ,������԰�=������Ŀ�����?���ﲻ�ܼ򵥷���this
{
	int size1 = 0;
	while (s[size1] != 0)
	{
		size1 = size1 + 1;
	}//������������ĳ���,����û���0
	int size2 = 0;
	while (s[size2] != 0)
	{
		size2 = size2 + 1;
	}//������������ĳ���,����û���0
	MyString a;
	a.str = new char[size1 + size2 + 1];
	a.str[size1 + size2] = 0;
	int size3 = 0;
	while (this->str[size3] != 0)
	{
		a[size3] = this->str[size3];//ע��this.str��һ���﷨����,��Ϊthis����һ������,����һ������ָ��,��ȡ���ĳ�Ա����ʹ��->�����
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
std::ostream& operator<<(std::ostream& out, const MyString& s)//ע��������Ԫ�������������,���Բ�����thisָ��
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