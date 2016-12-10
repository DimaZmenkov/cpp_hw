
//#include "cassert"
#include "stdafx.h"
#include "iostream"

using namespace std;
    int*  map ( int (*pf_map) (int ), int* aArray, int size)
	{for(int i = 0;i < size;i++)
	      aArray[i] = pf_map(aArray[i]) ;
	return aArray;
	}
	  
	int* filter ( bool (*pf_filter) (int ), int *aArray, int size ,  int &rSize_out)
	{int *bArray = new int[size];
	for(int i = 0; i < size; i++)
	      if(pf_filter(aArray[i])){ bArray[rSize_out] = aArray[i];rSize_out++;}
	return bArray;
	}
	
	int reduce (int (*pf_reduce) (int, int ), int*aArray, int size )
	{
	for(int i = 1;i < size;i++)
	aArray[0] = pf_reduce(aArray[0], aArray[i]);
	return aArray[0];
	}
	
	int func_map1(int value)
	{return value + 5;
	}
	
	int func_map2(int value)
	{return 2 * value;
	}
	
	bool func_filter1(int value)
	{return value > 10;
	}
	
	bool func_filter2(int value)
	{return value > 20;
	}
	
	int func_reduce1(int x, int y  )
	{return 2 * x + y;
	}
	
	int func_reduce2(int x, int y  )
	{return 2 * x -  y;
	}
		int _tmain(int argc, _TCHAR* argv[])
    {int size, result;
    //int (*pf_map) (int );
    //bool (*pf_filter) (int );
    int (*pf_reduce) (int, int );
    cout<<"Input quantity elements of array"<<endl;
	cin>>size;
	int*aArray = new int[size];
	cout<<"Input  array"<<endl;
    for(int i = 0;i < size;i++)	
	cin>>aArray[i];
    aArray = map(func_map1, aArray, size);
    cout<<"  array after map"<<endl;
    for(int i = 0;i < size;i++)
    cout<<aArray[i]<<" ";
    cout<<endl;
    int Size_out = 0;
    int* bArray = filter(func_filter1, aArray, size, Size_out);
    cout<<"  array after filter"<<endl;
    for(int i = 0;i < Size_out;i++)
    cout<<bArray[i]<<" ";
    cout<<endl;
    delete[] aArray;
    aArray = 0;
    pf_reduce = func_reduce1;
    if(Size_out > 1)
    {result = reduce(pf_reduce, bArray, Size_out );
    cout<<"  value after reduce"<<endl;
    cout<<result<<endl;
    }
         else
		 {cout<<"  can not reduce"<<endl;
	     }
			 return 0;
    }

