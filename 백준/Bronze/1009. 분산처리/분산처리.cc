#include<iostream>
#include<math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, n, i, a, b, t;
	cin >> testn;
	while (testn--) {
		cin >> a >> b;
		for (i = 2, t=a%10; i <= b; i++) {
			t = a * t % 10;
		}
		if (t == 0) cout << "10\n";
		else cout << t << "\n";
	}
}