#include<iostream>
#include"normalcommodity.h"
using namespace std;
#include<sstream>
int NormalCommodity::getType()const
{
    return 0; //0表示普通商品
}
string NormalCommodity::getInfo()const
{
    ostringstream ostr;
    ostr<<getType()<<""; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discount<<endl; //输出子类信息
    return ostr.str();
}
NormalCommodity::NormalCommodity(long id,std::string name,double p,int n,double d):Commodity(id,name,p,n),discount(d)
{
}
NormalCommodity::NormalCommodity(std::string name,double p,int n,double d):Commodity(name,p,n),discount(d)
{
}
double NormalCommodity::getNetPrice()const
{
    return Commodity::getNetPrice()*discount;
}
void NormalCommodity::output()const
{
    Commodity::output();
    cout<<"商品总价:"<<getNetPrice()<<"(价格:"<<getPrice()<<",数量:"<<getNum()<<",折扣:"<<discount<<")\n";
}
Commodity* NormalCommodity::clone()
{
    return new NormalCommodity(*this);
}
void NormalCommodity::changeinformation()
{
    char temp;
    cout<<"请输入要修改的值(1:品名、2:价格、3:数量、4:折扣)"<<endl;
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
}
