#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int binary_search(int array[], int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == array[mid])
			return mid;
		else if (key < array[mid])
			high= mid - 1;
		else if (key > array[mid])
			low= mid + 1;
	}
	return -1;
}

int main()
{
	int x, y, i, j;
	scanf("%d", &x);
	int* arr1 = (int*)malloc(sizeof(int) * x);
	scanf("%d", &arr1[0]);
	for (i = 1; i < x; i++)
		scanf(" %d", &arr1[i]);
	scanf("%d", &y);
	int* arr2 = (int*)malloc(sizeof(int) * y);
	scanf("%d", &arr2[0]);
	for (i = 1; i < y; i++)
		scanf(" %d", &arr2[i]);
	qsort(arr1, x, sizeof(int), compare);
	for (i = 0; i < y; i++)
	{
		j = binary_search(arr1, x, arr2[i]);
		if (j == -1)
			printf("0\n");
		else
			printf("1\n");
	}

}