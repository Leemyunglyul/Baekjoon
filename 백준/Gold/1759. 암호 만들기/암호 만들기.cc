#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> a;
int n, k;
int arr[16];
char pw[17];

int check() {
	int i, a, b;
	for (i = 0, a = 0, b = 0; i < k; i++) {
		if (pw[i] == 97 || pw[i] == 101 || pw[i] == 105 || pw[i] == 111 || pw[i] == 117) {
			a++;
		}
		else b++;
	}
	if (a >= 1 && b >= 2) return 1;
	else return 0;
}

void print(int x, int y) {
	if (x == k) {
		if(check()==1) cout << pw << endl;
		return;
	}
	int i;
	for (i = y; i < n; i++) {
		pw[x] = arr[i] + 97;
		print(x + 1, i + 1);
	}
	return;
}

int main() {
	int sum, i;
	char word;
	cin >> k>>n;
	for (i = 0; i < n; i++) {
		cin >> word;
		a.push(word - 97);
	}
	for (i = 0; i < n; i++) {
		arr[i] = a.top();
		a.pop();
	}
	print(0, 0);
}