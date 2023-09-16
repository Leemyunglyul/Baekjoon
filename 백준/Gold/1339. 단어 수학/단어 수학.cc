#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

char word[10][11];
long long anum[11];
long long alpha[11] = {0};
long long alphanum[11] = {0};
char s[11];
int number=0;

void check(char sw)
{
	for (int i = 0; i < 10; i++)
	{
		if (alpha[i]++ == 0){
			s[i] = sw;
			number++;
			return;
		}
		if (s[i] == sw){
			return;
		}
	}
}

void Compare(int n, int num)
{
	int i, j, c,d;
	long long max = 0;
	long long dec10;
	char x = s[num];
	for (i = 0; i < n; i++)
	{
		c = 0;
		while (word[i][c] != '\0')
			c++;
		j = c-1;
		dec10 = 1;
		while (j>=0)
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
	int n, i, j, k,a;
	long long dec10;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", word+i);
	for (i = 0; i < n; i++){
		j = 0;
		while (word[i][j] != '\0')
		{
			check(word[i][j]);
			j++;
		}
	}
	long long temp;
	for (i = 0; i < number; i++)
		Compare(n, i);
	
	sort(alphanum, alphanum + number);
	a = 9;
	for (i = number - 1; i >= 0; i--)
		anum[i] = a--;
	//for (i = number - 1; i >= 0; i--)
		//printf("<%c %lld %lld>\n", s[i], anum[i], alphanum[i]);
	long long sum = 0;
	for (i = 0; i < number; i++)
		sum += anum[i] * alphanum[i];
	printf("%lld", sum);
}