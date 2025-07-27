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
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<SpecialOffer<<endl; //���������Ϣ
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
    cout<<"��Ʒ�ܼ�:"<<getNetPrice()<<"(�۸�:"<<getPrice()<<",����:"<<getNum()<<",�ؼ�:"<<SpecialOffer<<")\n";
}
Commodity* SpecialOfferCommodity::clone()
{
    return new SpecialOfferCommodity (*this);
}
void SpecialOfferCommodity::changeinformation()
{
    char temp;
    cout<<"������Ҫ�޸ĵ�ֵ(1:Ʒ����2:�۸�3:������4:�ؼ�)"<<endl;
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
        double specialoffer;
        cout<<"������Ҫ�޸ĵ�ֵ";
        cin>>specialoffer;
        this->setSpecialOffer(specialoffer);
    }
}
