#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int A[101];
long long Memory[101];
int cal[101][4];
int n;
long long Min = 1000000001;
long long Max=-1000000001;

void bruteback(int x)
{
	if (x == n)
	{
		if (Memory[x-1] > Max)
			Max = Memory[x - 1];
		if (Memory[x - 1] < Min)
			Min = Memory[x - 1];
		return;
	}
	int i, j;
	for (i = 0; i < 4; i++)
	{
		Memory[x] = Memory[x - 1];
		for (j = 0; j < 4; j++)
			cal[x][j] = cal[x - 1][j];
		if (i == 0 && cal[x][i] > 0){
			Memory[x] += A[x];
			--cal[x][i];
			bruteback(x + 1);
		}
		else if (i == 1 && cal[x][i] > 0) {
			Memory[x] -= A[x];
			--cal[x][i];
			bruteback(x + 1);
		}
		else if (i == 2 && cal[x][i] > 0) {
			Memory[x] *= A[x];
			--cal[x][i];
			bruteback(x + 1);
		}
		else if (i == 3 && cal[x][i] > 0)
		{
			if (Memory[x] < 0)
			{
				Memory[x] = -Memory[x];
				Memory[x] /= A[x];
				Memory[x] = -Memory[x];
			}
			else
				Memory[x] /= A[x];
			--cal[x][i];
			bruteback(x + 1);
		}
		
		
	}
	return;
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> A[i];
	for (i = 0; i < 4; i++)
		cin >> cal[0][i];
	Memory[0] = A[0];
	bruteback(1);
	cout << Max << endl << Min << endl;
}