#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	string x;
	string y;
	cin >> x >> y;
	if (x.size()>=y.size()) cout << "go";
	else cout << "no";
}