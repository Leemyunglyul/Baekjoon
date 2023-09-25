#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
#include <stack>

using namespace std;

int arr[30001];


int main()
{
	int n, i, max;
	cin >> n;
	max = 0;
	
	for (i = 0; i < n; i++)
		cin >> arr[i];
	int temp = arr[0];
	int tmax = 0;
	for (i = 1; i < n; i++)
	{
		if (temp > arr[i])
			tmax++;
		else if (temp <= arr[i])
		{
			temp = arr[i];
			if (tmax > max)
				max = tmax;
			tmax = 0;
		}
	}
	if (tmax > max)
		max = tmax;
	cout << max;
	return 0;
}