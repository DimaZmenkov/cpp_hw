// HamCycle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"HamCycle.h"

HamCycle::HamCycle() :
	n_(4),
	isHamiltonian_(false)
{
	vector<int> vect;
	for (int i = 0; i < n_; i++)
	{
		gr_.push_back(vect); 
		ind_.push_back(false);
	}
	createGraph();
}
void HamCycle::createGraph()
{
	gr_[0].push_back(1); gr_[0].push_back(2); gr_[0].push_back(3); gr_[1].push_back(0);
	gr_[1].push_back(2); gr_[2].push_back(0); gr_[2].push_back(1); gr_[2].push_back(3);
	gr_[3].push_back(0); gr_[3].push_back(2);
}
void HamCycle::createHamiltonCycle(int i,int count)
{
	if (count == n_) 
	{
		isHamiltonian_ = true; return;
	}
for(int j = 0;j < gr_[i].size();j++)
		if (!ind_[gr_[i][j]])
		{
			ind_[gr_[i][j]] = true; route.push_back(gr_[i][j]);
			createHamiltonCycle(gr_[i][j], ++count); 
			if (isHamiltonian_) return;
			ind_[gr_[i][j]] = false; route.pop_back();
		}
}
void HamCycle::showHamiltonCycle() const
{
	for (int i = 0; i < n_; i++)
		cout << route[i] << endl;
}
int main()
{
	HamCycle h;
	h.createHamiltonCycle(0,0);
	h.showHamiltonCycle();
	return 0;
}

