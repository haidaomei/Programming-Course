#include"header.h"
using namespace std;
extern vector<Student> StudentArray;
void AddStudent(string id,string name,long age,bool gender,double score1,double score2,double score3,double score4,double score5,double score6,double score7)//这些参数需要用main传进来
{
    Student temp;
    temp.id=id;
    temp.name=name;
    temp.age=age;
    temp.gender=gender;
    temp.score[0]=score1;
    temp.score[1]=score2;
    temp.score[2]=score3;
    temp.score[3]=score4;
    temp.score[4]=score5;
    temp.score[5]=score6;
    temp.score[6]=score7;
    StudentArray.push_back(temp);
}
