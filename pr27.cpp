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

using namespace std;

int _tmain(int argc, _TCHAR* argv[])

{
 ifstream file;
 string str[7] = { "I", "or", "and", "that", "the", "of", "not"};
 set<string> testSet( str, str + 6);
 file.open("D:/test.txt");
	string word;
	size_t pos;
	map<string, int> words;
	multimap<int, string> words1;
	while(file>>word)
    
	{
			 transform (word.begin(), word.end(), word.begin(), ::tolower);
		pos = word.length() - 1;
		if(!((word[pos] >= 'a')&&(word[pos] <= 'z')))  
			word.erase(pos, 1);
				//pos--;
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





