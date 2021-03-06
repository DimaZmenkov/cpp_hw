// Prim.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<unordered_set>
#include<set>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
struct GraphElem
{
	int elem;
	float dist;
};
inline bool operator < (const GraphElem& elem1, const GraphElem& elem2)
{
	return elem1.elem < elem2.elem;
}

int main()
{
	unordered_set<int> set1, set2;
	vector<unordered_map<int,float>> graph1, graph2;
	set1.insert(0);
	set2.insert(1); set2.insert(2); set2.insert(3); set2.insert(4);
	GraphElem  elem;
	unordered_map<int, float> unMap;
	const int n = 5;
	for (int i = 0; i < n; i++)
	{
		graph1.push_back(unMap);
		graph2.push_back(unMap);
		
    }
	elem = { 1,1 }; graph1[0].insert(pair<int, float>(1,1));
	elem = { 0,1 }; graph1[1].insert(pair<int, float>(0, 1));
	elem = {3,4};  graph1[0].insert(pair<int, float>(3, 4));
	elem = {0,4}; graph1[3].insert(pair<int, float>(0, 4));
	elem = { 1,8 }; graph1[2].insert(pair<int, float>(1, 8));
	elem = { 2,8 }; graph1[1].insert(pair<int, float>(2, 8));
   elem = {4,9}; graph1[2].insert(pair<int, float>(4, 9));
   elem = { 2,9 }; graph1[4].insert(pair<int, float>(2, 9));
   elem = {4,6}; graph1[1].insert(pair<int, float>(4, 6));
   elem = {1,6}; graph1[4].insert(pair<int, float>(1, 6));
   elem = { 3,5 }; graph1[1].insert(pair<int, float>(3, 5));
   elem = { 1,5 }; graph1[3].insert(pair<int, float>(1, 5));
   elem = { 4, 7}; graph1[3].insert(pair<int, float>(4, 7));
   elem = { 3,7 }; graph1[4].insert(pair<int, float>(3, 7));
	float min  =  20;
	int minElem, minEl1;
	unordered_set<int> ::iterator itMin;
	while (set2.size() > 0)
	{
		min = 20;
		for (auto it1 = set1.begin(); it1 != set1.end(); ++it1)
		{
			for (auto it2 = set2.begin(); it2 != set2.end(); ++it2)
			{
				auto itHelp = graph1[*it1].find(*it2);
				if (itHelp != graph1[*it1].end())
					if (itHelp->second < min)
					{
						itMin = it2; min = itHelp->second; minElem = *it2; minEl1 = *it1;
					}
				
			}
		}
		set2.erase(itMin); 
		set1.insert(minElem);
		//elem = { minElem , min };
		graph2[minElem].insert(pair<int, float>(minEl1, min));
		graph2[minEl1].insert(pair<int, float>(minElem, min));
		
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << " ";
		for (auto it = graph2[i].begin(); it != graph2[i].end(); ++it)
			cout << it -> first << " ";
		cout << endl;
    }
	
	return 0;


}

