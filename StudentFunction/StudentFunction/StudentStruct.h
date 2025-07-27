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
    std::vector<double> score = {0,0,0,0,0,0,0}; // 初始化7个成绩
};

extern std::vector<Student> StudentArray; // 声明

#endif
