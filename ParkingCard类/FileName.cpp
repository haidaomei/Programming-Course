#include<iostream>
using namespace std;
class MyTime
{
public:
	MyTime();
	MyTime(int h, int m); //通过指定 h 和 m 构造 MyTime 对象 
	MyTime(int minutes);  //通过指定分钟数构造 MyTime对象 
	void setTime(int h, int m);  //设置新的时间 
	//void output() const;  //以 hh:mm 格式输出时间 
	int getHour() const;
	//获得小时 
	int getMinute() const;  //获得分钟 
	int getTotalMinutes() const;  //获得从 0 点 0 分起的总分钟数 
	//MyTime getTimeSpan(const MyTime& t)const; //计算时间差 
	friend std::ostream& operator<<(std::ostream& out, const MyTime& t);
	MyTime operator-(const MyTime& newTime)const; //计算时间差 
private:
	int hour;
	int minute;
	void normalizeTime();  //规范化小时为 0~23，分钟为 0~59 
};
MyTime::MyTime()
{
	hour = 0;
	minute = 0;
	normalizeTime();
}
MyTime::MyTime(int h, int m)
{
	hour = h;
	minute = m;
	normalizeTime();
}
void MyTime::setTime(int h, int m)
{
	hour = h;
	minute = m;
	normalizeTime();
}
void MyTime::normalizeTime()
{
	if (minute >= 60)
	{
		minute = minute - 60;
		hour = hour + 1;
	}
	if (hour >= 24)
	{
		hour = hour % 24;
	}
}
/*void MyTime::output()const
{
	if (hour < 10)
	{
		if (minute < 10)
		{
			cout << '0' << hour << ':' << '0' << minute << endl;
		}
		else
		{
			cout << '0' << hour << ':' << minute << endl;
		}
	}
	else
	{
		if (minute < 10)
		{
			cout << hour << ':' << '0' << minute << endl;
		}
		else
		{
			cout << hour << ':' << minute << endl;
		}
	}
}*/
MyTime::MyTime(int minutes)
{
	minute = minutes;
	normalizeTime();
}
int MyTime::getHour()const
{
	return hour;
}
int MyTime::getMinute()const
{
	return minute;
}
int MyTime::getTotalMinutes()const
{
	return hour * 60 + minute;
}
/*MyTime MyTime::getTimeSpan(const MyTime& t)const
{
	MyTime a;
	if (t.hour > hour)
	{
		if (t.minute > minute)
		{
			a.hour = t.hour - hour;
			a.minute = t.minute - minute;
		}
		else
		{
			a.hour = t.hour - hour - 1;
			a.minute = 60 + t.minute - minute;
		}
	}
	else
	{
		if (t.minute > minute)
		{
			a.hour = hour - t.hour - 1;
			a.minute = 60 + minute - t.minute;
		}
		else
		{
			a.hour = hour - t.hour;
			a.minute = minute - t.minute;
		}
	}
	return a;
}*/
std::ostream& operator<<(std::ostream& out, const MyTime& t)
{
	if (t.hour < 10)
	{
		if (t.minute < 10)
		{
			out << '0' << t.hour << ':' << '0' << t.minute << endl;
			return out;
		}
		else
		{
			out << '0' << t.hour << ':' << t.minute << endl;
			return out;
		}
	}
	else
	{
		if (t.minute < 10)
		{
			out << t.hour << ':' << '0' << t.minute << endl;
			return out;
		}
		else
		{
			out << t.hour << ':' << t.minute << endl;
			return out;
		}
	}
}//注意完善输入输出流概念
MyTime MyTime::operator-(const MyTime& newTime)const
{
	MyTime a;
	if (newTime.hour > hour)
	{
		if (newTime.minute > minute)
		{
			a.hour = newTime.hour - hour;
			a.minute = newTime.minute - minute;
		}
		else
		{
			a.hour = newTime.hour - hour - 1;
			a.minute = 60 + newTime.minute - minute;
		}
	}
	else
	{
		if (newTime.minute > minute)
		{
			a.hour = hour - newTime.hour - 1;
			a.minute = 60 + minute - newTime.minute;
		}
		else
		{
			a.hour = hour - newTime.hour;
			a.minute = minute - newTime.minute;
		}
	}
	return a;
}
class ParkingCard
{
public:
	ParkingCard(double newRate)
	{
		rate = newRate;
	}
	void setRate(double newRate)
	{ 
		rate = newRate;
	}  //设置每小时费率 
	double getRate() const
	{ 
		return rate;
	}
	void setParkingTime(const MyTime& time);  //设置开始停车时间 
	void setLeavingTime(const MyTime& time);  //设置离开时间 
	double getTotalExpenses() const;  //计算停车费用 
	//停车时间分钟数不足半小时按半小时计算，不足1小时按1小时计算 
	//void output() const;  //输出停车起始时间、费率及总费用 
	friend std::ostream& operator<<(std::ostream& out, const ParkingCard& t);
private:
	double rate; //停车费率，按元/每小时计算 
	MyTime parkingTime; //开始停车时间 
	MyTime leavingTime; //离开时间 
};
void ParkingCard::setParkingTime(const MyTime& time)
{
	parkingTime = time;
}
void ParkingCard::setLeavingTime(const MyTime& time)
{
	leavingTime = time;
}
double ParkingCard::getTotalExpenses()const
{
	MyTime a;
	int b, c;
	a = parkingTime - leavingTime;
	b = a.getHour();
	c = a.getMinute();
	return ((b * 60 + c) / 30 * rate) + (b * 1.0 * 60 + c * 1.0) / 30.0 > 0 ? rate : 0;//总分钟除以30得多少个半小时,这里一定要去尾,如果有余则加一个rate
}
/*void ParkingCard::output()const
{
	int hour, minute;
	hour = parkingTime.getHour();
	minute = parkingTime.getMinute();
	if (hour < 10)
	{
		if (minute < 10)
		{
			cout << '0' << hour << ':' << '0' << minute << endl;
			cout << rate << endl;
			cout << getTotalExpenses() << endl;
		}
		else
		{
			cout << '0' << hour << ':' << minute << endl;
			cout << rate << endl;
			cout << getTotalExpenses() << endl;
		}
	}
	else
	{
		if (minute < 10)
		{
			cout << hour << ':' << '0' << minute << endl;
			cout << rate << endl;
			cout << getTotalExpenses() << endl;
		}
		else
		{
			cout << hour << ':' << minute << endl;
			cout << rate << endl;
			cout << getTotalExpenses() << endl;//指针指向执行该函数的对象,这里不写成parkingTime.getTotalExpenses,也不写成ParkingCard类型的对象.getTotalExpenses
		}
	}
}*/
std::ostream& operator<<(std::ostream& out, const ParkingCard& t)//不能只复制output的程序过来,因为output是成员函数,这是友元函数,所以调用要大改组
{//不要忘记对象是card传入这里是t,下面getTotalExpenses的时候要用
	int hour, minute;
	hour = t.parkingTime.getHour();
	minute = t.parkingTime.getMinute();
	if (hour < 10)
	{
		if (minute < 10)
		{
			out << '0' << hour << ':' << '0' << minute << endl << t.rate << endl << t.getTotalExpenses() << endl;
			return out;
		}
		else
		{
			out << '0' << hour << ':' << minute << endl << t.rate << endl << t.getTotalExpenses() << endl;
			return out;
		}
	}
	else
	{
		if (minute < 10)
		{
			out << hour << ':' << '0' << minute << endl << t.rate << endl << t.getTotalExpenses() << endl;
			return out;
		}
		else
		{
			out << hour << ':' << minute << endl << t.rate << endl << t.getTotalExpenses() << endl;
			return out;
		}
	}
}
int main() {
	ParkingCard card(5);
	card.setParkingTime(MyTime(9, 20));
	card.setLeavingTime(MyTime(11, 35));
	//构造临时时间对象并作为参数 
	cout << "Expenses: " << card.getTotalExpenses() << endl;
	cout << "Detailed info:\n";
	cout << card << endl;
	return 0;
}