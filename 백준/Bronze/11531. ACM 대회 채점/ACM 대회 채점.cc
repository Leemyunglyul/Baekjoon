#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include<queue>
//#include<deque>
//#include<string.h>
#include<math.h>
#include<cmath>
#include<map>
#include<algorithm>
//#include<functional>

using namespace std;

map<char, int> board;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	char q;
	string cond;
	int sum, num, time;
	num = 0;
	sum = 0;
	while (1) {
		cin >> time;
		if (time == -1) {
			cout << num << " " << sum;
			return 0;
		}
		cin >> q >> cond;
		if (board.find(q) == board.end()) {
			if (cond == "wrong") {
				board.insert({ q, 1 });
			}
			else {
				num++;
				sum += time;
			}
		}
		else {
			if (cond == "wrong") {
				board[q]++;
			}
			else {
				num++;
				sum += time + board[q] * 20;
				board.erase(q);
			}
		}

	}
	
}