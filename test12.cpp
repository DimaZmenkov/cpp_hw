
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
		string str ( "<img src=../../smiley.gif height=42 width=4> ");
	return str;
	}
};
class HTMLTextAreaElement:public  HTMLElement
{
	public:
	const string& Content() const;
	string Render() override
	{
	string str( "<textarea>content-of-the-text-area</textarea>");
return str;
	}
};
string HTMLButtonElement::Render()
{string str ( "<button>title-of-the-button</button> ");
	return str;
}

int _tmain(int argc, _TCHAR* argv[])

	{
		HTMLElement* pButton = new HTMLButtonElement();
	HTMLElement* pImage  = new HTMLImageElement();
    HTMLElement* pTextArea = new HTMLTextAreaElement();
	cout<<pButton -> Render()<<endl;
	cout<< pImage -> Render()<<endl;
	cout<< pTextArea -> Render()<<endl;
return 0;
}