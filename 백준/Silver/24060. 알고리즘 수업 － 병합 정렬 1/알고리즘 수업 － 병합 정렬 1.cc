//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<stdlib.h>
//#include <string>
//#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N, K, arr[1000001];
int num = 0;
int* arr2;
int x=0;

void merge(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) arr2[k++] = arr[tmp++];

	for (int i = left; i <= right; i++)
	{
		arr[i] = arr2[i];
		x++;
		if (x == K)
			num = arr2[i];
	}
}

void partition(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main()
{
	cin >> N >> K;
	arr2 = new int[N];
	for (int i = 0; i < N; i++) cin>>arr[i];

	partition(0, N - 1);

	if (num == 0)
		cout << "-1";
	else
		cout << num;
}