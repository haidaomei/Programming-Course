#ifndef SPECIALOFFERCOMMODITY_H
#define SPECIALOFFERCOMMODITY_H
#include<string>
#include"Commodity.h"
class SpecialOfferCommodity:public Commodity
{
public:
    virtual~SpecialOfferCommodity()
    {
    }
    SpecialOfferCommodity(long id,std::string name,double p=0,int n=0,double s=0);//分别是id、品名、价格、数量、折扣、程度
    SpecialOfferCommodity(std::string name,double p=0,int n=0,double s=0);//省略id
    void setSpecialOffer(double SpecialOffer)
    {
        this->SpecialOffer=SpecialOffer;
    }
    double getSpecialOffer()const
    {
        return SpecialOffer;
    }
    virtual double getNetPrice()const;
    virtual Commodity* clone();
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
    virtual void changeinformation()override;
private:
    double SpecialOffer;
};


#endif // SPECIALOFFERCOMMODITY_H
