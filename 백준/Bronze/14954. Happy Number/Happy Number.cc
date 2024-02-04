#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
vector<long long int> x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, i, temp, sum;
	cin >> n;
	x.push_back(n);
	while (1) {
		sum = 0;
		while (n > 0) {
			temp = n % 10;
			sum += temp * temp;
			n = n / 10;
		}
		if (sum == 1) {
			cout << "HAPPY";
			return 0;
		}
		for (i = 0; i < x.size(); i++) {
			if (sum ==x[i]) {
				cout << "UNHAPPY";
				return 0;
			}
		}
		x.push_back(sum);
		n = sum;
	}
}