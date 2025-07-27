#ifndef STUDENTSTRUCT_H
#define STUDENTSTRUCT_H

#include <vector>
#include <string>

struct Student
{
    std::string id;
    std::string name;
    long age;
    bool gender;
    std::vector<double> score = {0,0,0,0,0,0,0}; // ��ʼ��7���ɼ�
};

extern std::vector<Student> StudentArray; // ����

#endif
