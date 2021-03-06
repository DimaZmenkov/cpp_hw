// Floyd.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"Floyd.h"
Floyd::Floyd():
	n_(5)
{
	vector<float> vect;
	for (int i = 0; i < n_; i++)
	{
		gr_.push_back(vect);
		for (int j = 0; j < n_; j++)
			if(i!=j)
			gr_[i].push_back(100000000);
			else
				gr_[i].push_back(0);
	}
	createGraph();
}
void	Floyd::createGraph()
{
	gr_[0][1] = 1; gr_[0][2] = 2; gr_[1][0] = 1; gr_[2][0] =2 ;
	gr_[2][3] = 2; gr_[2][4] =2 ; gr_[3][2] = 2; gr_[3][4] = 5;
	gr_[4][3] = 5; gr_[4][2] = 2;
}
void Floyd::alg()
{
	for (int k = 0; k < n_; k++)
	for (int i = 0; i < n_; i++)
			for (int j = 0; j < n_; j++)
				if (gr_[i][j] > gr_[i][k] + gr_[k][j])
					gr_[i][j] = gr_[i][k] + gr_[k][j];

	
}
void Floyd::show() const
{
	for (int i = 0; i < n_; i++)
	{
		for (int j = 0; j < n_; j++)
			cout << gr_[i][j] << " ";
		cout << endl;
	}
	
}
int main()
{
	Floyd f;
	f.alg();
	f.show();
    return 0;
}

