#include"normalcommodity.h"
#include"overseacommodity.h"
#include"function.h"
#include"secondhandcommodity.h"
#include"specialoffercommodity.h"
#include<string>
#include<iostream>
using namespace std;
void doAddCommodity(CommodityManage &cm)
{
    string name;
    double price,discount;
    double tariff;
    double level;
    double specialoffer;
    int num,type;
    cout<<"ѡ����Ʒ����(0-��ͨ��Ʒ��1-���⹺��Ʒ��2-������Ʒ��3-�ؼ���Ʒ)";
    cin>>type;
    fflush(stdin);
    cout<<"������Ʒ����:";
    getline(cin,name);
    cout<<"����۸����Ʒ����:";
    cin>>price>>num;
    if(type==0)
    {
        cout<<"������Ʒ�ۿ�:";
        cin>>discount;
        NormalCommodity nc(name,price,num,discount);
        cm.addCommodity(&nc);
    }
    else if(type==1)
    {
        cout<<"������Ʒ�ۿۺ͹�˰:";
        cin>>discount>>tariff;
        Commodity* pc=new OverseaCommodity(name,price,num,discount,tariff);
        cm.addCommodity(pc);
        delete pc;
    }
    else if(type==2)
    {
        cout<<"������Ʒ�ۿۺ��۾�:";
        cin>>discount>>level;
        Commodity* pc=new SecondhandCommodity(name,price,num,discount,level);
        cm.addCommodity(pc);
        delete pc;
    }
    else if(type==3)
    {
        cout<<"������Ʒ�ؼ�:";
        cin>>specialoffer;
        Commodity* pc=new SpecialOfferCommodity(name,price,num,specialoffer);
        cm.addCommodity(pc);
        delete pc;
    }
}
char menu()
{
    cout<<" 0)�˳�ϵͳ\n";
    cout<<" 1)�����������Ʒ\n";
    cout<<" 2)�ӹ������Ƴ���Ʒ\n";
    cout<<" 3)�鿴ָ����Ʒ\n";
    cout<<" 4)�鿴������Ʒ\n";
    cout<<" 5)����\n";
    cout<<" 6)�޸���Ϣ\n";
    cout<<"�����빦��ѡ��:";
    char choice;
    cin>>choice;
    return choice;
}
void doRemoveCommodity(CommodityManage &cm)
{
    long id;
    cout<<"Inputid:";
    cin>>id;
    cm.removeCommodity(id);
}
void doViewCommodity(const CommodityManage &cm)
{
    long id;
    cout<<"Inputid:";
    cin>>id;
    cm.viewCommodity(id);
}
void doViewAllCommodity(const CommodityManage &cm)
{
    cm.viewAllCommodities();
}
void doCheckout(const CommodityManage &cm)
{
    cm.checkOut();
}
void doChangeInformation(CommodityManage &cm)
{
    long id;
    cout<<"Inputid:";
    cin>>id;
    cm.changingInformation(id);
}
