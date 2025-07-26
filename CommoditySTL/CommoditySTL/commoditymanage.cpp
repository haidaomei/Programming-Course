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
        cout<<"品名为"<<p->getName()<<"的商品已经存在!累加其数量\n";
        pCommodity2->setNum(pCommodity2->getNum()+p->getNum());
    }
    Commodity* pCommodity=findCommodityById(p->getId());
    if(pCommodity!=nullptr)
    {
        cout<<"编号为"<<p->getId()<<"的商品已经存在!累加其数量\n";
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
        cout<<"编号为"<<id<<"的商品不存在!\n";
        return;
    }
    pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::viewCommodity(int id)const
{
    const Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr)
    {
        cout<<"编号为"<<id<<"的商品不存在!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities()const
{
    if(pCommodities.size()==0)
    return;
    cout<<"指定排序方式(0-商品id,1-商品名称,2-商品净价,3-数量,4-价格):";
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
            sort(a.begin(), a.end(),[](Commodity* a, Commodity* b) { return a->getNum() > b->getNum(); });//注意pCommodities装的是指针,要使用指针指向的话就用lambda表达式吧
            cout<<"商品种类:"<<pCommodities.size()<<endl;
            for(auto e:a)
            e->output();
        }
        else if(type==4)
        {
            sort(a.begin(), a.end(),[](Commodity* a, Commodity* b) { return a->getPrice() > b->getPrice(); });
            cout<<"商品种类:"<<pCommodities.size()<<endl;
            for(auto e:a)
            e->output();
        }
    }
}//还要特别注意这里声明了const但是不能修改成员 所以直接使用sort排序是无法通过编译的 这是最根本最容易出现的错误
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
    cout<<"商品种类:"<<pCommodities.size()<<endl;
    cout<<"商品名称\t\t"<<"价格\t"<<"件数\t"<<"总价\n";
    for(auto e:pCommodities)
    {
        double price=e->getNetPrice();
        cout<<" "<<e->getName()<<"\t";
        cout<<e->getPrice()<<"\t"<<e->getNum()<<"\t"<<price<<endl;
        totalPrice+=price;
        totalNum+=e->getNum();
    }
    cout<<"购物篮商品总件数:"<<totalNum<<"\n";
    cout<<"购物篮结算总价:"<<totalPrice<<endl;
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
    case 0: //根据id排序
        sort(pCommodities.begin(),pCommodities.end(),[=](Commodity*p1,Commodity*p2){return p1->getId()<p2->getId();});
        break;
    case 1: //根据名称排序
        sort(pCommodities.begin(),pCommodities.end(),[=](Commodity*p1,Commodity*p2){return p1->getName()<p2->getName();});
        break;
    case 2: //根据净价排序
        sort(pCommodities.begin(),pCommodities.end(),[=](Commodity*p1,Commodity*p2){
        return p1->getNetPrice()<p2->getNetPrice();});
    break;
    }
}
void CommodityManage::sortCommoditiesByType(int type)
{
    if(type==sortType) //已经按指定规则排序，直接返回
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
