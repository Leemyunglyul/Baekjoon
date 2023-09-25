#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
#include <stack>

using namespace std;
stack <int> s;

int main()
{
	int n, i, x;
	cin >> n;
	s.push(2);
	for (i = 0; i < n; i++)
	{
		cin >> x;
		if (s.top() == 2 && x == 0)
			s.push(0);
		else if (s.top() == 1 && x == 2)
			s.push(2);
		else if (s.top() == 0 && x == 1)
			s.push(1);
	}
	cout << s.size() - 1;
}