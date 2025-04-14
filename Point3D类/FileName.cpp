#include <iostream> 
#include<cmath> 
using namespace std;
class Point
{
public:
	Point(double newX = 0, double newY = 0);
	Point(const Point& p);
	~Point();
	void setValue(double newX, double newY);
	double getX() const;
	double getY() const;
	double getDistance(const Point& p2) const;
private:
	double x, y;
};
//-------------------------
class Point3D : public Point
{
public:
	Point3D(double newX = 0, double newY = 0, double newZ = 0);
	Point3D(const Point& p);
	double getZ() const;
	double getDistance(const Point3D& p)const;
private:
	double z;
};
//-------------------------
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
//-------------------------
Point3D::Point3D(double newX, double newY, double newZ) :Point(newX, newY), z(newZ)//要求使用初始化列表,如果声明有过一次一遍缺省值设置,定义这里不用再写缺省值了
{
}
Point3D::Point3D(const Point& p) :Point(p.getX(), p.getY()), z(0)
{
}
double Point3D::getZ()const
{
	return z;
}
double Point3D::getDistance(const Point3D& p)const
{
	return sqrt((getX() - p.getX()) * (getX() - p.getX()) + (getY() - p.getY()) * (getY() - p.getY()) + (getZ() - p.getZ()) * (getZ() - p.getZ()));
}//派生类拥有上个类的数据成员,但是往往不能访问,这个时候可以通过公有接口?
int main()
{
	Point p1(3, 4), p2(5, 3);
	Point3D p1_3D(3, 4, 6);
	Point3D p2_3D(2, 6, 9);
	double dis = p1.getDistance(p2);  //计算二维点 p1 和 p2 的距离 
	cout << "Distance between p1 and p2: " << dis << endl;
	dis = p1.getDistance(p2_3D);  //计算 p1 和 p2_3D 的距离 
	cout << "Distance between p1 and p2_3D: " << dis << endl;
	dis = p1_3D.getDistance(p2);  //计算点 p1_3D 和 p2 的距离
	cout << "Distance between p1_3D and p2: " << dis << endl;
	return 0;
}
//错在p13d是Point3D的实例,但是Point3D的getDistance必须要求输入一个Point3D类的对象,这里尝试把Point类的实例输入到Point3D的参数中,所以出错了
//解决方案就是,除非存在一个Point转Point3D的重载,或者在Point3D下继续定义一个函数容纳Point类的参数