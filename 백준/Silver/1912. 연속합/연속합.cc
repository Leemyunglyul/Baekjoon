//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<stdlib.h>
//#include <string>
//#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int arr[100010];
int mem[100010];
int big[100010];

int main()
{
	int n, i, j, x, sum, Min, k;
	cin >> n;
	for (i = 0, x=0, Min=-1001; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0)
			x = 1;
		if (arr[i] > Min)
			Min = arr[i];
	}
	if (x == 0)
	{
		cout << Min;
		return 0;
	}
	for (i = 0, j = 0, sum = 0, mem[0] = -1; i < n; i++)
	{
		if (j == 0 && arr[i] <= 0 && sum == 0);
		else if (j == 0 && i>0 &&arr[i - 1] <= 0 && arr[i] > 0)
			sum = arr[i];
		else if (i > 0 && ((arr[i - 1] <= 0 && arr[i]>0) || (arr[i - 1] > 0 && arr[i] <= 0)))
		{
			mem[j++] = sum;
			sum = arr[i];
		}
		else
			sum += arr[i];
	}
	mem[j] = sum;
	for (i = 0, sum=0; i <= j; i++)
	{
		if (i == 0)
		{
			big[0] = mem[0];
			sum += mem[0];
		}
		else if (i % 2 == 1)
		{
			if (sum + mem[i] <= 0)
				sum =0 ;
			else
				sum += mem[i];
		}
		else
		{
			big[i] = mem[i]+sum;
			sum += mem[i];
		}
		
	}
	for (i = 0, Min=-123456789; i <= j; i+=2)
	{
		//cout << mem[j] << " " << big[i] << endl;
		if (Min < big[i])
			Min = big[i];
	}
	cout << Min;
}