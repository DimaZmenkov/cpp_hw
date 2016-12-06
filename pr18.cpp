// ConsoleApplication34.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

	struct Professor
	{char name[20];
            unsigned short age;
            unsigned int salary;
	};
	struct student
{char name[20];
            unsigned short age;
            float gpa;
Professor* supervisor;
};
int _tmain(int argc, _TCHAR* argv[])
{int n,m,j;
float s;
cout<<"Input quantity of students"<<endl;
cin>>n;
student* group= new student[n];
for(int i=0;i<n;i++)
	{cout<<" Input name"<<endl;
	cin>>group[i].name;
cout<<" Input age"<<endl;
cin>>group[i].age;
cout<<" Input gpa"<<endl;
cin>>group[i].gpa;
}	
s=0;
for(int i=0;i<n;i++)
s+=group[i].gpa;
s/=n;
cout<<"the average group score"<<endl;
cout<<s<<endl;
student stmax,stmin=group[0];
stmax=stmin;
for(int i=1;i<n;i++)
	{if(stmax.gpa<group[i].gpa) stmax=group[i];
	if(stmin.gpa>group[i].gpa) stmin=group[i];
    }
cout<<"Student with max average group score"<<endl;
cout<<stmax.name<<endl;
cout<<"Student with min average group score"<<endl;
cout<<stmin.name<<endl;
cout<<"Input quantity of proffesors"<<endl;
cin>>m;
Professor *pr=new Professor[m];
for(int i=0;i<m;i++)
	{cout<<" Input name"<<endl;
	cin>>pr[i].name;
cout<<" Input age"<<endl;
cin>>pr[i].age;
cout<<" Input salary"<<endl;
cin>>pr[i].salary;
}	
for(int i=0;i<n;i++)
{j=i%m;
group[i].supervisor=pr+j;
if(group[i].supervisor->age>50) cout<<group[i].name<<endl;
}
cin>>j;
return 0;
}

