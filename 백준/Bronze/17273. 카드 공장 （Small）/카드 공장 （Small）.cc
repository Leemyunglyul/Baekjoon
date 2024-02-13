#include<iostream>
#include<math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, f, b, con, x;
	cin >> n >> m;
	cin >> f >> b;
	for (i = 0, con=0; i < m; i++) {
		cin >> x;
		if (con == 0 && f <= x) {
			con = 1;
		}
		else if (con == 1 && b <= x) {
			con = 0;
		}
	}
	if (con == 0) cout << f;
	else cout << b;
}