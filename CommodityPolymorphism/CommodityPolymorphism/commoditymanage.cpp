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
        cout<<"���Ϊ"<<p->getId()<<"����Ʒ�Ѿ�����!�ۼ�������\n";
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
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n";
        return;
    }
    size--;
    Commodity *temp=pCommodity; //�����ҵ���ָ�룬�����ͷ��ڴ�
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
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities()const
{
    cout<<"��Ʒ����:"<<size<<endl;
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
    cout<<"��Ʒ����: "<<size<<endl;
    cout<<" ��Ʒ����\t\t"<<"�۸�\t"<<"����\t"<<"�ܼ�\n";
    for(int i=0;i<size;++i)
    {
        double price=pCommodities[i]->getNetPrice();
        cout<<" "<<pCommodities[i]->getName()<<"\t";
        cout<<pCommodities[i]->getPrice()<<"\t"<<pCommodities[i]->getNum()<<"\t"<<price<<endl;
        totalPrice+=price;
        totalNum+=pCommodities[i]->getNum();
    }
    cout<<"��������Ʒ�ܼ���:"<<totalNum<<"\n";
    cout<<"�����������ܼ�:"<<totalPrice<<endl;
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
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n";
        return;
    }
    pCommodity->changeinformation();
}
