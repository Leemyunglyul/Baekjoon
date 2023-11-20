#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
//#include <string>
#include <cmath>
//#include <queue>
#include <deque>
//#include <algorithm>

using namespace std;
int arr[100010] = {0};
int mem[100010][2];
int cmd[100010];
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tn;
	cin >> tn;
	
	
	while (tn--) {
		int  i, j, len, arrn, dn, fb, m10;
		string s, input;
		cin >> input>>len>>s;
		for (i = 0, dn=0; i < input.size(); i++) {
			if (input[i] == 'R') {
				cmd[i] = 1;
			}
			else if (input[i] == 'D') {
				cmd[i] = 0;
				dn++;
			}
			else {
				cout << "error\n";
				continue;
			}
		}
		if (s[0] != '[' || s[s.size() - 1] != ']') {
			cout << "error\n";
			continue;
		}
		for (i = 1, arrn = 0; i < s.size() - 1; i++) {
			for (j = i; s[j] != ','; j++) {
				if (s[j] == ']')break;
			}
			if (i == j) {
				arrn = -1;
				break;
			}
			mem[arrn][0] = i;
			mem[arrn++][1] = j - 1;
			i = j;
		}
		if (arrn == -1|| arrn < dn || len!=arrn) {
			cout << "error\n";
			continue;
		}
		for (i = 0; i < arrn; i++) {
			arr[i] = 0;
			for (j = mem[i][1], m10 = 1; j >= mem[i][0]; j--,m10*=10) {
				arr[i] += (s[j] - 48) * m10;
			}
		}
		for (i = 0; i < len; i++) {
			dq.push_back(arr[i]);
		}
		for (i = 0, fb=0; i < input.size(); i++) {
			if (cmd[i] == 1 && fb==0) {
				fb = 1;
			}
			else if (cmd[i] == 1 && fb == 1) {
				fb = 0;
			}
			else {
				if (fb == 0) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		cout << '[';
		if (dq.size() == 0) {
			cout << ']' << endl;
			continue;
		}
		if (fb == 0) {
			while (dq.size() > 1) {
				cout << dq.front() << ",";
				dq.pop_front();
			}
			cout << dq.front() << ']' << endl;
			dq.pop_front();
		}
		else {
			while (dq.size()>1) {
				cout << dq.back() << ",";
				dq.pop_back();
			}
			cout << dq.back() << ']' << endl;
			dq.pop_back();
		}
	}
}