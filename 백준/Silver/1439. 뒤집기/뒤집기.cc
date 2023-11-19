#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
//#include <queue>
//#include <deque>
//#include <algorithm>

using namespace std;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, n, m;
	n = 0;
	m = 0;
	cin >> s;
	if (s[0] == '0') n++;
	else m++;
	for (i = 1; i < s.size(); i++) {
		if (s[i - 1] == '1' && s[i] == '0')n++;
		else if (s[i - 1] == '0' && s[i] == '1')m++;
	}
	cout << min(n, m);
}