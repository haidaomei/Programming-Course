#ifndef NORMALCOMMODITY_H
#define NORMALCOMMODITY_H
#include<string>
#include"commodity.h"
class NormalCommodity:public Commodity
{
public:
    virtual ~NormalCommodity(){}
    NormalCommodity(long id,std::string name,double p=0,int n=0,double d=0);
    NormalCommodity(std::string name,double p=0,int n=0,double d=0);
    void setDiscount(double discount)
    {
        this->discount=discount;
    }
    double getDiscount()const
    {
        return discount;
    }
    virtual double getNetPrice()const;
    virtual Commodity* clone();
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
private:
    double discount;
};
#endif
