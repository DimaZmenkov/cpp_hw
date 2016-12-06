// ConsoleApplication42.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;
enum color {red,yellow,green,blue,black,white};
struct Shape { 
	color itscolor;
};
struct Rectangle:Shape {
	double itsWidth;
	double itsHeight;
	double GetArea() const {return itsWidth*itsHeight;}
};
struct Triangle:Shape {
	double GetArea() const
	{double s, p=0;
	for(int i=0;i<3;i++)
		p+=Sides[i];
		p/=2;
		s=p;
for(int i=0;i<3;i++)
	s*=(p-Sides[i]);
		s=sqrt(s);	
		return s;}
	double Sides[3];
};
struct Circle:Shape {
	
	double GetArea() const
	{return 3.14*Radius*Radius;}
	double Radius;

};
	
int _tmain(int argc, _TCHAR* argv[])
{Shape s;
s.itscolor=red;
Rectangle r;
r.itscolor=green;
r.itsWidth=3.5;
r.itsHeight=4.5;
double sf=r.GetArea();
cout<<"S Rectangle"<<endl;
cout<<sf<<endl;
Circle c;
c.itscolor=black;
c.Radius=2;
sf=c.GetArea();
cout<<"S Circle"<<endl;
cout<<sf<<endl;
Triangle t;
t.itscolor=yellow;
for(int i=0;i<3;i++)
t.Sides[i]=i+3;
	sf=t.GetArea();
cout<<"S Triangle"<<endl;
cout<<sf<<endl;

return 0;

}

