#include<iostream>
#include"commodity.h"
#include<sstream>
using namespace std;
string Commodity::getInfo()const
{
    ostringstream ostr;
    ostr<<getId()<<endl;
    ostr<<getName()<<endl;
    ostr<<price<<""<<num<<"";
    return ostr.str();
}
long Commodity::nextId=100;
Commodity::Commodity(string n,double p,int nu):Commodity(autoNextId(),n,p,nu)
{
}
Commodity::Commodity(long i,std::string n,double p,int nu):id(i),name(n),price(p),num(nu)
{
}
double Commodity::getNetPrice()const
{
    return price*num;
}
void Commodity::output()const
{
    cout<<" ��Ʒ���(id):"<<id<<endl;
    cout<<"��Ʒ����:"<<name<<endl;
}
void Commodity::changeinformation()
{
    char temp;
    cout<<"������Ҫ�޸ĵ�ֵ(1:Ʒ����2:�۸�3:����)"<<endl;
    cin>>temp;
    if(temp=='1')
    {
        string name;
        cout<<"�������޸ĵ�ֵ";
        cin>>name;
        this->setName(name);
    }
    else if(temp=='2')
    {
        double price;
        cout<<"�������޸ĵ�ֵ";
        cin>>price;
        this->setPrice(price);
    }
    else if(temp=='3')
    {
        int num;
        cout<<"������Ҫ�޸ĵ�ֵ";
        cin>>num;
        this->setNum(num);
    }
}
