#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<long long int> print;

bool cmp(long long int a, long long int b) {
	string x = to_string(a);
	string y = to_string(b);
	string xy = x + y;
	string yx = y + x;
	return xy >= yx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int k, n, i, x, big, j;
	cin >> k >> n;
	for (i = 0, big=0; i < k; i++) {
		cin >> x;
		big = max(big, x);
		print.push_back(x);
	}
	for(i=0;i<n-k;i++) print.push_back(big);

	for (i = 1; i < print.size(); i++) {
		long long int temp = print[i];
		for (j = i-1; j>=0; j--) {
			if (!cmp(print[j], temp)) {
				print[j + 1] = print[j];
			}
			else break;
		}
		print[j + 1] = temp;
	}
	for (i = 0; i < print.size(); i++) cout << print[i];
}