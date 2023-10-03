//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<stdlib.h>
//#include <string>
//#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int arr[101][2];
int dp[101];

int main()
{
	int n, x, y, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		pq.push({ x, y });
	}
	for (i = 0; i < n; i++)
	{
		arr[i][0] = pq.top().first;
		arr[i][1] = pq.top().second;
		pq.pop();
	}
	for (i = 0, x = 1; i < n; i++)
	{
		dp[i] = 1;
		for (j = i-1; j >=0; j--){
			if (arr[i][1] > arr[j][1])
				dp[i] = max(dp[i], dp[j]+1);
		}
		x = max(dp[i], x);
		//cout << dp[i]<<endl;
	}
	cout << n - x;
}