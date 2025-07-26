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
    const Commodity* findCommodityById(int id)const;//给出两个版本的函数,分别匹配变量是否被修改
    std::vector<Commodity*>::iterator getIterator(Commodity* p);
    int sortType=0; //记录当前排序类型
    void sortCommodities();
    void sortCommoditiesByType(int type);
};
#endif // COMMODITYMANAGE_H
