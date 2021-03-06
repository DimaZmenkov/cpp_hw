// EulerCycle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"AlgGr.h"

	AlgGr::AlgGr():
		n_(6)
	{
		unordered_set<int> st;
		vector<bool> vect;
		testBridge_ = { -1,-1 }; 
		for (int i = 0; i < n_; i++)
		{
			gr_.insert(pair<int, unordered_set<int>>(i, st));
			ind_.push_back(false); 
			
			//idicator_.push_back(false);
		}
		createGraph();
		quantityEdges_ = 0;
		for (auto it = gr_.begin(); it != gr_.end(); ++it)
			quantityEdges_ += it->second.size();
	}
	void AlgGr::createGraph()
	{
		gr_[0].insert(1); gr_[0].insert(2); gr_[1].insert(0); gr_[1].insert(2);
		gr_[1].insert(4); gr_[1].insert(5); gr_[2].insert(0); gr_[2].insert(1);
		gr_[2].insert(3); gr_[2].insert(4); gr_[3].insert(2); gr_[3].insert(4);
		gr_[4].insert(1); gr_[4].insert(2); gr_[4].insert(3); gr_[4].insert(5);
		gr_[5].insert(1); gr_[5].insert(4);

	}
	bool AlgGr::testBridge(const  Point &e)
	{
		testBridge_ = e;
		if (gr_[e.v2].find(e.v1) != gr_[e.v2].end())
			testBridge1_ = { e.v2, e.v1 };
		initInd();
		ind_[0] = true; find(0);
		bool isBridge = false;
		for (int i = 0; i < ind_.size(); i++)
			if (!ind_[i])
			{
				isBridge = true; 
			}
		//gr_[e.v1].insert(e.v2); gr_[e.v2].insert(e.v1);
		testBridge_ = { -1,-1 }; testBridge1_ = { -1,-1 };
		//assert(!isBridge);
		return isBridge;
     }
	void	AlgGr::initInd()
	{
		for (int i = 0; i < ind_.size(); i++)
			ind_[i] = false;

	}
	void AlgGr::find(int i)
	{
		Point p;
		for (auto it = gr_[i].begin(); it != gr_[i].end(); ++it)
		{
			p = { i,*it };
			if ((!ind_[*it]) && (testBridge_ != p) && (testBridge1_ != p))
			{
				ind_[*it] = true; find(*it);

			}
		}
}
	void AlgGr::createEulerCycle(int i)
	{
		//static 
		Point p, p1;
		//cout << "gr_[" << i << "].size()=" << gr_[i].size();
		//assert()
		for (auto it = gr_[i].begin(); it != gr_[i].end(); ++it)
		{
			if ((*it == 0) && (test_.size() < quantityEdges_ - 2)) continue;
			//cout << "*it =" << *it << endl;
			p = { i, *it };
			//if ((test_.find(p) == test_.end()) && (!testBridge(p)))
			if (test_.find(p) == test_.end())
			{

				test_.insert(p); eulerCycle_.push_back(p);
				if (gr_[*it].find(i) != gr_[*it].end())
				
					test_.insert({*it, i});
				
				createEulerCycle(*it);
            }
		}
	}
	void AlgGr::showEulerCycle()const 
	{
		for (auto it = eulerCycle_.begin(); it != eulerCycle_.end(); ++it)
			cout << it->v1 << " "<< it -> v2 << endl;
	}
	bool AlgGr::testEulerCycle()
	{
		for (auto it = gr_.begin(); it != gr_.end(); ++it)
			if ((it -> second.size() % 2 != 0) || (it -> second.size() == 0)) return false;
		return true;
	}

int main()
{
		
	AlgGr alg;
	if (alg.testEulerCycle())
	{
		alg.createEulerCycle(0);
		alg.showEulerCycle();
	}
	else
		cout << "impossible to build euler cycle" << endl;
	
	
	
	
	return 0;
}

