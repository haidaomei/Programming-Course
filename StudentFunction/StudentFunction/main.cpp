#include"header.h"
vector<Student> StudentArray;
using namespace std;
extern vector<Student> StudentArray;
int main()
{
    while(1)
    {
        char temp;
        cout<<"ѧ������ϵͳ"<<endl;
        cout<<"1�����ѧ��"<<endl;
        cout<<"2��ɾ��ѧ��"<<endl;
        cout<<"3���޸���Ϣ"<<endl;
        cout<<"4����ʾ����ѧ��"<<endl;
        cout<<"5������ȫ�꼶�ض���Ŀƽ����"<<endl;
        cout<<"6������ѧ���ܷ�"<<endl;
        cout<<"���������"<<endl;
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
            cout<<"������Ԫ��"<<endl;
            cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k;
            AddStudent(a,b,c,d,e,f,g,h,i,j,k);
        }
        else if(temp=='2')
        {
            string a;
            cout<<"������ѧ��"<<endl;
            cin>>a;
            DeleteStudent(a);
        }
        else if(temp=='3')
        {
            string a;
            cout<<"������ѧ��"<<endl;
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
            cout<<"�������Ŀ"<<endl;
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
            cout<<"������ѧ��"<<endl;
            cin>>a;
            StudentScoreSummary(a);
        }
        else
        {
            cout<<"��ʽ����,����������"<<endl;
        }
    }
    return 0;
}

