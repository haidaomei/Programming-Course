#include"header.h"
vector<Student> StudentArray;
using namespace std;
extern vector<Student> StudentArray;
int main()
{
    while(1)
    {
        char temp;
        cout<<"学生管理系统"<<endl;
        cout<<"1、添加学生"<<endl;
        cout<<"2、删除学生"<<endl;
        cout<<"3、修改信息"<<endl;
        cout<<"4、显示所有学生"<<endl;
        cout<<"5、计算全年级特定科目平均分"<<endl;
        cout<<"6、计算学生总分"<<endl;
        cout<<"请输入操作"<<endl;
        cin>>temp;
        if(temp=='1')
        {
            string a;
            string b;
            long c;
            bool d;
            double e;
            double f;
            double g;
            double h;
            double i;
            double j;
            double k;
            cout<<"请输入元素"<<endl;
            cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k;
            AddStudent(a,b,c,d,e,f,g,h,i,j,k);
        }
        else if(temp=='2')
        {
            string a;
            cout<<"请输入学号"<<endl;
            cin>>a;
            DeleteStudent(a);
        }
        else if(temp=='3')
        {
            string a;
            cout<<"请输入学号"<<endl;
            cin>>a;
            ChangeInformation(a);
        }
        else if(temp=='4')
        {
            ShowStudent();
        }
        else if(temp=='5')
        {
            char temp2;
            cout<<"请输入科目"<<endl;
            cin>>temp2;
            if(temp2=='1')
            {
                double summary=0;
                for(size_t i=0;i<StudentArray.size();++i)
                {
                    summary=summary+StudentArray[i].score[0];
                }
                cout<<summary;
            }
            else if(temp2=='2')
            {
                double summary=0;
                for(size_t i=0;i<StudentArray.size();++i)
                {
                    summary=summary+StudentArray[i].score[1];
                }
                cout<<summary;
            }
            else if(temp2=='3')
            {
                double summary=0;
                for(size_t i=0;i<StudentArray.size();++i)
                {
                    summary=summary+StudentArray[i].score[2];
                }
                cout<<summary;
            }
            else if(temp2=='4')
            {
                double summary=0;
                for(size_t i=0;i<StudentArray.size();++i)
                {
                    summary=summary+StudentArray[i].score[3];
                }
                cout<<summary;
            }
            else if(temp2=='5')
            {
                double summary=0;
                for(size_t i=0;i<StudentArray.size();++i)
                {
                    summary=summary+StudentArray[i].score[4];
                }
                cout<<summary;
            }
            else if(temp2=='6')
            {
                double summary=0;
                for(size_t i=0;i<StudentArray.size();++i)
                {
                    summary=summary+StudentArray[i].score[5];
                }
                cout<<summary;
            }
            else if(temp2=='7')
            {
                double summary=0;
                for(size_t i=0;i<StudentArray.size();++i)
                {
                    summary=summary+StudentArray[i].score[6];
                }
                cout<<summary;
            }
        }
        else if(temp=='6')
        {
            string a;
            cout<<"请输入学号"<<endl;
            cin>>a;
            StudentScoreSummary(a);
        }
        else
        {
            cout<<"格式错误,请重新输入"<<endl;
        }
    }
    return 0;
}

