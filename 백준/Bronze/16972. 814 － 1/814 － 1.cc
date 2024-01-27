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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i, j, r, c, s;
	r = -8140;
	c = -8140;
	
	
	for (i = 0, s=1; i < 29; i++) {
		r += 561;
		for (j = 0, c=-8140; j < 29; j++, s++) {
			if (i == 0 && j == 0);
			else if (i == 0&& j==1) c += 560;
			else {
				c += 561;
			}
			cout << r << " " << c << endl;
			if (s == 814) break;
		}
		if (s == 814) break;
	}
}