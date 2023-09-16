#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int sudoku[9][9];
int s[81];
int BLANK[81];
int k=0;

int check(int n, int m)
{
	int i, j;
	for (i = 0; i < 9; i++)
		if ((sudoku[n][m] == sudoku[i][m] && i != n) || (sudoku[n][m] == sudoku[n][i] && i != m))
			return 0;
	for (i = (n / 3) * 3; i < (n / 3) * 3 + 3; i++)
	{
		for(j=(m/3)*3;j< (m / 3) * 3+3;j++)
			if (sudoku[i][j] == sudoku[n][m] && n != i && m!=j)
				return 0;
	}
	return 1;
}

void blank(int X)
{
	int n = s[X] / 10;
	int m = s[X] % 10;
	int num=0;
	int i, j;
	for (i = 0; i < 9; i++)
		if (sudoku[i][m] == 0 && i != n) 
			num++;
	for (i = 0; i < 9; i++)
		if (sudoku[n][i] == 0 && i != m)
			num++;
	for (i = (n / 3) * 3; i < (n / 3) * 3 + 3; i++)
	{
		for (j = (m / 3) * 3; j < (m / 3) * 3 + 3; j++)
			if (sudoku[i][j] == 0 && !(n == i || m == j))
				num++;
	}
	BLANK[X] = num;
}

void backtracking(int x, int * num)
{
	if (*num == 1)
		return;
	int a = s[x] / 10;
	int b = s[x] % 10;
	for (int i = 1; i <= 9; i++)
	{
		sudoku[a][b] = i;
		if (check(a, b) == 0)
		{
			//printf("아니었다! %d %d: 현재위치 %d 현재 숫자 %d[%d]\n", a, b, x, i,*num);
			continue;
		}
		if (x == k-1)
		{
			//printf("돌아간다 %d->%d\n", x, k);
			*num = 1;
			return;
		}
		//printf("일단 이걸로%d %d: 현재위치 %d 현재 숫자 %d[%d]\n", a, b, x, i, *num);
		backtracking(x + 1, num);
		if (*num == 1)
			return;			
	}
	sudoku[a][b] = 0;
}

void quickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
	int temp;
	do
	{
		while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;
		if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			/*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
			left++;
			right--;
		}
	} while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

	/* recursion */
	if (L < right)
		quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}

int main()
{
	int i, j, num;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++){
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				s[k++] = 10 * i + j;
		}
	}
	//for (i = 0; i < k; i++)
		//blank(i);
	//quickSort(BLANK ,0, k - 1);
	//for (i = 0; i < k; i++)
		//printf("(%d %d)\n", s[i], BLANK[i]);
	num = 0;
	backtracking(0, &num);
	for (i = 0; i < 9; i++) {
		printf("%d", sudoku[i][0]);
		for (j = 1; j < 9; j++) {
			printf(" %d", sudoku[i][j]);
		}
		printf("\n");
	}
}