#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x;
	char c;
	getline(cin, x);
	int i, s1, s2, sp;
	for (i = 0, s1 = 0, s2=0,sp=0; i < x.size(); i++) {
		if ((x[i] >= 104 && x[i] <= 112) || x[i] == 117) s2++;
		else if (x[i] >= 97 && x[i] <= 122) s1++;
		else if (x[i] == 32) sp++;
		else {
			c = x[i]+32;
			sp++;
			if ((c >= 104 && c <= 112) || c == 117) s2++;
			else if (c >= 97 && c <= 122) s1++;
		}
	}
	for (i = 0; i < sp; i++) {
		if (s1 < s2) s1++;
		else if (s1 > s2)s2++;
		else s1++;
	}
	cout << s1 << " " << s2;
}