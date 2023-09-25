#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
#include <queue>

using namespace std;

int main()
{
	int a, b, c, d, i, sum, tired, work;
	cin >> a >> b >> c >> d;
	for (i = 0, sum=0, tired=0; i < 24; i++)
	{
		if (tired + a <= d)
		{
			sum += b;
			tired += a;
		}
		else
			tired -= c;
		if (tired < 0)
			tired = 0;
	}
	cout << sum;
}