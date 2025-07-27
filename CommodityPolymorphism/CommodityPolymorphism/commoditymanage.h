#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include<string>
#include"commodity.h"
class CommodityManage
{
public:
    CommodityManage();
    CommodityManage(int s);
    ~CommodityManage();
    CommodityManage(const CommodityManage &c)=delete;
    CommodityManage &operator=(const CommodityManage &c)=delete;
    void addCommodity(Commodity* p);
    void removeCommodity(int id);
    void viewCommodity(int id)const;
    void viewAllCommodities()const;
    void checkOut()const;
    void readData(std::string filename);
    void saveData(std::string filename);
    void changingInformation(int id);
private:
    Commodity **pCommodities; //ָ��̬��������Ʒָ������
    int maxSize; //��ǰ����Ŀռ�����
    int size;
    Commodity* findCommodityById(int id)const;
    void reAllocMemory();
};
#endif // COMMODITYMANAGE_H
