//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <string>
//#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int arr[1002];
int mem[1002][2] = {0};

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	mem[0][1] = 1;
	mem[0][0] = 1;
	for (i = 1; i < n; i++)
	{
		mem[i][1] = 1;
		for (j = i - 1; j >= 0 && i<n-1; j--)
		{
			if (arr[i] > arr[j])
				mem[i][1] = max(mem[i][1], mem[j][1] + 1);
		}
		mem[i][0] = mem[i][1];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[i] < arr[j])
				mem[i][0] = max(mem[i][0], mem[j][0] + 1);
		}
	}
	for (i = 0, j = 0; i < n; i++)
	{
		//cout << mem[i][0]<<" " << mem[i][1]<< endl;
		j = max(j, mem[i][0]);
	}
	cout << j;
}