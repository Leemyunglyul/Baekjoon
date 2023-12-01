#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
//#include <queue>
//#include <stack>
#include <algorithm>
#include <map>
//#include <set>

using namespace std;
map<long long int, long long int> mem;
long long int n, p, q;

long long int rec(long long int a) {
	//cout << a << endl;
	if (a == 0) return 1;

	if (mem.find(a) != mem.end()) return mem[a];
	else {
		mem[a]=rec(a / p)+rec(a / q);
		return mem[a];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> p >> q;
	mem[0] = 1;
	cout<<rec(n);
}