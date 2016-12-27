// ConsoleApplication55.cpp: определяет точку входа для консольного приложения.
//
    #include "stdafx.h"
    #include "iostream"
    using namespace std;
   
	enum color
	{
		red, yellow, green, blue, black, white
	};
    
	class Shape 
	{ 
    public:
	      virtual double GetArea() const = 0;
	
	  Shape():
		m_color(white) 
	
    {
		cout<<"Shape constructor"<<endl;
		
	}
	 
	virtual ~Shape()
	
	{
		cout<<"Shape destructor"<<endl;
    }
	
	 inline void SetColor(color col);
	 inline double GetColor() const;

	 private:
	   color m_color;
     };
     class Rectangle:public Shape 
    {
	public:
	Rectangle(double height = 2, double width =1):
	m_height(height),
	m_width(width)
	{
		cout<<"Rectangle constructor"<<endl;
	}
		
	virtual ~Rectangle()
	
	{
		cout<<"Rectangle destructor"<<endl;
	}
	
		double GetHeight() const;
		double GetWidth() const;
		void SetWidth(double width);
	void SetHeight(double height  );
		double GetArea() const  override
		
		{
			return m_width * m_height;
		}

	
	private:
	double m_width;
	double m_height;
	
    };
    
	 class Triangle:public Shape
	 {
    public:
	Triangle (double* sides):
	m_sides(sides)
	{
		}
		void SetSides(double* sides);
	double* GetSides()const  ;
	double GetArea()  const override ;
	
    private:
	double* m_sides;
    };

    class Circle: public Shape 
	{
	
	public:
		Circle(double radius):
		m_radius(radius)
		{
			
		}

		void SetRadius(double radius)  ;
	double GetRadius()const  ;
	double GetArea()  const override   
	
	{
		return 3.14 * m_radius * m_radius;
	}
	
	private:
	double m_radius;
    };
    double Shape::GetColor() const
	
	{
		return m_color;
	} 

	void Shape::SetColor(color col)
	
	{
		m_color = col;
	}

	double Rectangle::GetHeight() const
	
	{
		return m_height;
	}

	double Rectangle::GetWidth() const
	
	{
		return m_width; 
	}

	void Rectangle::SetWidth(double width)
	
	{
		m_width=width;
	}

	void Rectangle::SetHeight(double height  )
	
	{ 
		m_height=height;
	}

	void Triangle::SetSides(double* sides)
	
	{
		m_sides=sides;
	}

	double*Triangle:: GetSides()const
	
	{
		return m_sides;
	}

	double Triangle:: GetArea()  const 
	
	{
		double semiperimeter, product;
	semiperimeter = 0;
	for(int i = 0;i < 3;i++)
		semiperimeter += m_sides[i];
		semiperimeter /= 2;
		product = semiperimeter;
for(int i = 0;i < 3;i++)
	product *= (semiperimeter - m_sides[i]);
		product = sqrt(product);	
		return product;
	}

	void Circle::SetRadius(double radius)
	
	{
		m_radius=radius;
	}

	double Circle::GetRadius()const
	
	{
		return m_radius;
	}

    int _tmain(int argc, _TCHAR* argv[])
   
	{
		

    Shape* pRectangle= new Rectangle(3,2);
    pRectangle->SetColor(black);
    
   
	double squareFig = pRectangle->GetArea();
    cout<<"S Rectangle"<<endl;
    cout<<squareFig<<endl;
    Shape* pCircle = new Circle(9);
 
    squareFig = pCircle->GetArea();
    cout<<"S Circle"<<endl;
    cout<<squareFig<<endl;
    double sides[3];
    for(int i = 0;i < 3;i++)
    sides[i] = i+3;
	Shape* pTriangle = new Triangle(sides);
    
   

   squareFig = pTriangle->GetArea();
    cout<<"S Triangle"<<endl;
    cout<<squareFig<<endl;

    return 0;

    }


