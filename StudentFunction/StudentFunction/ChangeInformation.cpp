#include"header.h"
using namespace std;
extern vector<Student> StudentArray;
void ChangeInformation(string id)
{
    bool found = false;
    for(size_t i=0;i<StudentArray.size();++i)
    {
        if(StudentArray[i].id==id)
        {
            found = true;
            while(1)
            {
                string temp;
                cout<<"���������(1��11�ֱ��Ӧ��ͬ����)"<<endl;
                cin>>temp;
                if(temp=="1")
                {
                    string information1;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information1;
                    StudentArray[i].id=information1;
                    break;
                }
                else if(temp=="2")
                {
                    string information2;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information2;
                    StudentArray[i].name=information2;
                    break;
                }
                else if(temp=="3")
                {
                    long information3;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information3;
                    StudentArray[i].age=information3;
                    break;
                }
                else if(temp=="4")
                {
                    bool information4;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information4;
                    StudentArray[i].gender=information4;
                    break;
                }
                else if(temp=="5")
                {
                    double information5;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information5;
                    StudentArray[i].score[0]=information5;
                    break;
                }
                else if(temp=="6")
                {
                    double information6;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information6;
                    StudentArray[i].score[1]=information6;
                    break;
                }
                else if(temp=="7")
                {
                    double information7;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information7;
                    StudentArray[i].score[2]=information7;
                    break;
                }
                else if(temp=="8")
                {
                    double information8;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information8;
                    StudentArray[i].score[3]=information8;
                    break;
                }
                else if(temp=="9")
                {
                    double information9;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information9;
                    StudentArray[i].score[4]=information9;
                    break;
                }
                else if(temp=="10")
                {
                    double information10;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information10;
                    StudentArray[i].score[5]=information10;
                    break;
                }
                else if(temp=="11")
                {
                    double information11;
                    cout<<"�������޸�ֵ"<<endl;
                    cin>>information11;
                    StudentArray[i].score[6]=information11;
                    break;
                }
                else
                {
                    cout<<"��ʽ����,����������"<<endl;
                }
            }
        }
    }
    if(!found)
    {
        cout<<"��Ŀ��ѧ��"<<endl;
    }
}

