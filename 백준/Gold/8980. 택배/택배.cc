#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef struct box{
	int len;
	int start;
	int num;
};
int vil[10100] = {0};
box b[10100];

bool cmp(const box& b1, const box& b2) {
	if (b1.len < b2.len) {
		return true;
	}
	else if (b1.len == b2.len) {
		if (b1.start < b2.start) return true;
		else if (b1.start == b2.start) {
			if (b1.num <= b2.num) return true;
		}
		return false;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cap, bn, x, y, z, i, sum, j, least;
	cin >> n >> cap>>bn;
	for (i = 0; i < bn; i++) {
		cin >> x >> y >> z;
		b[i].len = y - x;
		b[i].start = x;
		b[i].num = z;
	}
	sort(b, b + bn, cmp);
	for (i = 0, sum=0; i < bn; i++) {
		for (j = b[i].start, least = 100000; j < b[i].start + b[i].len; j++) {
			least = min(least, cap - vil[j]);
		}
		least = min(least, b[i].num);
		//cout << b[i].start <<" "<<b[i].start+b[i].len<<" "<<b[i].num << endl;
		if (least == 0) continue;
		for (j = b[i].start, sum+=least; j < b[i].start + b[i].len; j++) {
			vil[j] += least;
		}
	}
	cout << sum;
}