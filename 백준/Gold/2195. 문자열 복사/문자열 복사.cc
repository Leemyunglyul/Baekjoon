#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x, y;
	cin >> x >> y;
	int i, j, sum, k, max_len, temp;
	for (i = 0, sum = 0; i < y.size();) {
		int max_len = 0;
		for (j = 0; j < x.size(); j++) {
			temp = 0;
			while (x[j + temp] == y[i + temp]) temp++;
			max_len = max(temp, max_len);
		}
		i += max_len;
		sum++;
	}
	cout << sum;
}