#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<set>
#include<algorithm>
//#include<functional>

using namespace std;
vector<char> st;
set<string> s;
set<string>::iterator it;
vector<string> whole;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c, d, testn, u, v, sum;
	double ui, vi;
	cin >> a >> b >> c >> d;
	cin >> testn;
	sum = 0;
	while (testn--) {
		cin >> u >> v;
		ui = sqrt(double(u-c)/a)+b;
		if (ui == double(v)) sum++;
	}
	cout << sum;
}