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
Point3D::Point3D(double newX, double newY, double newZ) :Point(newX, newY), z(newZ)//Ҫ��ʹ�ó�ʼ���б�,��������й�һ��һ��ȱʡֵ����,�������ﲻ����дȱʡֵ��
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
}//������ӵ���ϸ�������ݳ�Ա,�����������ܷ���,���ʱ�����ͨ�����нӿ�?
int main()
{
	Point p1(3, 4), p2(5, 3);
	Point3D p1_3D(3, 4, 6);
	Point3D p2_3D(2, 6, 9);
	double dis = p1.getDistance(p2);  //�����ά�� p1 �� p2 �ľ��� 
	cout << "Distance between p1 and p2: " << dis << endl;
	dis = p1.getDistance(p2_3D);  //���� p1 �� p2_3D �ľ��� 
	cout << "Distance between p1 and p2_3D: " << dis << endl;
	dis = p1_3D.getDistance(p2);  //����� p1_3D �� p2 �ľ���
	cout << "Distance between p1_3D and p2: " << dis << endl;
	return 0;
}
//����p13d��Point3D��ʵ��,����Point3D��getDistance����Ҫ������һ��Point3D��Ķ���,���ﳢ�԰�Point���ʵ�����뵽Point3D�Ĳ�����,���Գ�����
//�����������,���Ǵ���һ��PointתPoint3D������,������Point3D�¼�������һ����������Point��Ĳ���