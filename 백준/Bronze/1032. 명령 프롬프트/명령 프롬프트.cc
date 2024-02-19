#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, j;
	string x, y;
	cin >> n;
	cin >> x;
	for (i = 1; i < n; i++) {
		cin >> y;
		for (j = 0; j < y.size(); j++) {
			if (x[j]!='?' && x[j] != y[j]) {
				x[j] = '?';
			}
		}
	}
	cout << x;
}