//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<stdlib.h>
//#include <string>
//#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int dust[52][52];
queue <pair<int, int>> temp;
queue <int> tem;
int air[2];
int r, c;

void spread()
{
	int i, j, num;
	for (i = 1; i <= r; i++) {
		if (temp.empty() == 1)
			break;
		for (j = 1; j <= c; j++) {
			num = 4;
			if (temp.empty() == 1)
				break;
			if (i==temp.front().first && j==temp.front().second)
			{
				if (dust[i][j - 1] == -1 || j == 1) { num--; }
				else {dust[i][j - 1] = dust[i][j-1] + (tem.front() / 5);}
				if (dust[i - 1][j] == -1 || i == 1) { num--; }
				else { dust[i - 1][j] = dust[i-1][j] + (tem.front() / 5); }
				if (j == c) { num--; }
				else { dust[i][j+1] = dust[i][j+1] + (tem.front() / 5); }
				if (dust[i+1][j] == -1 || i == r) { num--; }
				else { dust[i+1][j] = dust[i+1][j] + (tem.front() / 5); }
				dust[i][j] = dust[i][j] - num * (tem.front() / 5);
				temp.pop();
				tem.pop();
			}
		}
	}
}

void Push()
{
	int i, j;
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			if (dust[i][j] > 0){
				temp.push({ i, j });
				tem.push(dust[i][j]);
			}
		}
	}
}

void cir()
{
	int i, j;
	for (i = air[0]-2; i >=1; i--){
		dust[i + 1][1] = dust[i][1];
	}
	for (i = 2; i <= c; i++){
		dust[1][i - 1] = dust[1][i];
	}
	for (i = 2; i <=air[0]; i++) {
		dust[i-1][c] = dust[i][c];
	}
	for (i = c-1; i >=2; i--) {
		dust[air[0]][i+1] = dust[air[0]][i];
	}
	dust[air[0]][2] = 0;
	for (i = air[1] + 2; i <=r; i++) {
		dust[i - 1][1] = dust[i][1];
	}
	for (i = 2; i <= c; i++) {
		dust[r][i - 1] = dust[r][i];
	}
	for (i = r-1; i >= air[1]; i--) {
		dust[i + 1][c] = dust[i][c];
	}
	for (i = c - 1; i >= 2; i--) {
		dust[air[1]][i + 1] = dust[air[1]][i];
	}
	dust[air[1]][2] = 0;
}

/*void Print()
{
	cout << endl;
	int i, j;
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			cout << dust[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}*/

int main()
{
	int t, i, j, x, sum;
	cin >> r >> c >> t;
	for (i = 1, x=0; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			cin >> dust[i][j];
			if (dust[i][j] > 0)
			{
				temp.push({ i, j });
				tem.push(dust[i][j]);
			}
			else if (dust[i][j] == -1)
				air[x++] = i;
		}
	}
	for (i = 0; i < t; i++)
	{
		spread();
		//Print();
		cir();
		Push();
		//Print();
	}
	for (i = 1, sum = 0; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			sum += dust[i][j];
		}
	}
	cout << sum + 2;
}