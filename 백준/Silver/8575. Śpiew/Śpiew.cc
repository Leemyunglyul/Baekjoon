#include<iostream>
#include<math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, sum, n, k;
	string x;
	cin >> n >> x;
	for (i = 0, sum=0;i<n;i++) {
		if (x[i] == 'W') continue;
		k = 0;
		while (x[i] == 'Z') {
			k++;
			i++;
		}
		sum += (k + 2) / 3;
	}
	cout << sum;
}