#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
#include <queue>

using namespace std;

int main()
{
	int n, i, x, sum;
	cin >> n;
	int max = 0;
	for (i = 0, sum=0; i < n; i++)
	{
		cin >> x;
		if (max < x)
			max = x;
		sum += x;
	}
	cout << sum - max;
}