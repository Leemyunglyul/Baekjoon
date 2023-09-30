//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<stdlib.h>
//#include <string>
//#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

long long  N[4000001], a1[31], b1[31];
int n, k;
const int p = 1000000007;

int main()
{
	int i, j;
	unsigned long long int result, a, b, x;
	cin >> n >> k;
	for (i = 2,  N[1]=1; i <= n; i++)
		N[i] = (N[i - 1] * i) % p;
	for (x=p-2, a=1, b= N[n - k]* N[k]%p;x > 0;){
		if (x % 2==1)
			a = a * b % p;
		b = b * b % p;
		x /= 2;
	}
	if (n == k || k == 0)
	{
		cout << "1";
		return 0;
	}
	result = N[n] * a % p;
	cout << result;
}