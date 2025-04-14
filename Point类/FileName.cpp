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
int main() {
	Point p1(3, 4);
	Point p2(5, 2);
	double distance = getDistance1(p1, p2);
	cout << "Distance: " << distance << endl;
	return 0;
}