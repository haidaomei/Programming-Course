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
    cout<<" 商品编号(id):"<<id<<endl;
    cout<<"商品名称:"<<name<<endl;
}
void Commodity::changeinformation()
{
    char temp;
    cout<<"请输入要修改的值(1:品名、2:价格、3:数量)"<<endl;
    cin>>temp;
    if(temp=='1')
    {
        string name;
        cout<<"请输入修改的值";
        cin>>name;
        this->setName(name);
    }
    else if(temp=='2')
    {
        double price;
        cout<<"请输入修改的值";
        cin>>price;
        this->setPrice(price);
    }
    else if(temp=='3')
    {
        int num;
        cout<<"请输入要修改的值";
        cin>>num;
        this->setNum(num);
    }
}
