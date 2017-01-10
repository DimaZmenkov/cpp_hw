#include "stdafx.h"
#include <iostream>
#include <cassert>



using namespace std;
template<typename T>
size_t count_if(T* arr, size_t length, bool(*p)(const T& elem))
{
size_t count = 0;
for(int i = 0;i < length ;i++)
if(p(arr[i]))  count++; 
return count;
}
 
template<typename T>
bool is_sorted(T* arr, size_t length)
{
	for(int i = 0;i < length - 1 ;i++)
		if(arr[i] >= arr[i + 1]) return false;
	return true;
}
template<typename T>
bool func(const T& elem)
 {
	 return elem > 0;
 }

int _tmain(int argc, _TCHAR* argv[])
{
	int* arr = new int[5];
	for(int i = 0;i < 5 ;i++)
		arr[i] = i - 1;
	assert(count_if<int>(arr, 5, func) == 3);
	assert(is_sorted<int>(arr, 5) == true);
		
	
	return 0;
}