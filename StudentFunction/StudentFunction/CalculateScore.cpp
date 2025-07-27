#include"header.h"
using namespace std;
extern vector<Student> StudentArray;
void CalculateScore()
{
    while(1)
    {
        char temp;
        cout<<"请输入查看类型"<<endl;
        cin>>temp;
        if(temp=='1')
        {
            double summary=0;
            for(unsigned int i=0;i<StudentArray.size();++i)
            {
                summary=summary+StudentArray[i].score[0];
            }
            cout<<"总分"<<summary<<endl;
            break;
        }
        else if(temp=='2')
        {
            double summary=0;
            for(unsigned int i=0;i<StudentArray.size();++i)
            {
                summary=summary+StudentArray[i].score[1];
            }
            cout<<"总分"<<summary<<endl;
            break;
        }
        else if(temp=='3')
        {
            double summary=0;
            for(unsigned int i=0;i<StudentArray.size();++i)
            {
                summary=summary+StudentArray[i].score[2];
            }
            cout<<"总分"<<summary<<endl;
            break;
        }
        else if(temp=='4')
        {
            double summary=0;
            for(unsigned int i=0;i<StudentArray.size();++i)
            {
                summary=summary+StudentArray[i].score[3];
            }
            cout<<"总分"<<summary<<endl;
            break;
        }
        else if(temp=='5')
        {
            double summary=0;
            for(unsigned int i=0;i<StudentArray.size();++i)
            {
                summary=summary+StudentArray[i].score[4];
            }
            cout<<"总分"<<summary<<endl;
            break;
        }
        else if(temp=='6')
        {
            double summary=0;
            for(unsigned int i=0;i<StudentArray.size();++i)
            {
                summary=summary+StudentArray[i].score[5];
            }
            cout<<"总分"<<summary<<endl;
            break;
        }
        else if(temp=='7')
        {
            double summary=0;
            for(unsigned int i=0;i<StudentArray.size();++i)
            {
                summary=summary+StudentArray[i].score[6];
            }
            cout<<"总分"<<summary<<endl;
            break;
        }
        else
        {
            cout<<"格式错误,请重新输入"<<endl;
        }
    }
}
