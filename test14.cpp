#include "stdafx.h"
#include <iostream>
# include <string>
using namespace std;

class HTMLElement
{
public:
             unsigned Width() const;
			 unsigned Height() const;
			 bool Hidden() const;
			 virtual string Render() = 0;
			 bool getFlag() const
			 {
				 return m_flag;
			 }
			 private:
	
	mutable bool m_flag;
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
	return true;
}
template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem))
{
for(int i = 0;i < length ;i++)
if(p(arr[i])) return true; 
return false;
}
 template<typename T>
bool func(const T& elem)
 {
	 return elem -> getFlag() ;
 }
bool HTMLElement::Hidden() const
 {
	 static int count;
 count++;
 
 if (count % 2 ==0)
	 m_flag = true;
 else m_flag = false;

 return m_flag;
}

int _tmain(int argc, _TCHAR* argv[])
{
	 HTMLElement* pArray[3];
	 pArray [0] = new HTMLButtonElement();
	 pArray [1] = new HTMLImageElement();
	 pArray [2] = new HTMLTextAreaElement();
	for(int i = 0;i < 3 ;i++)
		{
	pArray[i]->Hidden();
	}
 cout<<any_of<HTMLElement*>(pArray, 3, func)<<endl;
 
	 cout<<all_of<HTMLElement*>(pArray, 3, func)<<endl;



	 
	  return 0;
}

