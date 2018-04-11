#pragma once
#include <vector>
#include<iostream>
using namespace std;
class HamCycle
{
	int n_;
	vector<vector<int>> gr_;
	vector<int> route;
	vector<bool> ind_;
	bool isHamiltonian_;
	void createGraph();
public:
	HamCycle();
	
	void createHamiltonCycle(int i,int count);
	void showHamiltonCycle()const;
	

};