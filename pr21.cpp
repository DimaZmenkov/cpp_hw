
#include "stdafx.h"
#include "iostream"
using namespace std;
enum color {red,yellow,green,blue,black,white};
class Shape { 
public:
	Shape()
	{cout<<"Shape constructor"<<endl;itsColor=white;}
	~Shape()
	{cout<<"Shape destructor"<<endl;}
	inline void SetColor(color Col);
	 inline double GetColor() const;
private:
	 color itsColor;
};
class Rectangle:public Shape {
	public:
	Rectangle()
	{cout<<"Rectangle constructor"<<endl;}
		~Rectangle()
	{cout<<"Rectangle destructor"<<endl;}
	double GetHeight() const;
		double GetWidth() const;
		void SetWidth(double Width);
	void SetHeight(double Height  );
		double GetArea() const {return itsWidth*itsHeight;}
	private:
	double itsWidth;
	double itsHeight;
	
};
class Triangle:public Shape {
public:
	void SetSides(double* Sides);
	double* GetSides()const;
	double GetArea() const;
	
private:
	double *itsSides;
};

class Circle:Shape {
	public:
	void SetRadius(double Radius);
	double GetRadius()const;
	double GetArea() const
	{return 3.14*itsRadius*itsRadius;}
	private:
	double itsRadius;
};
double Shape::GetColor() const
	{return itsColor;} 
	void Shape::SetColor(color Col)
	{itsColor=Col;}
	double Rectangle::GetHeight() const
	{return itsHeight; }
	double Rectangle::GetWidth() const
	{return itsWidth; }
	void Rectangle::SetWidth(double Width)
	{itsWidth=Width;}
	void Rectangle::SetHeight(double Height  )
	{ itsHeight=Height;}
	void Triangle::SetSides(double* Sides)
	{itsSides=Sides;}
	double*Triangle:: GetSides()const
	{return itsSides;}
	double Triangle:: GetArea() const
	{double p,s;
	p=0;
	for(int i=0;i<3;i++)
		p+=itsSides[i];
		p/=2;
		s=p;
for(int i=0;i<3;i++)
	s*=(p-itsSides[i]);
		s=sqrt(s);	
		return s;}
	void Circle::SetRadius(double Radius)
	{itsRadius=Radius;}
	double Circle::GetRadius()const
	{return itsRadius;}
int _tmain(int argc, _TCHAR* argv[])
{Shape s;

Rectangle r;
r.SetColor(black);
r.SetWidth(2);
r.SetHeight(2);
double sf=r.GetArea();
cout<<"S Rectangle"<<endl;
cout<<sf<<endl;
Circle c;
c.SetRadius(3);
sf=c.GetArea();
cout<<"S Circle"<<endl;
cout<<sf<<endl;
Triangle t;
double Sides[3];
for(int i=0;i<3;i++)
Sides[i]=i+3;
t.SetSides(Sides);	

sf=t.GetArea();
cout<<"S Triangle"<<endl;
cout<<sf<<endl;

return 0;

}