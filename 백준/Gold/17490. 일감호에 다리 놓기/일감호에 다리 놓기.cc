#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

vector<pair<int, int>> miss;
vector<vector<int>> sep;
int arr[1001000];
vector<int> temp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, m, k, i, j, sum, x, y;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (i = 1; i <= m; i++) {
		cin >> x>>y;
		miss.push_back({ x,y });
	}
	if (m <= 1) {
		cout << "YES";
		return 0;
	}
	sort(miss.begin(), miss.end());
	miss.push_back({ miss[0].first, miss[0].second });
	for (i = 0; i <miss.size()-1; i++) {
		if (i == miss.size() - 2 && miss[i].second!=1) {
			for (j = miss[i].second; j <= n; j++) {
				temp.push_back(j);
			}
			for (j = 1; j <= miss[i+1].first; j++) {
				temp.push_back(j);
			}
		}
		else {
			for (j = miss[i].second; j <= miss[i + 1].first; j++) {
				temp.push_back(j);
			}
		}
		sep.push_back(temp);
		temp.clear();
	}
	for (i = 0, sum=0; i < miss.size() - 1; i++) {
		for (j = 0, x=1000000; j <sep[i].size(); j++) {
			x = min((long long int)arr[sep[i][j]], x);
		}
		sum += x;
	}
	if (sum <= k) cout << "YES";
	else cout << "NO";
}