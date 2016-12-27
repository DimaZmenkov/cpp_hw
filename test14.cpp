#include "stdafx.h"
#include <iostream>

using namespace std;

class HTMLElement
{
public:
             unsigned Width() const;
			 unsigned Height() const;
			 bool Hidden() const;
			 virtual string Render() = 0;
};
class HTMLButtonElement: public  HTMLElement
{ 
	public:
	const string& Title() const;
	string Render() override;

};
class HTMLImageElement:public  HTMLElement
{
	public:
	const string& Url() const;
	string Render() override
	{
		string str = "<img src=../../smiley.gif height=42 width=4> ";
	return str;
	}
};
class HTMLTextAreaElement:public  HTMLElement
{
	public:
	const string& Content() const;
	string Render() override
	{
	string str = "<textarea>content-of-the-text-area</textarea>";
return str;
	}
};
string HTMLButtonElement::Render()
{string str = "<button>title-of-the-button</button> ";
	return str;
}


template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T& elem))
{
	for(int i = 0;i < length ;i++)
if(!p(arr[i])) return false; 
	return true
}
template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem))
{
for(int i = 0;i < length ;i++)
if(p(arr[i])) return true; 
return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
//#4



	 
	  return 0;
}

