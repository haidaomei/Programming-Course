#ifndef DATATYPE_H
#define DATATYPE_H
#include <string>
struct CommodityInfo
{
    long id;
    std::string name;
    double price;
    int num;
    double discount;
    double money=price*discount*num;
};
const int MAX_COMMODITY_NUM=100;
#endif // DATATYPE_H
