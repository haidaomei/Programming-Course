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
	//predicate���Ի���[](int value){if (value <= 20){return 1;}else { return 0; }}
	//����lambda���ʽ(��������)��֪ʶ
	//predicate�����Ի���a,��Ϊ����predicate����ȷ����һ��()������;copy_if��,ν�������д����һ������,��ôcopy_ifִ��ʱ���ж�����,��������������ڵ����()��������غ������ڵ�����
	//predicate�����Ի���Predicate(),���ǹ�����ʱ�����֪ʶ,�������˵���ֶ���,������ʱ������ʱ�����һ��Ӧ������ν�ʰ�
	result.erase(end, result.end());
	for_each(result.begin(), result.end(), [](int e) {cout << e << endl; });
	return 0;
}