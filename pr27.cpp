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
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
 ifstream file;
 string str[7] = { "I", "or", "and", "that", "the", "of", "not"};
 
 file.open("D:/test.txt");
	string word;
	size_t pos;
	int i;
	int difference = 'a' - 'A';
	unordered_map<string, int> unMap;
	for(int j = 0; j < 7; j++)
	unMap.insert(pair<std::string, int>(str[j], 1));
	map<string, int> words;
	multimap<int, string> words1;
	while(file>>word)
	{
		
		pos = word.length()-1;
		if(!((word[pos] >= 'A')&&(word[pos]<= 'Z')||(word[pos]>= 'a')&&(word[pos]<= 'z')))  
			{
				word.erase(pos,1);
				pos--;
		    }
		for(int j = 0; j < pos + 1; j++)
	if(word[j] <= 'Z')
		word[j] += difference;
			if(unMap.count(word)!= 0) continue;
		
		++words[word]; 
	
	}
	int count = 0;
	for(auto it = words.begin();it != words.end(); ++it)
	{
		words1.insert( pair<int, string>((*it).second, (*it).first) );
		}
 
	for(auto it = words1.rbegin();it != words1.rend(); ++it)
	{
		cout<<(*it).second<<" "<<(*it).first<<endl;
		count++;
	if (count >= 10) break;
	}
	return 0;
}



