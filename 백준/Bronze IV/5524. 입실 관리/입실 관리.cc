#include<iostream>
#include<math.h>
#include<string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x;
	int n, i;
	cin >> n;
	while (n--) {
		cin >> x;
		for (i = 0; i < x.size(); i++) x[i] = tolower(x[i]);
		cout << x << "\n";
	}
}