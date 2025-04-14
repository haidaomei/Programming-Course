#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class RandomNum {
public:
	RandomNum();  //��ϵͳ��ǰʱ��������������� 
	RandomNum(unsigned int seed);  //�ô���� seed ������������� 
	void setSeed(unsigned int seed);  //���ò�ͬ����������� 
	int random();  //���� 0~RAND_MAX ������ 
	int random(int max);  //���� 0~max ֮��������������max�� 
	int random(int min, int max); //���� min~max ֮�������������� max�� 
	double frandom();  //���� 0~1.0 ֮��� double ������������� 1.0�� 
};
RandomNum::RandomNum()
{
	srand((unsigned)time(NULL));//�ر�ע��,��ͳc++������,srand���õ���ȫ������,����������ֻ�ܴ���һ����Ч����,ÿ���µ���srand���Ḳ��֮ǰ������ֵ
}
RandomNum::RandomNum(unsigned int seed)
{
	srand(seed);
}
void RandomNum::setSeed(unsigned int seed)
{
	srand(seed);//ȫ������,���ﲻ�ÿ����������������Ĳ���,ֱ����������һ�����ǵ�,������������������ֻ��srandһ������
}
int RandomNum::random()//�����汾1
{
    int a=rand();
    return a;
}
int RandomNum::random(int max)//�����汾2
{
    int a=rand()%(max-0+1)+0;
    return a;
}
int RandomNum::random(int min,int max)//�����汾3
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
