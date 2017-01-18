#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
 ifstream file;
 string str[7] = { "I", "or", "and", "that", "the", "of", "not"};
 file.open("D:/test.txt");
	string word;
	map<string, int> words;
	while(file>>word)
	{
		bool flag = true; 
		for(int i = 0; i < 7; i++)
		if(str[i] == word) 
		{
			flag = false;
			break;
		}
		if(!flag) continue;	
		
		
	++words[word];
	}
	for(auto it = words.rbegin();it != words.rend(); ++it)
	cout<<(*it).first<<" "<<--(*it).second<<endl;
	

 return 0;
}


