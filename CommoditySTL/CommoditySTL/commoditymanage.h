#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include<string>
#include"commodity.h"
#include<vector>
class CommodityManage
{
public:
    CommodityManage()=default;
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
    Commodity* findCommodityByName(std::string name);
private:
    std::vector<Commodity*> pCommodities;
    Commodity* findCommodityById(int id);
    const Commodity* findCommodityById(int id)const;//���������汾�ĺ���,�ֱ�ƥ������Ƿ��޸�
    std::vector<Commodity*>::iterator getIterator(Commodity* p);
    int sortType=0; //��¼��ǰ��������
    void sortCommodities();
    void sortCommoditiesByType(int type);
};
#endif // COMMODITYMANAGE_H
