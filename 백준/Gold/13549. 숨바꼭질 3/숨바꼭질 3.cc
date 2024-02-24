#include<iostream>
#include<math.h>
#include<vector>
#include<deque>

using namespace std;

int arr[100100] = { 0 };
deque<int> pos;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, i, j, start, end, now, sum;
	cin >> start >> end;
	pos.push_front(start);
	arr[start] = 1;
	sum = 0;
	if (start == end||start*2==end) {
		cout << "0";
		return 0;
	}
	arr[end] = 100100;
	while (!pos.empty()) {
		now = pos.front();
		pos.pop_front();
		if (now * 2 == end) {
			arr[end] =min( arr[now], arr[end]);
		}
		else if (now * 2 <= 100000) {
			if (arr[now * 2] == 0) {
				pos.push_front(2 * now);
				arr[now * 2] = arr[now];
			}
		}
		if (now + 1 == end) {
			arr[end] = min(arr[now] + 1, arr[end]);
		}
		else if (now + 1 <= 100000) {
			if (arr[now + 1] == 0) {
				pos.push_back(now + 1);
				arr[now + 1] = arr[now] + 1;
			}
		}
		if (now - 1 == end) {
			arr[end] = min(arr[now] + 1, arr[end]);
		}
		else if (now - 1 >= 0) {
			if (arr[now - 1] == 0) {
				pos.push_back(now - 1);
				arr[now - 1] = arr[now] + 1;
			}
		}
	}
	cout << arr[end] - 1;
}