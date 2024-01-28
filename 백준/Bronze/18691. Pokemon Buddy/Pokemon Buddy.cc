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

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, g, c, e;
	cin >> n;
	while (n--) {
		cin >> g >> c >> e;
		if (c >= e) cout << "0" << endl;
		else cout<<(e - c)* (2 * g - 1)<<endl;
	}
}