#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<long long int> s1;
vector<long long int> s2;
map<long long int, long long int> mp;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int x, t, i, n, m, j, e1, e2, mid, sum;
	cin >> t >> n;
	s1.push_back(0);
	s2.push_back(0);
	for (i = 1; i <= n; i++) {
		cin >> x;
		s1.push_back(x + s1[i - 1]);
	}
	cin >> m;
	for (i = 1; i <= m; i++) {
		cin >> x;
		s2.push_back(x + s2[i - 1]);
	}
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			s1.push_back(s1[j] - s1[i]);
		}
	}
	for (i = 0; i <= m; i++) {
		for (j = i + 1; j <= m; j++) {
			mp[s2[j] - s2[i]]++;
		}
	}
	for (i = 1, sum=0; i < s1.size(); i++) {
		sum += mp[t-s1[i]];
	}
	cout << sum;
}