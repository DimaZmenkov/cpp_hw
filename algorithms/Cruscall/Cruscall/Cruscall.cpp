// Cruscall.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<unordered_set>
#include<set>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<cassert>
//#include<multiset>
using namespace std;
struct E
{
	int v1;
	int v2;
	float dist;
};
inline bool operator < (const E& elem1, const E& elem2)
{
	return elem1.dist < elem2.dist;
}
void findCycle(vector<bool>& vi, const vector<unordered_map<int, float>>& gr,int i,
	int prev, bool& f)
{
	for (auto it = gr[i].begin(); it != gr[i].end(); ++it)
	{
		if (it->first == prev) continue;
		if (vi[it->first]) { f = true; return; }

		vi[it->first] = true;
		findCycle(vi, gr, it->first,i, f);
			if (f) return;
	}
}
int main()
{
	multiset<E> st;
	vector<unordered_map<int, float>> graph1, graph2;
	vector<bool> vi;
	
	unordered_map<int, float> unMap;
	const int n = 5;
	for (int i = 0; i < n; i++)
	{
		graph1.push_back(unMap);
		graph2.push_back(unMap);

	}
	 graph1[0].insert(pair<int, float>(1, 1));
 graph1[1].insert(pair<int, float>(0, 1));
	  graph1[0].insert(pair<int, float>(3, 4));
	 graph1[3].insert(pair<int, float>(0, 4));
	 graph1[2].insert(pair<int, float>(1, 8));
	 graph1[1].insert(pair<int, float>(2, 8));
	 graph1[2].insert(pair<int, float>(4, 9));
	 graph1[4].insert(pair<int, float>(2, 9));
	 graph1[1].insert(pair<int, float>(4, 6));
	 graph1[4].insert(pair<int, float>(1, 6));
	 graph1[1].insert(pair<int, float>(3, 5));
	 graph1[3].insert(pair<int, float>(1, 5));
	 graph1[3].insert(pair<int, float>(4, 7));
	 graph1[4].insert(pair<int, float>(3, 7));
	float min = 20;
	int minElem, minEl1;
	for (int i = 0; i < n; i++)
		for (auto it = graph1[i].begin(); it != graph1[i].end(); ++it)
			st.insert({ i,it->first,it->second });
	for (int i = 0; i < n; i++)
		vi.push_back(false);
	for(auto it =st.begin();it!= st.end();++it)
	{
		for (int j = 0; j < vi.size(); j++)
		vi[j] = false;
			bool haveCycle = false;
			graph2[it->v1].insert(pair<int, float>(it->v2, it->dist));
			graph2[it->v2].insert(pair<int, float>(it->v1, it->dist));
			while (true)
			{
				bool flag = true;
				for (int i = 0; i < vi.size(); i++)
					if (!vi[i])
					{
						flag = false;
						vi[i] = true;
						findCycle(vi, graph2, i,i, haveCycle);
						if (haveCycle)
						{
							assert(graph2[it->v1].size() > 0);
							graph2[it->v1].erase(graph2[it->v1].find(it->v2));
							graph2[it->v2].erase(graph2[it->v2].find(it->v1));
							flag = true;
							break; 
						}
						
					}
				if (flag) break;

			}
	}
	for (int i = 0; i < graph2.size(); i++)
	{
		cout << i << " ";
		for (auto it = graph2[i].begin(); it != graph2[i].end(); ++it)
			cout << it -> first << " ";
		cout << endl;
	}
	cout << "ok" << endl;
	
	return 0;
}

