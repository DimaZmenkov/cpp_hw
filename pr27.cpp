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
	size_t pos;
	int i;
	map<string, int> words;
	map<int, string> words1;
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
		pos = word.length()-1;
		if(!((word[pos] >= 'A')&&(word[pos]<= 'Z')||(word[pos]>= 'a')&&(word[pos]<= 'z')))  
			word.erase(pos,1);
		
	++words[word]; 
	
	}
	int count = 0;
	for(auto it = words.begin();it != words.end(); ++it)
	{
		words1[(*it).second] = (*it).first;
		}
 
	for(auto it = words1.rbegin();it != words1.rend(); ++it)
	{
		
		cout<<(*it).second<<" "<<(*it).first<<endl;
		
	count++;
	if (count >= 10) break;
	}
	return 0;
}


