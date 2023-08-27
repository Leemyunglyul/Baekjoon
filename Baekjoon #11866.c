#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int x, y, num, i, first, last;
	scanf("%d %d", &x, &y);
	printf("<");
	first = 0;
	last = x - 1;
	int size = last - first + 1;
	int* arr = (int*)malloc(sizeof(int) * (x + y));
	for (i = 0; i < x; i++)
		arr[i] = i+1;
	num = y;
	while (size != 1)
	{
		while (num != 1)
		{
			arr[++last] = arr[first++];
			num--;
		}
		printf("%d, ", arr[first++]);
		for (i = first; i <= last; i++)
			arr[i - first] = arr[i];
		size = last - first + 1;
		first = 0;
		last = size - 1;
		num = y;
	}
	printf("%d>", arr[0]);
}