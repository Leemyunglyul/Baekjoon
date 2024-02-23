#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, c, i;
	cin >> n>>c;
	n = n - (n % 100);
	for (i = 0; i <= 99; i++) {
		if ((n + i) % c == 0) break;
	}
	if (i < 10) cout << "0" << i;
	else cout << i;
}