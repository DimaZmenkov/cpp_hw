// Testgr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<unordered_map>
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
	unordered_set<int> st;
	st.insert(1); st.insert(2); st.erase(st.find(1)); st.erase(st.find(2));
	for (auto it = st.begin(); it != st.end(); ++it)

		cout << *it << endl;
	
	unordered_map<int, unordered_set<int>> gr_;
	for (int i = 0; i < 6; i++)
	{
		gr_.insert(pair<int, unordered_set<int>>(i, st));
		
	}

	for (int i = 0; i < 6; i++)
	{
		
		gr_[i].insert(1); gr_[i].insert(2);
	}
	gr_[0].erase(gr_[0].find(1)); gr_[7].erase(gr_[8].find(1));
	for(auto it  = gr_[0].begin();it!=gr_[0].end();++it)
		cout << *it << endl;

	return 0;
}

