#include"header.h"
using namespace std;
extern vector<Student> StudentArray;
void StudentScoreSummary(string id)
{
    bool found = false;
    for(size_t i=0;i<StudentArray.size();++i)
    {
        if(StudentArray[i].id==id)
        {
            found = true;
            cout<<"总分"<<StudentArray[i].score[0]+StudentArray[i].score[1]+StudentArray[i].score[2]+StudentArray[i].score[3]+StudentArray[i].score[4]+StudentArray[i].score[5]+StudentArray[i].score[6];
            break;
        }
    }
    if(!found)
    {
        cout<<"无目标学生"<<endl;
    }
}
