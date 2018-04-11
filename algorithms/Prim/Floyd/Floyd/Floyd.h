#pragma once
#include <vector>
#include<iostream>
using namespace std;
class Floyd
{
	int n_;
	vector<vector<float>> gr_;
	void	createGraph();
    public:
		Floyd();
	
	void alg();
	void show() const;
};