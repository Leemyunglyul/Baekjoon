#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
//#include <algorithm>

using namespace std;

int arr[1000000];
int stack[1000002][2];
int n;
int st;

void stackcmp(int x, int i)
{
	if (st == -1)
	{
		stack[++st][0] = x;
		stack[st][1] = i;
		return;
	}
	while (x > stack[st][0] && st>=0)
	{
		arr[stack[st][1]] = x;
		st--;
	}
	stack[++st][0] = x;
	stack[st][1] = i;
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	st = 0;
	stack[0][0] = arr[0];
	stack[0][1] = 0;
	for (i = 1; i < n; i++)
		stackcmp(arr[i], i);
	for (i = 0; i <= st; i++)
		arr[stack[i][1]] = -1;
	cout << arr[0];
	for (i = 1; i < n; i++)
		cout <<" " << arr[i];
}