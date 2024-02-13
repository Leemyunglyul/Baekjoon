#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int prize(int A, int C, int r, int g, int b) {
	return A * (r * r + g * g + b * b) + C * min(r, min(g, b));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, a, c, r, g, b, i;
	cin >> testn;
	while (testn--) {
		cin >> a >> c >> r >> g >> b;
		int t1 = prize(a, c, r + 1, g, b);
		int t2 = prize(a, c, r, g + 1, b);
		int t3 = prize(a, c, r, g, b + 1);
		if (t1 >= t2 && t1 >= t3) cout << "RED\n";
		else if (t2 >= t1 && t2 >= t3) cout << "GREEN\n";
		else cout << "BLUE\n";
	}
}