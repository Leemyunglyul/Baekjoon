#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
priority_queue<pair<int, int>> pq;
vector<int> print;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int n, k, i, x, num;
	cin >> n >> k;
	for (i = 1; i <= k; i++) {
		cin >> x;
		pq.push({ x, i });
	}
	while (!pq.empty()) {
		num = pq.top().first;
		x = pq.top().second;
		pq.pop();
		if (print.empty()) {
			print.push_back(x);
			if(num>1) pq.push({ num-1, x });
			continue;
		}
		pair<int, int> temp;
		if (print.back() == x) {//겹칠 경우
			if (pq.empty()) {//예외처리
				cout << "-1";
				return 0;
			}
			temp = pq.top();//안 겹치는 걸로 다시 빼오기
			pq.pop();
			pq.push({ num, x });//겹치는 건 다시 넣고
			print.push_back(temp.second);
			if (temp.first > 1) pq.push({ temp.first - 1, temp.second });
		}
		else {
			print.push_back(x);
			if (num > 1) pq.push({ num - 1, x });
		}
	}
	for (i = 0; i < print.size(); i++) {
		cout << print[i] << " ";
	}
}