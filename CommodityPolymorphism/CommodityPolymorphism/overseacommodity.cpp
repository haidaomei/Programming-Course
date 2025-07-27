#include<iostream>
#include"overseacommodity.h"
using namespace std;
#include <sstream>
int OverseaCommodity::getType()const
{
    return 1; //1 ��ʾ���⹺��Ʒ
}
string OverseaCommodity::getInfo()const
{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<discount<<" "<<tariff<<endl; //���������Ϣ
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
    cout<<"��Ʒ�ܼ�:"<<getNetPrice()<<"(�۸�:"<<getPrice()<<",����:"<<getNum()<<",�ۿ�:"<<discount<<",��˰:"<<tariff<<")\n";
}
Commodity* OverseaCommodity::clone()
{
    return new OverseaCommodity (*this);
}
void OverseaCommodity::changeinformation()
{
    char temp;
    cout<<"������Ҫ�޸ĵ�ֵ(1:Ʒ����2:�۸�3:������4:�ۿۡ�5:��˰)"<<endl;
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
        double tariff;
        cout<<"������Ҫ�޸ĵ�ֵ";
        cin>>tariff;
        this->setTariff(tariff);
    }
}
