#include <iostream>
#include "header.h"
#include <fstream>
#include <algorithm>
using namespace std;
char menu()
{
    cout<<" 0) �˳�ϵͳ\n";
    cout<<" 1) �����������Ʒ\n";
    cout<<" 2) �ӹ������Ƴ���Ʒ\n";
    cout<<" 3) �鿴ָ����Ʒ\n";
    cout<<" 4) �鿴������Ʒ\n";
    cout<<" 5) ����\n";
    cout<<" 6) �޸�\n";
    cout<<"�����빦��ѡ��:";
    char choice;
    cin>>choice;
    return choice;
}
void displayCommodities(CommodityInfo* pCommodities,int num)
{
    int i;
    cout<<"��Ʒ����:"<<num<<endl;
    char temp;
    while(1)
    {
        cout<<"������Ҫ����ķ�ʽ(1:��id,2:����Ʒ����,3:���۸�,4:���ۿ�,5:���ܼ۸�)";
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
            cout<<"��ʽ����,����������!";
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
    cout<<"������Ʒ���(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    if(index!=-1)
    {//�ҵ���Ʒ���ۼ�����
        cout<<"���Ϊ"<<id<<"����Ʒ�Ѿ�����!\n";
        cout<<"���������ӵ���Ʒ����:";
        int number;
        cin>>number;
        pCommodities[index].num+=number;
        return;
    }
    if(num==MAX_COMMODITY_NUM)
    {
        cout<<"û���㹻�ռ���!\n\n";
        return;
    }
    CommodityInfo* pCommodity=&pCommodities[num];//pCommodity��֮ǰfind���ص�ָ��,ָ��Ŀ����Ʒ,�����ǰ�ָ���Ƶ����һλ�ĺ�һλ�������
    pCommodity->id=id;
    setCommodityInfo(pCommodity);
    num++;
    cout<<"��Ʒ��ӳɹ�!\n\n";
}
void removeCommodity(CommodityInfo* pCommodities,int &num)
{
    int id;
    cout<<"������Ʒ���(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    CommodityInfo* pCommodity=pCommodities+index;
    if(index==-1)
    {
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n\n";
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
    cout<<"��Ʒ�Ƴ��ɹ�!\n\n";
}
void viewCommodity(CommodityInfo* pCommodities,int num)
{
    int id;
    cout<<"������Ʒ�ı��(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    if(index==-1)
    {
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n\n";
        return;
    }
    showCommodityInfo(pCommodities+index);
    cout<<endl;
}
void checkOut(CommodityInfo* pCommodities,int num)
{
    double totalPrice=0;
    int totalNum=0;
    cout<<"��Ʒ����:"<<num<<endl;
    cout<<"��Ʒ����\t\t"<<"�۸�\t"<<"����\t"<<"�ۿ�\t"<<"�ܼ�\n";
    for(int i=0;i<num;++i)
    {
        double price=getCommodityPrice(pCommodities+i);
        cout<<" "<<pCommodities[i].name<<"\t";
        cout<<pCommodities[i].price<<"\t"<<pCommodities[i].num<<"\t"<<pCommodities[i].discount<<"\t"<<price<<endl;
        totalPrice+=price;
        totalNum+=pCommodities[i].num;
    }
    cout<<"��������Ʒ�ܼ���:"<<totalNum<<"\n";
    cout<<"�����������ܼ�:"<<totalPrice<<endl;
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
    cout<<"������Ʒ�ı��(id):";
    cin>>id;
    int index=findCommodityById(pCommodities,num,id);
    CommodityInfo* pCommodity=pCommodities+index;
    if(index==-1)
    {
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n\n";
        return;
    }
    char temp;
    while(1)
    {
        cout<<"������Ҫ�޸ĵĲ���(1:���,2:����,3:����,4:����,5:�ۿ�)"<<endl;
        cin>>temp;
        if(temp=='1')
        {
            long info1;
            cout<<"�������޸�ֵ!"<<endl;
            cin>>info1;
            pCommodity->id=info1;
            break;
        }
        else if(temp=='2')
        {
            string info2;
            cout<<"�������޸�ֵ!"<<endl;
            cin>>info2;
            pCommodity->name=info2;
            break;
        }
        else if(temp=='3')
        {
            double info3;
            cout<<"�������޸�ֵ!"<<endl;
            cin>>info3;
            pCommodity->price=info3;
            break;
        }
        else if(temp=='4')
        {
            int info4;
            cout<<"�������޸�ֵ!"<<endl;
            cin>>info4;
            pCommodity->num=info4;
            break;
        }
        else if(temp=='5')
        {
            double info5;
            cout<<"�������޸�ֵ!"<<endl;
            cin>>info5;
            pCommodity->discount=info5;
            break;
        }
        else
        {
            cout<<"��ʽ����,����������!";
        }
    }
}
