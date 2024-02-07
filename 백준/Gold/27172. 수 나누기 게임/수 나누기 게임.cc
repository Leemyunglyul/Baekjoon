#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int score[100100] = { 0 };
int card[100100] = { 0 };
int rev[1000010] = { 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, n, j;
	cin >> n;
	for (i = 1;i<=n; i++) {
		cin >> card[i];
		rev[card[i]] = i;
	}
	for (i = 1; i <= n ; i++) {
		for (j = 1; j <= round(sqrt(card[i])); j++) {
			if (j == 1) {
				if (rev[1] != 0) {
					score[i]--;
					score[rev[1]]++;
				}
				continue;
			}
			if (card[i] % j == 0) {
				if (rev[j] != 0) {
					score[i]--;
					score[rev[j]]++;
				}
				if (j!=card[i]/j && rev[card[i] / j] != 0) {
					score[i]--;
					score[rev[card[i]/j]]++;
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		cout << score[i] << " ";
	}
}