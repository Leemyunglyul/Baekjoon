#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
#include <stack>

using namespace std;

int main()
{
	int n, i, min, max;
	string X, Y, a, b;
	cin >> X >> Y;
	a = X;
	b = Y;
	for (i = 0; i < a.size(); i++)
		if (a[i] == 53)
			a[i] = '6';
	for (i = 0; i < b.size(); i++)
		if (b[i] == 53)
			b[i] = '6';
	min = stoi(a) + stoi(b);
	for (i = 0; i < a.size(); i++)
		if (a[i] == 54)
			a[i] = '5';
	for (i = 0; i < b.size(); i++)
		if (b[i] == 54)
			b[i] = '5';
	max = stoi(a) + stoi(b);

	cout << max<< " " << min;
	return 0;
}