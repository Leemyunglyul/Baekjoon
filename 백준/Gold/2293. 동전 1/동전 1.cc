#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int arr[10001] = {0};
int coin[100];

int main() {
	int n, k, i, p;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (i = 0; i < n; i++) {
		p = 1;
		while (p <= k) {
			if (p == coin[i])
				arr[p]++;
			if(p>coin[i]) {
				arr[p] += arr[p - coin[i]];
			}
			p++;
		}
	}
	cout << arr[k];
}