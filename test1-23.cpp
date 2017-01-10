#include "stdafx.h"
#include <iostream>
#include <cassert>

using namespace std;
template<typename T>

class ASTBinaryNode
{
	public:
virtual  ~ASTBinaryNode()
{
}
		ASTBinaryNode(const T& left, const T& right):
		m_left(left),
		m_right(right)
		{
		}
virtual T evaluate() const = 0;
protected:
T m_left;
T m_right;
};


template<typename T>
class ASTBinaryNodePlus: public ASTBinaryNode<T>
{public:
	
	ASTBinaryNodePlus(const T& left, const T& right):
	ASTBinaryNode( left, right)
	{
	}
	T evaluate() const override
	{
      return m_left + m_right;
	}
};

template<typename T>
class ASTBinaryNodeMinus: public ASTBinaryNode<T>
{public:
	
	ASTBinaryNodeMinus(const T& left, const T& right):
		ASTBinaryNode( left, right)
	{
	}
	T evaluate() const override
	{
      return m_left - m_right;
	}
};
template<typename T>
class ASTBinaryNodeDivide: public ASTBinaryNode<T>
{public:
	
	ASTBinaryNodeDivide(const T& left, const T& right):
		ASTBinaryNode( left, right)
	{
	}
		T evaluate() const override
	{
      return m_left / m_right;
	}
};
template<typename T>
class ASTBinaryNodeMultiply: public ASTBinaryNode<T>
{public:
	
	ASTBinaryNodeMultiply(const T& left, const T& right):
		ASTBinaryNode( left, right)
	{
	}
	T evaluate() const override
	{
      return m_left * m_right;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	
		ASTBinaryNode<int> *pASTBinaryNodeMinus = new ASTBinaryNodeMinus<int>(5,1);
		assert(pASTBinaryNodeMinus ->evaluate() == 4);
		ASTBinaryNode<int> *pASTBinaryNodeMultiply = new ASTBinaryNodeDivide<int>(4,1);
		assert(pASTBinaryNodeMultiply ->evaluate() == 4);
		ASTBinaryNode<int> *pASTBinaryNodeDivide = new ASTBinaryNodeMultiply<int>(3,1);
		assert(pASTBinaryNodeDivide ->evaluate() == 3);
		ASTBinaryNode<int> *pASTBinaryNodePlus = new ASTBinaryNodePlus<int>(1,1);
		assert(pASTBinaryNodePlus ->evaluate() == 2);
		return 0;
}
