// ConsoleApplication101.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
template<typename T>
class BinaryTree
{
public:
BinaryTree(const T& value):
m_flagRight(false), m_flagLeft(false)
{
	 m_value = value;
}
void AddLeft(BinaryTree<T>* left)
{
m_left = left;
m_flagLeft = true;
}
void AddRight(BinaryTree<T>* right)
{

	m_right =  right;
m_flagRight = true;
}
BinaryTree<T>  Serialize()
{
return *this;
}
friend ostream& operator<<(ostream& stream, const BinaryTree<T> & rhs)
   {
	  

	 
			  stream << rhs.m_value;
		  
	  if(rhs.m_flagLeft)
	 
	  { 
		  stream << "(";cout<<*rhs.m_left;stream <<",";
	  }

		 if(rhs.m_flagRight) 
		  
		  {
			 cout<<*rhs.m_right; stream <<")";
		  }
	  
	   
			 return stream ;
   }
private:
T m_value;	
BinaryTree * m_left;
BinaryTree * m_right;

bool m_flagRight;
bool m_flagLeft ;
//bool fm;
};


int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree<string> root("+");
    BinaryTree<string> left1("1");
    BinaryTree<string> right2("2");
    root.AddLeft(&left1);
    root.AddRight(&right2);
    cout << root.Serialize() << endl;
	
	
	return 0;
}

