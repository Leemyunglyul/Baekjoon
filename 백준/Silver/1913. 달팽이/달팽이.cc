#include <iostream>
#include <string>
#include <vector>
//#include <math.h>
#include <queue>

using namespace std;

int s[1000][1000];

int main()
{
	int n, number;
	int i, u, d, r, l, j;
	cin >> n >> number;
	u = 0;
	d = n - 1;
	r = n - 1;
	l = 0;
	int distance = n * n;
	i = 0; j = 0;
	int move = 0;
	int output[2];
	while (distance > 0)
	{
		if (move == 0)
		{
			s[i][j] = distance;
			if (distance == number)
			{
				output[0] = i;
				output[1] = j;
			}
			if (i + 1 == d)
			{
				l++;
				move = 1;
			}
			i++;
		}
		else if (move == 1)
		{
			s[i][j] = distance;
			if (distance == number)
			{
				output[0] = i;
				output[1] = j;
			}
			if (j + 1 == r)
			{
				d--;
				move = 2;
			}
			j++;
		}
		else if (move == 2)
		{
			s[i][j] = distance;
			if (distance == number)
			{
				output[0] = i;
				output[1] = j;
			}
			if (i - 1 == u)
			{
				r--;
				move = 3;
			}
			i--;
		}
		else if (move == 3)
		{
			s[i][j] = distance;
			if (distance == number)
			{
				output[0] = i;
				output[1] = j;
			}
			if (j - 1 == l)
			{
				u++;
				move = 0;
			}
			j--;
		}
		distance--;
	}
	for (i = 0; i < n; i++)
	{
		cout << s[i][0];
		for (j = 1; j < n; j++)
			cout << " " << s[i][j];
		cout << endl;
	}
	cout << output[0]+1 << " " << output[1]+1;
}