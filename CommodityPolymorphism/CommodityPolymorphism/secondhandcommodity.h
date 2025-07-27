#ifndef SECONDHANDCOMMODITY_H
#define SECONDHANDCOMMODITY_H
#include<string>
#include"Commodity.h"
class SecondhandCommodity:public Commodity
{
public:
    virtual~SecondhandCommodity()
    {
    }
    SecondhandCommodity(long id,std::string name,double p=0,int n=0,double d=1.0,double l=0);//�ֱ���id��Ʒ�����۸��������ۿۡ��̶�
    SecondhandCommodity(std::string name,double p=0,int n=0,double d=1.0,double l=0);//ʡ��id
    void setDiscount(double discount)
    {
        this->discount=discount;
    }
    void setLevel(double level)
    {
        this->level=level;
    }
    double getDiscount()const
    {
        return discount;
    }
    double getLevel()const
    {
        return level;
    }
    virtual double getNetPrice()const;
    virtual Commodity* clone();
    virtual void output()const;
    virtual int getType()const;
    virtual std::string getInfo()const;
    virtual void changeinformation()override;
private:
    double discount;
    double level;
};

#endif // SECONDHANDCOMMODITY_H



