// Win32Project2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"iostream"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{int i,k,f1,f7;


for(i=17;i<972;i++)
{k=i;f1=0;f7=0;
	     while(k>0)
	{if(k%10==1) f1=1;
	if(k%10==7) f7=1;
	if((f1==1)&&(f7==1)) {cout<<i<<endl;break;}
	k/=10;
	}
}

return 0;
}

