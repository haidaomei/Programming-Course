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
    SpecialOfferCommodity(long id,std::string name,double p=0,int n=0,double s=0);//�ֱ���id��Ʒ�����۸��������ۿۡ��̶�
    SpecialOfferCommodity(std::string name,double p=0,int n=0,double s=0);//ʡ��id
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
