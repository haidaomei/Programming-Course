#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class RandomNum {
public:
	RandomNum();  //用系统当前时间设置随机数种子 
	RandomNum(unsigned int seed);  //用传入的 seed 设置随机数种子 
	void setSeed(unsigned int seed);  //重置不同的随机数种子 
	int random();  //产生 0~RAND_MAX 的整数 
	int random(int max);  //产生 0~max 之间的随机数（不含max） 
	int random(int min, int max); //产生 min~max 之间的随机数（不含 max） 
	double frandom();  //产生 0~1.0 之间的 double 型随机数（不含 1.0） 
};
RandomNum::RandomNum()
{
	srand((unsigned)time(NULL));//特别注意,传统c++程序中,srand设置的是全局种子,整个程序中只能存在一个有效种子,每次新调用srand都会覆盖之前的种子值
}
RandomNum::RandomNum(unsigned int seed)
{
	srand(seed);
}
void RandomNum::setSeed(unsigned int seed)
{
	srand(seed);//全局种子,这里不用考虑上面两个函数的操作,直接重新设置一个覆盖掉,所以以上三个函数都只有srand一个命令
}
int RandomNum::random()//函数版本1
{
    int a=rand();
    return a;
}
int RandomNum::random(int max)//函数版本2
{
    int a=rand()%(max-0+1)+0;
    return a;
}
int RandomNum::random(int min,int max)//函数版本3
{
    int a=rand()%(max-min+1)+min;
    return a;
}
double RandomNum::frandom()
{
    int a=1.0*rand();
    return a;
}
int main(void)
{
    RandomNum randomGenerator;
	int i;
	for(i=0;i<10;++i)
		cout<<randomGenerator.random(100)<<' ';
	cout<<"\n";
	for(i=0;i<10;++i)
		cout<<randomGenerator.random(50,100)<<' ';
	cout<<"\n";
	for(i=0;i<10;++i)
		cout<<randomGenerator.frandom()<<' ';
	cout<<"\n";
    return 0;
}
