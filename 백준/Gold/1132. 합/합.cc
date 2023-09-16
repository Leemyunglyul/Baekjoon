#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

char word[50][14];
long long anum[11];
long long alpha[11] = { 0 };
long long alphanum[11] = { 0 };
char s[11] = "ABCDEFGHIJ";

void check(int n){
	int x;
	for (int i = 0; i < n; i++){
		alpha[word[i][0] - 65] = 1;
	}
}

void Compare(int n, int num){
	int i, j, c, d;
	long long max = 0;
	long long dec10;
	char x = s[num];
	for (i = 0; i < n; i++)
	{
		c = 0;
		while (word[i][c] != '\0')
			c++;
		j = c - 1;
		dec10 = 1;
		while (j >= 0)
		{
			if (x == word[i][j])
				max += dec10;
			j--;
			dec10 *= 10;
		}
	}
	alphanum[num] = max;
}


int main()
{
	int n, i, j, k, a;
	long long dec10;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", word + i);
	check(n);
	for (i = 0; i < 10; i++)
		Compare(n, i);

	for (i = 0; i <= 9; i++)
		if (alpha[i] == 0)
			break;
	swap(alphanum[i], alphanum[0]);
	for (j = i+1; j <= 9; j++)
		if (alphanum[0] > alphanum[j] && alpha[j] == 0)
			swap(alphanum[j], alphanum[0]);
	sort(alphanum + 1, alphanum + 10);

	for (i = 9; i >= 0; i--)
		anum[i] = i;
	//for (i = 9; i >= 0; i--)
		//printf("<%d %c %lld %lld>\n", alpha[i], s[i], anum[i], alphanum[i]);
	long long sum = 0;
	for (i = 0; i <= 9; i++)
		sum += anum[i] * alphanum[i];
	printf("%lld", sum);
}