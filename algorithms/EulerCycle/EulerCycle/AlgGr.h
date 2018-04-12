#pragma once
#include "stdafx.h"
#include<vector>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<iostream>
#include"Point.h"
#include<cassert>
using namespace std;
class AlgGr
{
	int n_;
	unordered_map<int, unordered_set<int>> gr_;
	//vector<int> cycles_;
	vector<bool> ind_;
	//vector<bool> idicator_;
	vector<Point> eulerCycle_;
	set<Point> test_;
	Point testBridge_;
	Point testBridge1_;
	int quantityEdges_;
	
public:
	
	AlgGr();
	void createGraph();
	bool testBridge(const Point& e);
	bool testEulerCycle();
void	initInd();
void find(int i);
void createEulerCycle(int i);
void showEulerCycle()const;
	
};