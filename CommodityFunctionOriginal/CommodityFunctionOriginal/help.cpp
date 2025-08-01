#include<iostream>
using namespace std;
#include"datatype.h"
void setCommodityInfo(CommodityInfo* pCommodity)
{//读取商品信息
    fflush(stdin); //确保之前残留的回车被清理，商品名称取整行
    cout<<"输入商品名称:";
    getline(cin,pCommodity->name);
    cout<<"输入商品价格:";
    cin>>pCommodity->price;
    cout<<"输入商品数量:";
    cin>>pCommodity->num;
    cout<<"输入商品折扣:";
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
    cout<<"商品编号(id):"<<pCommodity->id<<endl;
    cout<<"商品名称:"<<pCommodity->name<<endl;
    cout<<"商品总价:"<<getCommodityPrice(pCommodity)<<"(价格:"<<pCommodity->price<<",数量:"<<pCommodity->num<<",折扣:"<<pCommodity->discount<<")\n";
}
