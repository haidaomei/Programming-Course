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
                cout<<"请输入操作(1到11分别对应不同数据)"<<endl;
                cin>>temp;
                if(temp=="1")
                {
                    string information1;
                    cout<<"请输入修改值"<<endl;
                    cin>>information1;
                    StudentArray[i].id=information1;
                    break;
                }
                else if(temp=="2")
                {
                    string information2;
                    cout<<"请输入修改值"<<endl;
                    cin>>information2;
                    StudentArray[i].name=information2;
                    break;
                }
                else if(temp=="3")
                {
                    long information3;
                    cout<<"请输入修改值"<<endl;
                    cin>>information3;
                    StudentArray[i].age=information3;
                    break;
                }
                else if(temp=="4")
                {
                    bool information4;
                    cout<<"请输入修改值"<<endl;
                    cin>>information4;
                    StudentArray[i].gender=information4;
                    break;
                }
                else if(temp=="5")
                {
                    double information5;
                    cout<<"请输入修改值"<<endl;
                    cin>>information5;
                    StudentArray[i].score[0]=information5;
                    break;
                }
                else if(temp=="6")
                {
                    double information6;
                    cout<<"请输入修改值"<<endl;
                    cin>>information6;
                    StudentArray[i].score[1]=information6;
                    break;
                }
                else if(temp=="7")
                {
                    double information7;
                    cout<<"请输入修改值"<<endl;
                    cin>>information7;
                    StudentArray[i].score[2]=information7;
                    break;
                }
                else if(temp=="8")
                {
                    double information8;
                    cout<<"请输入修改值"<<endl;
                    cin>>information8;
                    StudentArray[i].score[3]=information8;
                    break;
                }
                else if(temp=="9")
                {
                    double information9;
                    cout<<"请输入修改值"<<endl;
                    cin>>information9;
                    StudentArray[i].score[4]=information9;
                    break;
                }
                else if(temp=="10")
                {
                    double information10;
                    cout<<"请输入修改值"<<endl;
                    cin>>information10;
                    StudentArray[i].score[5]=information10;
                    break;
                }
                else if(temp=="11")
                {
                    double information11;
                    cout<<"请输入修改值"<<endl;
                    cin>>information11;
                    StudentArray[i].score[6]=information11;
                    break;
                }
                else
                {
                    cout<<"格式错误,请重新输入"<<endl;
                }
            }
        }
    }
    if(!found)
    {
        cout<<"无目标学生"<<endl;
    }
}

