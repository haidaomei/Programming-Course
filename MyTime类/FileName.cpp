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
int main()
{
	return 0;
}