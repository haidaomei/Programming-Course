#include<iostream>
using namespace std;
#include"datatype.h"
void setCommodityInfo(CommodityInfo* pCommodity)
{//��ȡ��Ʒ��Ϣ
    fflush(stdin); //ȷ��֮ǰ�����Ļس���������Ʒ����ȡ����
    cout<<"������Ʒ����:";
    getline(cin,pCommodity->name);
    cout<<"������Ʒ�۸�:";
    cin>>pCommodity->price;
    cout<<"������Ʒ����:";
    cin>>pCommodity->num;
    cout<<"������Ʒ�ۿ�:";
    cin>>pCommodity->discount;
}
int findCommodityById(CommodityInfo* pCommodities,int num,long id)
{
    int index=0;
    for(;index<num;index++)
    {
        if(pCommodities[index].id==id)
        {
            return index;
        }
    }
    return -1;
}
double getCommodityPrice(CommodityInfo* pCommodity)
{
    return pCommodity->price*pCommodity->num*pCommodity->discount;
}
void showCommodityInfo(CommodityInfo* pCommodity)
{
    cout<<"��Ʒ���(id):"<<pCommodity->id<<endl;
    cout<<"��Ʒ����:"<<pCommodity->name<<endl;
    cout<<"��Ʒ�ܼ�:"<<getCommodityPrice(pCommodity)<<"(�۸�:"<<pCommodity->price<<",����:"<<pCommodity->num<<",�ۿ�:"<<pCommodity->discount<<")\n";
}
