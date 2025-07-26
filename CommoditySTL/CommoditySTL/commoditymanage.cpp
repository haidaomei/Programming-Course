#include"commoditymanage.h"
#include<iostream>
#include<fstream>
#include<istream>
#include<algorithm>
#include "normalcommodity.h"
#include "overseacommodity.h"
using namespace std;
CommodityManage::~CommodityManage()
{
    for(auto e: pCommodities)
    delete e;
}
void CommodityManage::addCommodity(Commodity* p)
{
    Commodity* pCommodity2=findCommodityByName(p->getName());
    if(pCommodity2!=nullptr)
    {
        cout<<"Ʒ��Ϊ"<<p->getName()<<"����Ʒ�Ѿ�����!�ۼ�������\n";
        pCommodity2->setNum(pCommodity2->getNum()+p->getNum());
    }
    Commodity* pCommodity=findCommodityById(p->getId());
    if(pCommodity!=nullptr)
    {
        cout<<"���Ϊ"<<p->getId()<<"����Ʒ�Ѿ�����!�ۼ�������\n";
        pCommodity->setNum(pCommodity->getNum()+p->getNum());
        return;
    }
    pCommodities.push_back(p->clone() );
    sortCommodities();
}
void CommodityManage::removeCommodity(int id)
{
    Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr)
    {
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n";
        return;
    }
    pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::viewCommodity(int id)const
{
    const Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr)
    {
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities()const
{
    if(pCommodities.size()==0)
    return;
    cout<<"ָ������ʽ(0-��Ʒid,1-��Ʒ����,2-��Ʒ����,3-����,4-�۸�):";
    int type;
    cin>>type;
    if(type==0||type==1||type==2)
    {
        const_cast<CommodityManage*>(this)->sortCommoditiesByType(type);
        for(auto e:pCommodities)
        e->output();
    }
    else if(type==3||type==4)
    {
        auto a=pCommodities;
        if(type==3)
        {
            sort(a.begin(), a.end(),[](Commodity* a, Commodity* b) { return a->getNum() > b->getNum(); });//ע��pCommoditiesװ����ָ��,Ҫʹ��ָ��ָ��Ļ�����lambda���ʽ��
            cout<<"��Ʒ����:"<<pCommodities.size()<<endl;
            for(auto e:a)
            e->output();
        }
        else if(type==4)
        {
            sort(a.begin(), a.end(),[](Commodity* a, Commodity* b) { return a->getPrice() > b->getPrice(); });
            cout<<"��Ʒ����:"<<pCommodities.size()<<endl;
            for(auto e:a)
            e->output();
        }
    }
}//��Ҫ�ر�ע������������const���ǲ����޸ĳ�Ա ����ֱ��ʹ��sort�������޷�ͨ������� ��������������׳��ֵĴ���
Commodity* CommodityManage::findCommodityById(int id)
{
    vector<Commodity*>::iterator it=find_if(pCommodities.begin(),
    pCommodities.end(), [=](Commodity* p){return p->getId()==id;});
    if(it!=pCommodities.end())
    {
        return *it;
    }
    return nullptr;
}

void CommodityManage::checkOut()const
{
    double totalPrice=0;
    int totalNum=0;
    cout<<"��Ʒ����:"<<pCommodities.size()<<endl;
    cout<<"��Ʒ����\t\t"<<"�۸�\t"<<"����\t"<<"�ܼ�\n";
    for(auto e:pCommodities)
    {
        double price=e->getNetPrice();
        cout<<" "<<e->getName()<<"\t";
        cout<<e->getPrice()<<"\t"<<e->getNum()<<"\t"<<price<<endl;
        totalPrice+=price;
        totalNum+=e->getNum();
    }
    cout<<"��������Ʒ�ܼ���:"<<totalNum<<"\n";
    cout<<"�����������ܼ�:"<<totalPrice<<endl;
}
void CommodityManage::saveData(string filename)
{
    ofstream out(filename);
    if(out)
    {
        out<< pCommodities.size()<<endl;
        out<<Commodity::getNextId()<<endl;
        for(auto e : pCommodities)
        {
            out<<e->getInfo();
        }
    }
}
void CommodityManage::readData(string filename)
{
    ifstream in(filename);
    if(in)
    {
        int commoditySize;
        long nextId;
        in>>commoditySize>>nextId;
        Commodity::setNextId(nextId);
        int type;
        long id;
        string name,buf;
        double price,discount;
        double tariff;
        int num;
        for(int i=0;i< commoditySize;++i)
        {
            in>>type;
            in>>id;
            getline(in,buf);
            getline(in,name);
            in>>price>>num;
            if(type==0)
            {
                in>>discount;
                NormalCommodity nc(id,name,price,num,discount);
                addCommodity(&nc);
            }
            else if(type==1)
            {
                in>>discount>>tariff;
                OverseaCommodity *pc=new OverseaCommodity(id,name,price,num,discount,tariff);
                addCommodity(pc);
                delete pc;
            }
            in.close();
        }
        sortCommodities();
    }
}
const Commodity*CommodityManage::findCommodityById(int id)const
{
    vector<Commodity*>::const_iterator it=find_if(pCommodities.begin(),
    pCommodities.end(), [=](const Commodity* p){return p->getId()==id;});
    if(it!=pCommodities.end())
    {
        return *it;
    }
    return nullptr;
}
vector<Commodity*>::iterator CommodityManage::getIterator(Commodity*p)
{
    for(auto it=pCommodities.begin();it!=pCommodities.end();++it)
    {
        if(*it==p)
        {
            return it;
        }
    }
    return pCommodities.end();
}
void CommodityManage::sortCommodities()
{
    switch(sortType)
    {
    case 0: //����id����
        sort(pCommodities.begin(),pCommodities.end(),[=](Commodity*p1,Commodity*p2){return p1->getId()<p2->getId();});
        break;
    case 1: //������������
        sort(pCommodities.begin(),pCommodities.end(),[=](Commodity*p1,Commodity*p2){return p1->getName()<p2->getName();});
        break;
    case 2: //���ݾ�������
        sort(pCommodities.begin(),pCommodities.end(),[=](Commodity*p1,Commodity*p2){
        return p1->getNetPrice()<p2->getNetPrice();});
    break;
    }
}
void CommodityManage::sortCommoditiesByType(int type)
{
    if(type==sortType) //�Ѿ���ָ����������ֱ�ӷ���
    {
        return;
    }
    sortType=type;
    sortCommodities();
}
Commodity* CommodityManage::findCommodityByName(string name)
{
    auto it=find_if(pCommodities.begin(),pCommodities.end(), [&name](const Commodity* p){return p->getName()==name;});
    if(it==pCommodities.end())
    {
        return nullptr;
    }
    else
    {
        return *it;
    }
}
