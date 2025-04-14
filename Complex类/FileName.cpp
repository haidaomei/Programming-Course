#include <iostream>
#include <math.h>
using namespace std;
class Complex {
public:
	Complex();
	Complex(double r);
	Complex(double r, double i);
	Complex(const Complex& c);//�����ø�����,���Ǹ��ƹ��캯��,����ѡ���ʼ���б���Ա�����
	~Complex();//����
	void setValue(double r, double i);
	double getReal() const;
	double getImage() const;
	double getDistance() const;
	void output() const;
	Complex operator+(const Complex& f)const;
	Complex operator*(const Complex& f)const;
	Complex& operator+=(const Complex& f);
	Complex& operator*=(const Complex& f);
	Complex& operator ++(); //ǰ��++��ʵ���� 1 
	Complex operator++(int); //����++��ʵ���� 1
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
Complex Complex::operator+(const Complex& f)const//����������Զ����ֵ,�������ѡ�񷵻�*this,����Ϊ�˱�֤��˷����غ����ĶԳ���,ѡ������д
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
}//ǰ��++��ʵ���� 1 
Complex Complex::operator++(int temp)
{
	++((*this).real);
	return *this;
}//����++��ʵ���� 1
std::ostream& operator<<(std::ostream& out, const Complex& f)//��������?����������ostream�����cout����
{
	out << f.real << (f.image >= 0 ? '+' : ' ') << f.image << 'i' << endl;
	return out;//���������ｫout����һ�����������,����out����ostream�ڸ�cout�������(�����������������,��������������ʱָ����Ϊout)
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