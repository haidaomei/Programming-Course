#include"header.h"
using namespace std;
extern vector<Student> StudentArray;
void ShowStudent()
{
    for(size_t i=0;i<StudentArray.size();++i)
    {
        cout<<"ѧ��:"<<StudentArray[i].id<<endl;
        cout<<"����:"<<StudentArray[i].name<<endl;
        cout<<"����:"<<StudentArray[i].age<<endl;
        cout<<"�Ա�:"<<StudentArray[i].gender<<endl;
        cout<<"�ɼ�1:"<<StudentArray[i].score[0]<<endl;
        cout<<"�ɼ�2:"<<StudentArray[i].score[1]<<endl;
        cout<<"�ɼ�3:"<<StudentArray[i].score[2]<<endl;
        cout<<"�ɼ�4:"<<StudentArray[i].score[3]<<endl;
        cout<<"�ɼ�5:"<<StudentArray[i].score[4]<<endl;
        cout<<"�ɼ�6:"<<StudentArray[i].score[5]<<endl;
        cout<<"�ɼ�7:"<<StudentArray[i].score[6]<<endl;
    }
}
