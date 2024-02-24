#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int arr[100100] = { 0 };
queue<int> pos;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, i, j, start, end, x, y, now;
	cin >> start >> end;
	pos.push(start);
	arr[start] = 1;
	while (!pos.empty()) {
		now = pos.front();
		pos.pop();
		if (now == end) break;
		if (now + 1 <= 100000 && arr[now + 1] == 0 ) {
			pos.push(now + 1);
			arr[now + 1] = arr[now] + 1;
		}
		if ( now * 2 <= 100000 && arr[now * 2] == 0) {
			pos.push(2 * now);
			arr[now * 2] = arr[now] + 1;
		}
		if (now - 1 >= 0 && arr[now - 1] == 0) {
			pos.push(now - 1);
			arr[now - 1] = arr[now] + 1;
		}
	}
	cout << arr[end]-1;
}