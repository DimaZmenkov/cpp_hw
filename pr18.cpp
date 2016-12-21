

// ConsoleApplication34.cpp: определяет точку входа для консольного приложения.
//



#include "stdafx.h"
#include "iostream"

using namespace std;

	struct Professor
	{
		char name[20];
            unsigned short age;
            unsigned int salary;
	};
	
	struct student
{
	char name[20];
            unsigned short age;
            float gpa;
Professor* supervisor;
};
int _tmain(int argc, _TCHAR* argv[])

{
	int sizeGroup, quantityProffessors, count;
float sum;
cout<<"Input quantity of students"<<endl;
cin>>sizeGroup;
student* group = new student[sizeGroup];
for(int i = 0;i < sizeGroup;i++)
	{cout<<" Input name"<<endl;
	cin>>group[i].name;
cout<<" Input age"<<endl;
cin>>group[i].age;
cout<<" Input gpa"<<endl;
cin>>group[i].gpa;
    }	
sum=0;
for(int i = 0;i < sizeGroup;i++)
sum+=group[i].gpa;
sum /= sizeGroup;
cout<<"the average group score"<<endl;
cout<<sum<<endl;
student stMax,stMin=group[0];
stMax=stMin;
for(int i = 1;i < sizeGroup;i++)
	{if(stMax.gpa < group[i].gpa) stMax = group[i];
	if(stMin.gpa > group[i].gpa) stMin = group[i];
    }
cout<<"Student with max average group score"<<endl;
cout<<stMax.name<<endl;
cout<<"Student with min average group score"<<endl;
cout<<stMin.name<<endl;
cout<<"Input quantity of proffesors"<<endl;
cin>>quantityProffessors;
Professor *pr = new Professor[quantityProffessors];
for(int i = 0;i < quantityProffessors;i++)
	{cout<<" Input name"<<endl;
	cin>>pr[i].name;
cout<<" Input age"<<endl;
cin>>pr[i].age;
cout<<" Input salary"<<endl;
cin>>pr[i].salary;
}	
bool *flagSupervisors = new bool[quantityProffessors];
for(int j = 0;j < quantityProffessors;j++)
	flagSupervisors[j] = false;


for(int i = 0;i < sizeGroup;i++)
{
	count = i % quantityProffessors;
	flagSupervisors[count]=true;
group[i].supervisor = pr + count;
if(group[i].supervisor -> age > 50) cout<<group[i].name<<endl;
}
cin>>count;

for(int i = 0;i < sizeGroup;i++)
	delete group[i].supervisor;
delete[] group;
for(int i = 0;i < quantityProffessors;i++)
	if(!flagSupervisors[i])
	delete (pr+i);
	return 0;
}


