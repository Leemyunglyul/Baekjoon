#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int stack[500001];
int st=-1;
int h[500001] = { 0 };
int Plus[500001] = { 0 };
int n;
unsigned long long int number = 0;

void oasis(int x)
{
	stack[++st] = h[x];
	Plus[st] = 0;
	int i = st-1;
	while (i>=0)
	{
		number++;
		if (stack[i] < stack[st])
		{
			number += Plus[i];
			Plus[i] = Plus[st];
			stack[i--] = stack[st--];
		}
		else if (stack[i] == stack[st])
		{
			number+=Plus[i];
			Plus[i] = Plus[i] + 1;
			stack[i--] = stack[st--];
		}
		else if (stack[i] > stack[st])
			return;
	}
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> h[i];
	for (i = 0; i < n; i++)
		oasis(i);
	cout << number;
}