#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <vector>
#include <math.h>
//#include <queue>

void Print(int x, int y){printf("%d %d\n", x, y); }

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		Print(from, to);
		return;
	}
	hanoi(n - 1, from, to, by);
	Print(from, to);
	hanoi(n - 1, by, from, to);
}

int main()
{
	int n;
	scanf("%d", &n);
	double result = pow(2, n);
	long long int x = (long long int)result - 1;
	printf("%lld\n", x);
	hanoi(n, 1, 2, 3);
}