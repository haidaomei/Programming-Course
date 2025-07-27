#include<iostream>
#include"overseacommodity.h"
using namespace std;
#include <sstream>
int OverseaCommodity::getType()const
{
    return 1; //1 表示海外购商品
}
string OverseaCommodity::getInfo()const
{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discount<<" "<<tariff<<endl; //输出子类信息
    return ostr.str();
 }
OverseaCommodity::OverseaCommodity(long id,std::string name,double p,int n,double d,double t):Commodity(id,name,p,n),discount(d),tariff(t)
{
}
OverseaCommodity::OverseaCommodity(std::string name,double p,int n,double d,double t):Commodity(name,p,n),discount(d),tariff(t)
{
}
double OverseaCommodity::getNetPrice()const
{
    return Commodity::getNetPrice()*discount+tariff;
}
void OverseaCommodity::output()const
{
    Commodity::output();
    cout<<"商品总价:"<<getNetPrice()<<"(价格:"<<getPrice()<<",数量:"<<getNum()<<",折扣:"<<discount<<",关税:"<<tariff<<")\n";
}
Commodity* OverseaCommodity::clone()
{
    return new OverseaCommodity (*this);
}
void OverseaCommodity::changeinformation()
{
    char temp;
    cout<<"请输入要修改的值(1:品名、2:价格、3:数量、4:折扣、5:关税)"<<endl;
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
    else if(temp=='4')
    {
        double discount;
        cout<<"请输入要修改的值";
        cin>>discount;
        this->setDiscount(discount);
    }
    else if(temp=='5')
    {
        double tariff;
        cout<<"请输入要修改的值";
        cin>>tariff;
        this->setTariff(tariff);
    }
}
