#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
#include <stack>

using namespace std;

unsigned long long int fibo[100];

unsigned long long int fibonacci(int x)
{
	if (x == 0)
		return 0;
	else if (x == 1)
		return 1;
	for (int i = 2; i <= x; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	return fibo[x];
}

int main()
{
	int n;
	fibo[0] = 0;
	fibo[1] = 1;
	cin >> n;
	cout << fibonacci(n);
	return 0;
}