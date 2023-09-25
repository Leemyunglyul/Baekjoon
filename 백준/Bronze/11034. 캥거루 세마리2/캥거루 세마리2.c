#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//#include <queue>
#include <stdio.h>

//using namespace std;

int main()
{
	int a, b, c, i,x, sum;
	while (scanf("%d %d %d", &a, &b, &c) != -1)
	{
		if (b - a >= c - b)
			x = b - a-1;
		else
			x = c - b-1;
		printf("%d\n", x);
	}
}