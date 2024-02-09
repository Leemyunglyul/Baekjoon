#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, a, b, i, j, x, y;
	string xs;
	cin >> testn;
	while (testn--) {
		/*for (i = 1; i <= 3; i++) {
			for (j = 1; j <= 3; j++) {
				b1[i][j] = 0;
				b2[i][j] = 0;
			}
		}*/
		cin >> a;
		for (i = 0; i < a; i++) {
			cin >> x >> y;
		}
		cin >> b;
		for (i = 0; i < b; i++) {
			cin >> x >> y;
		}
		if (a != b) {
			cout << "no\n";
		}
		else cout << "yes\n";
		
	}
}
