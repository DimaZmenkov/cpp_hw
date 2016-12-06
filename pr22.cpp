// ConsoleApplication49.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication48.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include "iostream"
#include "cstring"
using namespace std;
class String { 
public:
	String ( char*  str);
	~String();
	inline int GetLength() const;
	String& operator=(const String& rhs);
	char* GetString() const; 
private:
char*itsString;
int itsLength;
};
String::String ( char *  str)
	{itsString=str;
	itsLength=strlen(str);
	}
String::~String()
{cout<<"String destructor"<<endl;}
String& String::operator=(const String& rhs)
{if(this==&rhs) return *this;
itsString=rhs.itsString;
itsLength=rhs.itsLength;
return *this;
};
char*String::GetString() const
{return itsString;}
	int String::GetLength() const
 {return itsLength;}
int _tmain(int argc, _TCHAR* argv[])
{int n=40;
	char s[]="545";
	char s1[]="545";
	cout<<"Input first string"<<endl;
	cin.getline(s,n);
String a(s);
cout<<"Input second string"<<endl;
	cin.getline(s1,n);
String b(s1);
b=a;
cout<<"a="<<endl;
char*sa=a.GetString();
char*sb=b.GetString();
int la=a.GetLength();
int lb=b.GetLength();
for(int i=0;i<la;i++)
	cout<<sa[i];
cout<<endl;
cout<<"b="<<endl;
	for(int i=0;i<lb;i++)
	cout<<sb[i];
	cout<<endl;
cout<<"&a="<<&a<<endl;
	cout<<"&b="<<&b<<endl;
return 0;
}
