#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>

using namespace std;

set<string> listt;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i;
	cin >> n;
	string x, print;
	for (i = 0; i < n; i++) {
		cin >> x;
		string temp = x;
		reverse(temp.begin(), temp.end());
		if (listt.find(temp) != listt.end() || temp == x) {
			print = x;
		}
		listt.insert(x);
	}
	cout << print.size() << " " << print[(print.size() - 1)/2];
}