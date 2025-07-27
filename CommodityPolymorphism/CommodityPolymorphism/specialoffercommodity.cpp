#include "specialoffercommodity.h"
#include<iostream>
#include"commodity.h"
using namespace std;
#include <sstream>
int SpecialOfferCommodity::getType()const
{
    return 3;
}
string SpecialOfferCommodity::getInfo()const
{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<SpecialOffer<<endl; //输出子类信息
    return ostr.str();
 }
SpecialOfferCommodity::SpecialOfferCommodity(long id,std::string name,double p,int n,double s):Commodity(id,name,p,n),SpecialOffer(s)
{
}
SpecialOfferCommodity::SpecialOfferCommodity(std::string name,double p,int n,double s):Commodity(name,p,n),SpecialOffer(s)
{
}
double SpecialOfferCommodity::getNetPrice()const
{
    return SpecialOffer*(this->getNum());
}
void SpecialOfferCommodity::output()const
{
    Commodity::output();
    cout<<"商品总价:"<<getNetPrice()<<"(价格:"<<getPrice()<<",数量:"<<getNum()<<",特价:"<<SpecialOffer<<")\n";
}
Commodity* SpecialOfferCommodity::clone()
{
    return new SpecialOfferCommodity (*this);
}
void SpecialOfferCommodity::changeinformation()
{
    char temp;
    cout<<"请输入要修改的值(1:品名、2:价格、3:数量、4:特价)"<<endl;
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
        double specialoffer;
        cout<<"请输入要修改的值";
        cin>>specialoffer;
        this->setSpecialOffer(specialoffer);
    }
}
