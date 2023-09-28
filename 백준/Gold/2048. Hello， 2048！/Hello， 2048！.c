#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <string>
//#include <vector>
//#include <iostream>
//#include <cmath>
//#include <queue>
//using namespace std;

int main()
{
	int n, i, a, b;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		if (b >= 4)
			printf("%d\n", b);
		else if (a == b)
			printf("%d\n", b);
		else if (a == 0 && (b == 1 || b == 2))
			printf("2\n");
		else if(a == 1 && (b == 2 || b == 3))
			printf("3\n");
		else if(a==0 && b==3)
			printf("5\n");
		else if (a == 2 && b == 3)
			printf("4\n");
	}
	return 0;
}