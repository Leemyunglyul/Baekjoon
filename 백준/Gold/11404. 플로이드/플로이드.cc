#include<iostream>
#include<math.h>

using namespace std;
int inf = 100000000;
int city[110][110];
int n;

void floyd() {
	int m, s, e;
	for (m = 1; m <= n; m++) {
		for (s = 1; s <= n; s++) {
			for (e = 1; e <= n; e++) {
				if (city[s][e] > city[s][m] + city[m][e]) {
					city[s][e] = city[s][m] + city[m][e];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, c1, c2, dis, bus;
	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			if (i == j) city[i][j] = 0;
			else city[i][j] = inf;
		}
	}
	cin >> n >> bus;
	for (i = 0; i < bus; i++) {
		cin >> c1 >> c2 >> dis;
		city[c1][c2] = min(city[c1][c2], dis);
	}
	floyd();
	for (i = 1; i <=n; i++) {
		for (j = 1; j <= n; j++) {
			if(city[i][j]==inf) cout << "0" << " ";
			else cout << city[i][j] << " ";
		}
		cout << "\n";
	}
}