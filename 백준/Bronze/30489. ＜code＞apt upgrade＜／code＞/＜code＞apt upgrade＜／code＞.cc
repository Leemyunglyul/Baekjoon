#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

vector<long long int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int a, b, c, data, i, sum, son;
	double x;
	cin >> a >> b >> c;
	for (i = 0, sum=0, son=0; i < a; i++) {
		cin >> data;
		v.push_back(data);
		sum += data;
	}
	sort(v.begin(), v.end(), greater<int>());
	if (b + c >= a) cout << "100";
	else {
		for (i = 0; i < b + c; i++) {
			son += v[i];
		}
		x = double(son) / sum * 100;
		cout << fixed;
		cout.precision(8);
		cout << x;
	}
}