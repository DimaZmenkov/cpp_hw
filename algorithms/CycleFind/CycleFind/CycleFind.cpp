// CycleFind.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

int findCycle(vector<bool> & vi,  vector<vector<int>>& gr, int i,int prev, bool& f)
{
	
	for (int j =0;j < gr[i].size();j++)
	{
		if (gr[i][j] == prev) continue;
		if(vi[gr[i][j]]) { f = true; return 0; }
		//if (vi[*it])  { f = true; return 0; }
		//if (vi[gr[i][j]]) { f = true; return 0; }
		vi[gr[i][j]] = true;
		findCycle(vi, gr, gr[i][j],i, f);
		if (f) return 0;
	}
}

bool cycleTest(vector<bool> & vi,  vector<vector<int>>& gr)
{
	bool haveCycle = false;
	while (true)
	{
		//cout << "fffffffffffffff"  << endl;
		bool flag = true;
		for(int i =0;i < vi.size();i++)
			if (!vi[i])
			{
				//cout << "fffffffffffffff" <<i<< endl;
				vi[i] = true;
				flag = false;
				findCycle(vi, gr, i, i, haveCycle);
				if (haveCycle)
				{
					flag = true;
					
				}
				break;
			}
		if (flag) break;
			

	}
	return haveCycle;
}

int main()
{
	vector<vector<int>> gr;
	vector<bool> ind;
	const int n = 6;
	vector<int > vect;
	for (int i = 0; i < n; i++)
	{
		ind.push_back(false); gr.push_back(vect);
	}
	gr[0].push_back(1); gr[1].push_back(0); gr[0].push_back(2); gr[2].push_back(0); 
	gr[2].push_back(3);
	gr[3].push_back(2); gr[3].push_back(5); 
	gr[5].push_back(3); gr[3].push_back(4); gr[4].push_back(3);
	//gr[1].push_back(3);
	if (cycleTest(ind, gr))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
    return 0;
}

