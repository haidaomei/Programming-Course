#include<iostream>
#include<math.h>
using namespace std;
class Point
{
public:
	Point(double newX, double newY);//ԭ������д��Point( double newX=0, double newY=0);��������д��vs2022����
	Point(const Point& p);
	~Point();
	void setValue(double newX, double newY);
	double getX() const;
	double getY() const;
	double getDistance(const Point& p2)const;
	friend double getDistance2(const Point& p1, const Point& p2);
private:
	double x, y;
};
Point::Point(double newX, double newY)
{
	x = newX;
	y = newY;
}
Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
}
Point::~Point()
{
}
void Point::setValue(double newX, double newY)
{
	x = newX;
	y = newY;
}
double Point::getX()const
{
	return x;
}
double Point::getY()const
{
	return y;
}
double Point::getDistance(const Point& p2)const
{
	return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
}
double getDistance1(const Point& p1, const Point& p2);//���������������Point������֮��,����������ŵ�includeͷ�ļ�֮��,���ֲ���
double getDistance1(const Point& p1, const Point& p2)
{
	return sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
}
double getDistance2(const Point& p1, const Point& p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
class Triangle
{
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3);//�Ҹо�Դ�����������벻Ӧ��ȡ������������Ա������ͬ������,����ԭָ����Triangle(const Point& p1, const Point& p2, const Point& p3);
	double getArea()const;  //���������ε���� 
	double getPerimeter()const;  //�����������ܳ� 
private:
	Point p1, p2, p3;  //������ 3 ������ 
};
Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) :p1(p1), p2(p2), p3(p3)
{
}//�������ʹ�ó�Ա��ʼ���б�,������p1=p1,p2=p2,p3=p3
double Triangle::getArea()const
{
	double p = getPerimeter();
	return sqrt(p * (p - getDistance2(p1, p2)) * (p - getDistance2(p2, p3)) * (p - getDistance2(p1, p3)));
}
double Triangle::getPerimeter()const
{
	return getDistance2(p1, p2) + getDistance2(p2, p3) + getDistance2(p1, p3);
}
int main() {
	Point p1(0, 0), p2(0, 3), p3(4, 0);
	Triangle t(p1, p2, p3);
	cout << "Area: " << t.getArea() << endl;
	cout << "Perimeter: " << t.getPerimeter() << endl;
	return 0;
}