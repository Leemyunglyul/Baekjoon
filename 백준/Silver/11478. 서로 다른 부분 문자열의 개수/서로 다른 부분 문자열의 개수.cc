#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
//#include <stack>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
map<string, int> m1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x, temp;
	cin >> x;
	int i, j, sum;
	for (i = 0; i < x.size(); i++) {
		for (j = i; j < x.size(); j++) {
			temp = x.substr(i, j-i+1);
			if(m1.find(temp)==m1.end())m1[temp] = 1;
		}
	}
	cout << m1.size() << endl;
}