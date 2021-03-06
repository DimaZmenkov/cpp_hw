// Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<memory>
#include<set>
#include<deque>
using namespace std;
class A
{
public:
	A() {}
	virtual shared_ptr<A>	f() =0;
};
class B :public A 
{
public:
	B() {}
	shared_ptr<A>	f()
	{
		cout << "ok" << endl;
		static int count = 0;
		shared_ptr<B>  b(new B());
		
		count++;
		
		cout << count << endl;
		return  b;
	}
	void g() {}
	vector<shared_ptr<A>> vect;
};

struct Point
{
	int x;
	int y;
};
struct Elem
{
	int dist;
	vector<int> route;
};
int main()
{
	vector<vector<Point>> vect;
	vector<Point> vec1;
	int n = 6;
	for (int i = 0; i < n; i++)
		vect.push_back(vec1);
	vect[0].push_back({ 3,2 });
	vect[3].push_back({ 0,2 });
	vect[0].push_back({ 1,1 });
	vect[1].push_back({ 0,1 });
	vect[1].push_back({2 ,1 });
	vect[2].push_back({ 1,1 });
	vect[2].push_back({3 ,1 });
	vect[3].push_back({2 ,1 });
	vect[4].push_back({3 ,1 });
	vect[3].push_back({4 ,1 });
	vect[5].push_back({ 2,1 });
	vect[2].push_back({ 5,1 });
	deque<int> deq;
	vector<Elem> dist;
	Elem elem;
	elem.dist = 1000;
	vector<bool> indicator;
	for (int i = 0; i < n; i++)
	{
		dist.push_back(elem);
		indicator.push_back(false);
	}
	dist[0].dist = 0;
	deq.push_front(0);
	
	while (deq.size() > 0)
	{
		int p = deq.back(); deq.pop_back();
		for(int i =0;i<vect[p].size();i++ )
			if ((dist[p].dist + vect[p][i].y < dist[vect[p][i].x].dist)&&(!indicator[p]))
			{
				dist[vect[p][i].x].dist = dist[p].dist + vect[p][i].y;
				dist[vect[p][i].x].route = dist[p].route;
				dist[vect[p][i].x].route.push_back(vect[p][i].x);
				deq.push_front(vect[p][i].x);
			}
		indicator[p] = true;

	}
	cout << dist[5].dist << endl;
	for (int i = 0; i < dist[5].route.size(); i++)
		cout << dist[5].route[i] << endl;

	return 0;
}

