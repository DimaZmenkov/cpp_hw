// ConsoleApplication118.cpp: определяет точку входа для консольного приложения.
//

// ConsoleApplication116.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <algorithm>
//#define D_SCL_SECURE_NO_WARNINGS
using namespace std;

int _tmain(int argc, _TCHAR* argv[])

{
 ifstream file;
 string str[7] = { "I", "or", "and", "that", "the", "of", "not"};
 
 set<string> testSet( str, str + 6);
 file.open("D:/test.txt");
	string word,word1;
	//const string test1 ="0123456789+-_";
	size_t pos;
	map<string, int> words;
	multimap<int, string> words1;
	while(file>>word)
    
	{
		//transform (word.begin(), word.end(), word.begin(), ::tolower, [](char ch) -> char
		//{if  ((ch >= 'a')&&(ch <= 'z')||(ch =='+')) return ch;      } );
		//Compiler write:
		//Ошибка	2	error C4996: 'std::_Transform2': Function call with parameters that may be unsafe - this
			//call relies on the caller to check that the passed values are correct. To disable this warning, 
			//use -D_SCL_SECURE_NO_WARNINGS. See documentation on how to use Visual C++ 'Checked Iterators'	
//c:\program files (x86)\microsoft visual studio 11.0\vc\include\algorithm	1207	1	ConsoleApplication126


		transform (word.begin(), word.end(), word.begin(), ::tolower );
	int	pos = word.length() - 1 ;
		
		for (int j = 0; j < 3; j++)
		{
			if(j == 2) pos = 0;
			if (pos >= 0)
			if(!((word[pos] >= 'a')&&(word[pos] <= 'z')||(word[pos]=='+')))
		   {
			word.erase(pos, 1);pos--;
		   }
		}		
		   if(binary_search(testSet.begin (), testSet.end(), word )) continue;
			++words[word]; 
	}

	int count = 0;
	for(auto it = words.begin();it != words.end(); ++it)
	words1.insert( pair<int, string>((*it).second, (*it).first) );
	for(auto it = words1.rbegin();it != words1.rend(); ++it)
	
	{
		cout<<(*it).second<<" "<<(*it).first<<endl;
		count++;
	if (count >= 10) break;
	}

	return 0;
}





