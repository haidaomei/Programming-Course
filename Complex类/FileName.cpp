#include <iostream>
#include <math.h>
using namespace std;
class Complex {
public:
	Complex();
	Complex(double r);
	Complex(double r, double i);
	Complex(const Complex& c);//常引用复数类,这是复制构造函数,可以选择初始化列表或成员运算符
	~Complex();//析构
	void setValue(double r, double i);
	double getReal() const;
	double getImage() const;
	double getDistance() const;
	void output() const;
	Complex operator+(const Complex& f)const;
	Complex operator*(const Complex& f)const;
	Complex& operator+=(const Complex& f);
	Complex& operator*=(const Complex& f);
	Complex& operator ++(); //前置++，实部加 1 
	Complex operator++(int); //后置++，实部加 1
	friend std::ostream& operator<<(std::ostream& out, const Complex& f);
	Complex& operator-=(const Complex& f);
	friend Complex operator-(const Complex& f1, const Complex& f2);
	//Complex add(const Complex& c)const;
	//Complex multiply(const Complex& c)const;
private:
	double real;
	double image;
};
Complex::Complex()
{
	real = 0;
	image = 0;
}
Complex::Complex(double r)
{
	real = r;
	image = 0;
}
Complex::Complex(double r, double i)
{
	real = r;
	image = i;
}
Complex::Complex(const Complex& c)
{
	real = c.real;
	image = c.image;
}
Complex::~Complex()
{
}
void Complex::setValue(double r, double i)
{
	real = r;
	image = i;
}
double Complex::getReal()const
{
	return real;
}
double Complex::getImage()const
{
	return image;
}
double Complex::getDistance()const
{
	return sqrt(real * real + image * image);
}
void Complex::output()const
{
	cout << real << (image >= 0 ? '+' : ' ') << image << 'i' << endl;
}
Complex Complex::operator+(const Complex& f)const//被操作的永远是右值,这里可以选择返回*this,但是为了保证与乘法重载函数的对称性,选择这样写
{
	Complex a;
	a.real = real + f.real;
	a.image = image + f.image;
	return a;
}
Complex Complex::operator*(const Complex& f)const
{
	double a, b;
	Complex d;
	a = real * f.real - image * f.image;
	b = image * f.real + f.image * real;
	d.setValue(a, b);
	return d;
}
Complex& Complex::operator+=(const Complex& f)
{
	Complex a;
	a.real = real + f.real;
	a.image = image + f.image;
	return a;
}
Complex& Complex::operator*=(const Complex& f)
{
	double a, b;
	Complex d;
	a = real * f.real - image * f.image;
	b = image * f.real + f.image * real;
	d.setValue(a, b);
	return d;
}
Complex& Complex::operator ++()
{
	real = real + 1;
	return *this;
}//前置++，实部加 1 
Complex Complex::operator++(int temp)
{
	++((*this).real);
	return *this;
}//后置++，实部加 1
std::ostream& operator<<(std::ostream& out, const Complex& f)//对象引用?这里引用了ostream里面的cout对象
{
	out << f.real << (f.image >= 0 ? '+' : ' ') << f.image << 'i' << endl;
	return out;//我们在这里将out看作一个输出流对象,返回out对象到ostream内给cout进行输出(输出流对象任意命名,这里在声明函数时指定其为out)
}
Complex& Complex::operator-=(const Complex& f)
{
	Complex a;
	a.real = real - f.real;
	a.image = image - f.image;
	return a;
}
Complex operator-(const Complex& f1, const Complex& f2)
{
	Complex a;
	a.real = f1.real - f2.real;
	a.image = f1.image - f2.image;
	return a;
}

/*Complex Complex::add(const Complex& c)const
{
	int a, b;
	Complex d;
	a = real + c.real;
	b = image + c.image;
	d.setValue(a, b);
	return d;
}
/*Complex Complex::multiply(const Complex& c)const
{
	int a, b;
	Complex d;
	a = real * c.real - image * c.image;
	b = image * c.real + c.image * real;
	d.setValue(a, b);
	return d;
}*/
	
int main(void)
{
	Complex a(114, 514);
	cout << a << endl;
	return 0;
}