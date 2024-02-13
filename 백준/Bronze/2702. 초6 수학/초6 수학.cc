#include<iostream>
#include<math.h>

using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, x,y ;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		int temp= gcd(max(x, y), min(x, y));
		cout << x * y / temp << " " << temp << "\n";
	}
}