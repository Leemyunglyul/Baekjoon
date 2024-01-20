#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<queue>
//#include<deque>
//#include<string.h>
#include<math.h>
#include<cmath>
#include<map>
#include<algorithm>
//#include<functional>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y;
	double a, b;
	while (cin >> x >> y) {
		a = double(100 * x) / y;
		cout << fixed;
		cout. precision(2);
		cout << round(a)/100<<endl;
	}
}