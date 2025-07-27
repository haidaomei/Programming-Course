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
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<discount<<" "<<level<<endl; //���������Ϣ
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
    cout<<"��Ʒ�ܼ�:"<<getNetPrice()<<"(�۸�:"<<getPrice()<<",����:"<<getNum()<<",�ۿ�:"<<discount<<",�۾�:"<<level<<")\n";
}
Commodity* SecondhandCommodity::clone()
{
    return new SecondhandCommodity (*this);
}
void SecondhandCommodity::changeinformation()
{
    char temp;
    cout<<"������Ҫ�޸ĵ�ֵ(1:Ʒ����2:�۸�3:������4:�ۿۡ�5:�۾�)"<<endl;
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
    else if(temp=='4')
    {
        double discount;
        cout<<"������Ҫ�޸ĵ�ֵ";
        cin>>discount;
        this->setDiscount(discount);
    }
    else if(temp=='5')
    {
        double level;
        cout<<"������Ҫ�޸ĵ�ֵ";
        cin>>level;
        this->setLevel(level);
    }
}
