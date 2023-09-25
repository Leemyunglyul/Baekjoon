#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
#include <stack>

using namespace std;


int main()
{
	int a, b, c, use, i;
	cin >> a >> b >> c;
	i = 1;
	while (!(a == 0 && b == 0 && c == 0))
	{
		use = 0;
		use += (c / b)*a;
		if (c % b > a)
			use += a;
		else
			use += c % b;
		cout << "Case " << i++ << ": " << use<<endl;
		cin >> a >> b >> c;
	}
}