//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<stdlib.h>
#include <string>
//#include <vector>
#include <iostream>
#include <cmath>
//#include <queue>
using namespace std;

int LCS[1002][1002];

int main()
{
	string x, y;
	cin >> x >> y;
	int i, j;
	for (i = 1; i <= x.size(); i++)
	{
		for (j = 1; j <= y.size(); j++)
		{
			if (x[i-1] == y[j-1])
				LCS[i][j] = LCS[i-1][j-1] + 1;
			else
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	cout << LCS[x.size()][y.size()];
}