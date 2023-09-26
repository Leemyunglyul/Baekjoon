//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <string>
//#include <vector>
//#include <cmath>
//#include <stack>
#include <iostream>
using namespace std;

int home[101][2];
int Distance[101][14] = {0};
int chicken[14][2];
int Min=200000000;
int chis[14];
int arr[100];
int H, C, m, n;

static int num = 0;

int chick_Street()
{
	int i, j;
	//cout << endl;
	for (i = 0; i < H; i++)
		arr[i] = 300;
	for (j = 0; j < m; j++) {
		for (i = 0; i < H; i++) {
			if (arr[i] > Distance[i][chis[j]])
				arr[i] = Distance[i][chis[j]];
		}
	}
	int sum = 0;
	for (i = 0; i < H; i++)
		sum += arr[i];
	return sum;
}

void backtrack(int x)
{
	if (num == m)
	{
		int x = chick_Street();
		//cout << x << endl;
		if (Min >x)
			Min = x;
		return;
	}
	int i;
	for (i = x; i < C; i++)
	{
		if (m - num > C - i)
			return;
		chis[num]=i;
		num++;
		backtrack(i + 1);
		num--;
	}
}


int distancE(int x1, int y1, int x2, int y2)
{
	int d = 0;
	d += x2 > x1 ? x2 - x1 : x1 - x2;
	d += y2 > y1 ? y2 - y1 : y1 - y2;
	return d;
}


int main()
{
	int i, j, x;
	cin >> n >> m;
	for (i = 0, H=0, C=0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> x;
			if (x == 1)
			{
				home[H][0] = i;
				home[H++][1] = j;
			}
			else if (x == 2)
			{
				chicken[C][0] = i;
				chicken[C++][1] = j;
			}
		}
	}
	for (i = 0; i < H; i++) {
		for (j = 0; j < C; j++) {
			Distance[i][j] = distancE(home[i][0], home[i][1], chicken[j][0], chicken[j][1]);
			//cout << Distance[i][j] << endl;
		}
	}
	backtrack(0);
	cout << Min;
}