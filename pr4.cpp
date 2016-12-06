// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void intersect(double x1, double y1, double R1,double x2,double y2,double  R2)
{double d,r,R;
d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
if(d<=R1+R2) {
	if(R1<R2) {r=R1;R=R2;}
    else {r=R2;R=R1;}
	
	
               if((d<R)&&(r<R-d)) cout<<"don't intersect"<<endl;
			   else cout<<" intersect"<<endl;}
else cout<<"don't intersect"<<endl;
}


int _tmain(int argc, _TCHAR* argv[])
{double x1,y1,R1,x2,y2,R2;
cout<<" input coordinates and radius first circle"<<endl;
cin>>x1>>y1>>R1;
cout<<" input coordinates and radius second circle"<<endl;
cin>>x2>>y2>>R2;
intersect(x1,y1,R1,x2,y2,R2);

return 0;
}
