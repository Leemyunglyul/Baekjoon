#include<iostream>
#include<math.h>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j;
	cin >> n;
	for (i = n; i >= 1; i--) {
		for (j = 0; j < i; j++) cout << "*";
		cout << "\n";
	}
}