#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

vector <pair<int, int>> q;
vector <long long int> anw;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, i, j, x, y, k;
	double x1, x2;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		q.push_back({x, y});
	}
	for (i = 0; i < n-2; i++) {
		for (j = i+1; j < n - 1; j++) {
			if (q[i].first == q[j].first) x1 = 1000000;
			else x1 = double(q[i].second - q[j].second) / double(q[i].first - q[j].first);
			for (k = j + 1; k < n; k++) {
				if (q[i].first == q[k].first) x2 = 1000000;
				else x2= double(q[i].second - q[k].second) / double(q[i].first - q[k].first);
				if (x1 == x2) anw.push_back(i * 1000000 + j * 1000 + k);
			}
		}
	}
	if (anw.size() == 0) return 0;
	cout << anw.size() << endl;
	for (i = 0; i < anw.size(); i++) {
		cout << (anw[i] / 1000000)+1 << " ";
		anw[i] = anw[i] - (anw[i] / 1000000) * 1000000;
		cout << (anw[i] / 1000)+1 << " ";
		anw[i]= anw[i] - (anw[i] / 1000) * 1000;
		cout << anw[i]+1 << endl;
	}
}