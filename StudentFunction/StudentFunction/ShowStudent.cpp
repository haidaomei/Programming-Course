#include"header.h"
using namespace std;
extern vector<Student> StudentArray;
void ShowStudent()
{
    for(size_t i=0;i<StudentArray.size();++i)
    {
        cout<<"学号:"<<StudentArray[i].id<<endl;
        cout<<"姓名:"<<StudentArray[i].name<<endl;
        cout<<"年龄:"<<StudentArray[i].age<<endl;
        cout<<"性别:"<<StudentArray[i].gender<<endl;
        cout<<"成绩1:"<<StudentArray[i].score[0]<<endl;
        cout<<"成绩2:"<<StudentArray[i].score[1]<<endl;
        cout<<"成绩3:"<<StudentArray[i].score[2]<<endl;
        cout<<"成绩4:"<<StudentArray[i].score[3]<<endl;
        cout<<"成绩5:"<<StudentArray[i].score[4]<<endl;
        cout<<"成绩6:"<<StudentArray[i].score[5]<<endl;
        cout<<"成绩7:"<<StudentArray[i].score[6]<<endl;
    }
}
