#include"commoditymanage.h"
#include<iostream>
#include<fstream>
#include<istream>
#include "normalcommodity.h"
#include "overseacommodity.h"
using namespace std;
CommodityManage::CommodityManage():CommodityManage(100)
{
}
CommodityManage::CommodityManage(int s):maxSize(s),size(0)
{
    pCommodities=new Commodity*[maxSize];
}
CommodityManage::~CommodityManage()
{
    for(int i=0;i<size;++i)
    {
        delete pCommodities[i];
    }
    delete[] pCommodities;
    pCommodities=nullptr;
}
void CommodityManage::addCommodity(Commodity* p)
{
    Commodity* pCommodity=findCommodityById(p->getId());
    if(pCommodity!=nullptr)
    {
        cout<<"编号为"<<p->getId()<<"的商品已经存在!累加其数量\n";
        pCommodity->setNum(pCommodity->getNum()+p->getNum());
        return;
    }
    if(size==maxSize)
    {
        reAllocMemory();
    }
    pCommodities[size]=p;
    pCommodities[size]=p->clone();
    size++;
}
void CommodityManage::removeCommodity(int id)
{
    Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr)
    {
        cout<<"编号为"<<id<<"的商品不存在!\n";
        return;
    }
    size--;
    Commodity *temp=pCommodity; //备份找到的指针，后面释放内存
    Commodity **pos=pCommodities+size;
    while(*pos!=pCommodity)
    {
        pos--;
    }
    while(pos<pCommodities+size)
    {
        *pos=*(pos+1);
        pos++;
    }
    delete temp;
}
void CommodityManage::viewCommodity(int id)const
{
    Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr)
    {
        cout<<"编号为"<<id<<"的商品不存在!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities()const
{
    cout<<"商品种类:"<<size<<endl;
    for(int i=0;i<size;++i)
    {
        pCommodities[i]->output();
    }
}
Commodity* CommodityManage::findCommodityById(int id)const
{
    for(int i=0;i<size;++i)
    {
        if(pCommodities[i]->getId()==id)
        return pCommodities[i];
    }
    return nullptr;
}
void CommodityManage::reAllocMemory()
{
    maxSize*=2;
    int i;
    Commodity **temp=pCommodities;
    pCommodities=new Commodity*[maxSize];
    for(i=0;i<size;++i)
    {
        pCommodities[i]=temp[i];
    }
    delete[] temp;
}
void CommodityManage::checkOut()const
{
    double totalPrice=0;
    int totalNum=0;
    cout<<"商品种类: "<<size<<endl;
    cout<<" 商品名称\t\t"<<"价格\t"<<"件数\t"<<"总价\n";
    for(int i=0;i<size;++i)
    {
        double price=pCommodities[i]->getNetPrice();
        cout<<" "<<pCommodities[i]->getName()<<"\t";
        cout<<pCommodities[i]->getPrice()<<"\t"<<pCommodities[i]->getNum()<<"\t"<<price<<endl;
        totalPrice+=price;
        totalNum+=pCommodities[i]->getNum();
    }
    cout<<"购物篮商品总件数:"<<totalNum<<"\n";
    cout<<"购物篮结算总价:"<<totalPrice<<endl;
}
void CommodityManage::saveData(string filename)
{
    ofstream out(filename);
    if(out)
    {
        out<<maxSize<<endl;
        out<<size<<endl;
        out<<Commodity::getNextId()<<endl;
        for(int i=0;i<size;++i)
        {
            out<< pCommodities[i]->getInfo();
        }
    out.close();
    }
}
void CommodityManage::readData(string filename)
{
    ifstream in(filename);
    if(in)
    {
        int commoditySize;
        long nextId;
        in>>maxSize>>commoditySize>>nextId;
        Commodity::setNextId(nextId);
        delete []pCommodities;
        pCommodities=new Commodity*[maxSize];
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
    }
}
void CommodityManage::changingInformation(int id)
{
    Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr)
    {
        cout<<"编号为"<<id<<"的商品不存在!\n";
        return;
    }
    pCommodity->changeinformation();
}
