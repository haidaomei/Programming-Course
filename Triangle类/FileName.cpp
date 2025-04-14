#include<iostream>
#include<math.h>
using namespace std;
class Point
{
public:
	Point(double newX, double newY);//原本这里写成Point( double newX=0, double newY=0);但是这样写在vs2022报错
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
double getDistance1(const Point& p1, const Point& p2);//函数声明必须放在Point类设置之后,本来想把这句放到include头文件之下,发现不行
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
	Triangle(const Point& p1, const Point& p2, const Point& p3);//我感觉源程序这里输入不应该取和下面三个成员变量相同的名字,这里原指令是Triangle(const Point& p1, const Point& p2, const Point& p3);
	double getArea()const;  //计算三角形的面积 
	double getPerimeter()const;  //计算三角形周长 
private:
	Point p1, p2, p3;  //三角形 3 个顶点 
};
Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) :p1(p1), p2(p2), p3(p3)
{
}//这里必须使用成员初始化列表,不能是p1=p1,p2=p2,p3=p3
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