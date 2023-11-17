#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef struct box {
	int end;
	int start;
	int num;
}Box;
int vil[4000] = { 0 };
box b[10200];

bool cmp(const box& b1, const box& b2) {
	if (b1.end == b2.end) return b1.start < b2.start;
	else return b1.end < b2.end;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, cap, bn, x, y, z, i, sum, j, least;
	cin >> n >> cap >> bn;
	for (i = 0; i < bn; i++) {
		cin >> x >> y >> z;
		b[i].end = y;
		b[i].start = x;
		b[i].num = z;
	}
	sort(b, b + bn, cmp);
	for (i = 0, sum = 0; i < bn; i++) {
		for (j = b[i].start, least=0; j < b[i].end; j++) {
			least = max(least, vil[j]);
		}
		least = min(b[i].num, cap - least);
		//cout << b[i].start <<" "<<b[i].start+b[i].len<<" "<<b[i].num << endl;
		if (least == 0) continue;
		for (j = b[i].start, sum += least; j < b[i].end; j++) {
			vil[j] += least;
		}
	}
	cout << sum;
}