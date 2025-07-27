#include"header.h"
using namespace std;
extern vector<Student> StudentArray;
void DeleteStudent(string id)
{
    bool found = false;
    for(unsigned int i=0;i<StudentArray.size();++i)
    {
        if(StudentArray[i].id==id)
        {
            StudentArray.erase(StudentArray.begin()+i);
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"无目标学生"<<endl;
    }
}
