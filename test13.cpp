#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
class HTMLElement
{
public:
             unsigned Width() const;
			 unsigned Height() const;
			 bool Hidden() const;
			 virtual string Render() = 0;
			  virtual HTMLElement* Duplicate() = 0;
};
class HTMLButtonElement: public  HTMLElement
{ 
	public:
	const string& Title() const;
	string Render() override;
	 HTMLElement* Duplicate() override
	 {
	 return new HTMLButtonElement();
	 }
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
	HTMLElement* Duplicate() override
	{
     return new HTMLImageElement();
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
	HTMLElement* Duplicate() //override
	{
     return new HTMLTextAreaElement();
	}
};
string HTMLButtonElement::Render()
{string str = "<button>title-of-the-button</button> ";
	return str;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//#3
	 HTMLElement* pArray [3];
	pArray [0] = new HTMLButtonElement();
	 pArray [1] = new HTMLImageElement();
	 pArray [2] = new HTMLTextAreaElement();
	  HTMLElement* pArray1 [3];
	  for(int i = 0;i < 3;i++)
		  {
			  pArray1 [i] =  pArray[i] ->  Duplicate();
			  cout<<pArray1 [i] -> Render()<<endl;
	      }
//#4



	 
	  return 0;
}