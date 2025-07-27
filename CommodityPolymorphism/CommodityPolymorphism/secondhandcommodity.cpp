#include "secondhandcommodity.h"
#include<iostream>
using namespace std;
#include <sstream>
int SecondhandCommodity::getType()const
{
    return 2;
}
string SecondhandCommodity::getInfo()const
{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discount<<" "<<level<<endl; //输出子类信息
    return ostr.str();
 }
SecondhandCommodity::SecondhandCommodity(long id,std::string name,double p,int n,double d,double l):Commodity(id,name,p,n),discount(d),level(l)
{
}
SecondhandCommodity::SecondhandCommodity(std::string name,double p,int n,double d,double l):Commodity(name,p,n),discount(d),level(l)
{
}
double SecondhandCommodity::getNetPrice()const
{
    return Commodity::getNetPrice()*discount*level;
}
void SecondhandCommodity::output()const
{
    Commodity::output();
    cout<<"商品总价:"<<getNetPrice()<<"(价格:"<<getPrice()<<",数量:"<<getNum()<<",折扣:"<<discount<<",折旧:"<<level<<")\n";
}
Commodity* SecondhandCommodity::clone()
{
    return new SecondhandCommodity (*this);
}
void SecondhandCommodity::changeinformation()
{
    char temp;
    cout<<"请输入要修改的值(1:品名、2:价格、3:数量、4:折扣、5:折旧)"<<endl;
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
        double level;
        cout<<"请输入要修改的值";
        cin>>level;
        this->setLevel(level);
    }
}
