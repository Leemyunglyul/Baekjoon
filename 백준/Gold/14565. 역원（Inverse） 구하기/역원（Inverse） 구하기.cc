#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

long long exEuclid(long long a, long long b, long long& s, long long& t) {
	if (b == 0) {
		s = 1; t = 0;
		return a;
	}
	long long gcd = exEuclid(b, a % b, s, t);
	long long tmp = t;
	t = s - (a / b) * t;
	s = tmp;

	if (s <= 0) { //s를 양수로
		s += b;
		t -= a;
	}
	return gcd;
}

int main() {
	long long a, b, s, t;
	cin >> a >> b;
	long long g = exEuclid(b, a, s, t);
	if (g != 1) cout << a-b << ' ' << -1;
	else cout << a-b << ' ' << s;
}