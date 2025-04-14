#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <functional> 
using namespace std;
class Predicate
{
public:
	bool operator()(int value)
	{
		if (value <= 20)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};
bool predicate(int value)
{
	if (value <= 20)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	vector<int> vec{ 2,4,5,6,10,15,3,21,36,72,9,13 };
	vector<int> result;
	result.resize(vec.size());
	Predicate a;
	auto end = copy_if(vec.begin(), vec.end(), result.begin(), predicate);
	//predicate可以换成[](int value){if (value <= 20){return 1;}else { return 0; }}
	//这是lambda表达式(匿名函数)的知识
	//predicate还可以换成a,因为我在predicate类中确定了一个()的重载;copy_if中,谓词如果填写的是一个对象,那么copy_if执行时的判断条件,就是这个对象所在的类的()运算符重载函数体内的内容
	//predicate还可以换乘Predicate(),这是构造临时对象的知识,这里可以说的又多了,不过暂时理解成临时对象的一个应用是在谓词吧
	result.erase(end, result.end());
	for_each(result.begin(), result.end(), [](int e) {cout << e << endl; });
	return 0;
}