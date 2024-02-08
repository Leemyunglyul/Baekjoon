#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	string x, y;
	getline(cin, x);
	getline(cin, y);
	int i, j, sum;
	for (i = 0, sum=0; i < x.size(); i++) {
		if (x[i] == y[0]) {
			for (j = 1; j < y.size(); j++) {
				if (x[i + j] != y[j]) break;
			}
			if (j == y.size()) {
				i = i + y.size() - 1;
				sum++;
			}
		}
	}
	cout << sum;
}