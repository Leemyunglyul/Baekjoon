#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x, y;
	cin >> x >> y;
	int t1, t2;
	t1 = 0;
	t2 = 0;
	while (t1 < x.size() || t2 < y.size()) {
		if (t2==y.size() || (x[t1] < y[t2] && t1<x.size())) {
			cout << x[t1++];
		}
		else cout << y[t2++];
	}
}