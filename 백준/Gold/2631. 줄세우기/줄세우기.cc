#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int arr[1002];
int mem[1002];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	mem[0] = 1;
	for (i = 1; i < n; i++)
	{
		mem[i] = 1;
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
				mem[i] = max(mem[i], mem[j] + 1);
		}
	}
	j = mem[0];
	for (i = 1; i < n; i++)
		j = max(j, mem[i]);
	cout << n-j;
}