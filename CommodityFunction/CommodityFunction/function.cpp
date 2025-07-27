#include <iostream>
#include "header.h"
#include <fstream>
#include <algorithm>
using namespace std;
char menu()
{
    cout<<" 0) 退出系统\n";
    cout<<" 1) 向购物篮添加商品\n";
    cout<<" 2) 从购物篮移除商品\n";
    cout<<" 3) 查看指定商品\n";
    cout<<" 4) 查看所有商品\n";
    cout<<" 5) 结算\n";
    cout<<" 6) 修改\n";
    cout<<"请输入功能选项:";
    char choice;
    cin>>choice;
    return choice;
}
void displayCommodities(CommodityInfo* pCommodities,int num)
{
    int i;
    cout<<"商品种类:"<<num<<endl;
    char temp;
    while(1)
    {
        cout<<"请输入要排序的方式(1:按id,2:按商品名称,3:按价格,4:按折扣,5:按总价格)";
        cin>>temp;
        if(temp=='1')
        {
            sort(pCommodities,pCommodities+num,[](CommodityInfo x,CommodityInfo y){return x.id<y.id;});
            break;
        }
        else if(temp=='2')
        {
            sort(pCommodities,pCommodities+num,[](CommodityInfo x,CommodityInfo y){return x.name<y.name;});
            break;
        }
        else if(temp=='3')
        {
            sort(pCommodities,pCommodities+num,[](CommodityInfo x,CommodityInfo y){return x.price<y.price;});
            break;
        }
        else if(temp=='4')
        {
            sort(pCommodities,pCommodities+num,[](CommodityInfo x,CommodityInfo y){return x.num<y.num;});
            break;
        }
        else if(temp=='5')
        {
            sort(pCommodities,pCommodities+num,[](CommodityInfo x,CommodityInfo y){return x.money<y.money;});
            break;
        }
        else
        {
            cout<<"格式有误,请重新输入!";
        }
    }
    for(i=0;i<num;i++)
    {
        showCommodityInfo(&pCommodities[i]);
    }
    cout<<endl;
}
void addCommodity(CommodityInfo* pCommodities,int &num)
{
    int id;
    cout<<"输入商品编号(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    if(index!=-1)
    {//找到商品，累加数量
        cout<<"编号为"<<id<<"的商品已经存在!\n";
        cout<<"请输入增加的商品数量:";
        int number;
        cin>>number;
        pCommodities[index].num+=number;
        return;
    }
    if(num==MAX_COMMODITY_NUM)
    {
        cout<<"没有足够空间了!\n\n";
        return;
    }
    CommodityInfo* pCommodity=&pCommodities[num];//pCommodity是之前find返回的指针,指向目标商品,这里是把指针移到最后一位的后一位进行添加
    pCommodity->id=id;
    setCommodityInfo(pCommodity);
    num++;
    cout<<"商品添加成功!\n\n";
}
void removeCommodity(CommodityInfo* pCommodities,int &num)
{
    int id;
    cout<<"输入商品编号(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    CommodityInfo* pCommodity=pCommodities+index;
    if(index==-1)
    {
        cout<<"编号为"<<id<<"的商品不存在!\n\n";
        return;
    }
    num--;
    CommodityInfo* pNext=pCommodity+1;
    while(pCommodity<pCommodities+num)
    {
        pCommodity->id=pNext->id;
        pCommodity->name=pNext->name;
        pCommodity->price=pNext->price;
        pCommodity->num=pNext->num;
        pCommodity->discount=pNext->discount;
        pCommodity++;
        pNext++;
    }
    cout<<"商品移除成功!\n\n";
}
void viewCommodity(CommodityInfo* pCommodities,int num)
{
    int id;
    cout<<"输入商品的编号(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    if(index==-1)
    {
        cout<<"编号为"<<id<<"的商品不存在!\n\n";
        return;
    }
    showCommodityInfo(pCommodities+index);
    cout<<endl;
}
void checkOut(CommodityInfo* pCommodities,int num)
{
    double totalPrice=0;
    int totalNum=0;
    cout<<"商品种类:"<<num<<endl;
    cout<<"商品名称\t\t"<<"价格\t"<<"件数\t"<<"折扣\t"<<"总价\n";
    for(int i=0;i<num;++i)
    {
        double price=getCommodityPrice(pCommodities+i);
        cout<<" "<<pCommodities[i].name<<"\t";
        cout<<pCommodities[i].price<<"\t"<<pCommodities[i].num<<"\t"<<pCommodities[i].discount<<"\t"<<price<<endl;
        totalPrice+=price;
        totalNum+=pCommodities[i].num;
    }
    cout<<"购物篮商品总件数:"<<totalNum<<"\n";
    cout<<"购物篮结算总价:"<<totalPrice<<endl;
}
void readData(std::string filename)
{
    ifstream in(filename);
    if(in)
    {
        in>>commodityNum;
        if(commodityNum>MAX_COMMODITY_NUM)
        {
            commodityNum=MAX_COMMODITY_NUM;
        }
        string buf;
        for(int i=0;i<commodityNum;++i)
        {
            in>>commodities[i].id;
            getline(in,buf);
            getline(in,commodities[i].name);
            in>>commodities[i].price>>commodities[i].num>>commodities[i].discount;
        }
    in.close();
    }
}
void writeData(std::string filename)
{
    ofstream out(filename);
    if(out)
    {
        out<<commodityNum<<endl;
        for(int i=0;i<commodityNum;++i)
        {
            out<<commodities[i].id<<endl;
            out<<commodities[i].name<<endl;
            out<<commodities[i].price<<""<<commodities[i].num<<""<<commodities[i].discount<<endl;
        }
    out.close();
    }
}
void changeCommodity(CommodityInfo* pCommodities,int num)
{
    int id;
    cout<<"输入商品的编号(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    CommodityInfo* pCommodity=pCommodities+index;
    if(index==-1)
    {
        cout<<"编号为"<<id<<"的商品不存在!\n\n";
        return;
    }
    char temp;
    while(1)
    {
        cout<<"请输入要修改的参数(1:编号,2:名称,3:定价,4:数量,5:折扣)"<<endl;
        cin>>temp;
        if(temp=='1')
        {
            long info1;
            cout<<"请输入修改值!"<<endl;
            cin>>info1;
            pCommodity->id=info1;
            break;
        }
        else if(temp=='2')
        {
            string info2;
            cout<<"请输入修改值!"<<endl;
            cin>>info2;
            pCommodity->name=info2;
            break;
        }
        else if(temp=='3')
        {
            double info3;
            cout<<"请输入修改值!"<<endl;
            cin>>info3;
            pCommodity->price=info3;
            break;
        }
        else if(temp=='4')
        {
            int info4;
            cout<<"请输入修改值!"<<endl;
            cin>>info4;
            pCommodity->num=info4;
            break;
        }
        else if(temp=='5')
        {
            double info5;
            cout<<"请输入修改值!"<<endl;
            cin>>info5;
            pCommodity->discount=info5;
            break;
        }
        else
        {
            cout<<"格式有误,请重新输入!";
        }
    }
}
