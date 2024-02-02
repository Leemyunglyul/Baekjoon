#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, sum;
	string x;
	cin >> x;
	for (i = 0, sum = 0; i < x.size(); i++) {
		if (x[i] == 97 || x[i] == 101 || x[i] == 101 || x[i] == 105 || x[i] == 111 || x[i] == 117) sum++;
	}
	cout << sum;
}