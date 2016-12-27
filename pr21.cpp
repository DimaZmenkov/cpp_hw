// ConsoleApplication54.cpp: определяет точку входа для консольного приложения.
//


//#include "cassert"
#include "stdafx.h"
#include <iostream>

using namespace std;
template<typename T>
    T*  map ( int (*pf_map) (T ), T* aArray, size_t size)
	{
		for(int i = 0;i < size;i++)
	     
			aArray[i] = pf_map(aArray[i]) ;
	
		return aArray;
	
	}
	  template<typename T>
	T* filter ( bool (*pf_filter) (T ), T *aArray, size_t size ,  int &rSize_out)
	{
		int *bArray = new int[size];
	
		for(int i = 0; i < size; i++)
	     
			if(pf_filter(aArray[i]))
			{ 
				bArray[rSize_out] = aArray[i];rSize_out++;
		    }
	return bArray;
	
	}
	template<typename T>
	T reduce (T (*pf_reduce) (T, T ), T*aArray, size_t size )
	{
	for(int i = 1;i < size;i++)
	aArray[0] = pf_reduce(aArray[0], aArray[i]);
	
	return aArray[0];
	
	}
	 template<typename T>
	T func_map1(T value)
	{
		return value + 5;
	}
	template<typename T>
	T func_map2(T value)
	{
		return 2 * value;
	}
	template<typename T>
	bool func_filter1(T value)
	{
		return value > 10;
	}
	template<typename T>
	bool func_filter2(T value)
	{
		return value > 20;
	}
	template<typename T>
	T func_reduce1(T x, T y  )
	{
		return 2 * x + y;
	}
	template<typename T>
	T func_reduce2(T x, T y  )
	{
		return 2 * x -  y;
	}
		int _tmain(int argc, _TCHAR* argv[])
    {
		int  result;
    //int (*pf_map) (int );
    //bool (*pf_filter) (int );
   size_t size;
		
    
		cout<<"Input quantity elements of array"<<endl;
	cin>>size;
	
	int*aArray = new int[size];
	
	cout<<"Input  array"<<endl;
    for(int i = 0;i < size;i++)	
	cin>>aArray[i];
    
	aArray = map<int>(func_map1, aArray, size);
    cout<<"  array after map"<<endl;
    
	for(int i = 0;i < size;i++)
    cout<<aArray[i]<<" ";
    cout<<endl;
    
	int size_out = 0;
    int* bArray = filter<int>(func_filter1, aArray, size, size_out);
    cout<<"  array after filter"<<endl;
    
	for(int i = 0;i < size_out;i++)
   
		cout<<bArray[i]<<" ";
    
	cout<<endl;
    delete[] aArray;
   
	aArray = 0;
    
	
    
	if(size_out > 1)
    {
		result = reduce<int>(func_reduce1, bArray, size_out );
     delete[] bArray;
    bArray = 0;
	
	cout<<"  value after reduce"<<endl;
    cout<<result<<endl;
    }
         else
		 {
			 cout<<"  can not reduce"<<endl;
	     }
			 return 0;
    }

