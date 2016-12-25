
#include "stdafx.h" 
#include "iostream"
#include "cstring"

using namespace std;

bool test(char ch)

{
	return(ch >= 'a')&&(ch <= 'z')||(ch >= 'A')&&(ch <= 'Z');
}

int _tmain(int argc, _TCHAR* argv[])
{
	int pos=0, maxSize = 30, strCount = 0;
char *str = new char[maxSize];
cout<<"Input  string"<<endl;
cin.getline(str, maxSize);
	int  length = strlen(str);
   for(int i = 0;i < length;i++)
	if (str[i] == '.')  length = i;
	
	pos = length;
	int t=0;
	bool flag = 0;
		if(test(str[0])) 
	{
		flag=true;pos--;
		}
		for(int i = 0;i < length ;i++)
		{if(flag)
		     {
			    flag = false;continue;
		     }
		if((i > 0)&&(!test(str[i-1])) && (test(str[i]))) 
		    {
			  continue;
		    }
		 
			str[strCount] = str[i];
		strCount++;
		}

cout<<"new string"<<endl;
for(int i = 0;i < strCount;i++)
cout<<str[i];
cout<<endl;
delete[] str;

}


