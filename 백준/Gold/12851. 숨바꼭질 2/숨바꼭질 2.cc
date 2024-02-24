#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

int arr[100100] = { 0 };
int way[100100] = { 0 };
queue<int> pos;

void put(int input, int now) {
	if (arr[input] == 0) {
		pos.push(input);
		arr[input] = arr[now] + 1;
	}
	if (arr[input] == arr[now] + 1) way[input] += way[now];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, i, j, start, end, now, sum;
	cin >> start >> end;
	pos.push(start);
	arr[start] = 1;
	way[start] = 1;
	sum = 0;
	if (start == end) {
		cout << "0\n1";
		return 0;
	}
	while (!pos.empty()) {
		now = pos.front();
		pos.pop();
		if (sum > 0 && arr[end] < arr[now] + 1) continue;
		if (now + 1 == end || now * 2 == end || now - 1 == end) {
			if (arr[end] == 0) arr[end] = arr[now] + 1;
			if(arr[end] == arr[now] + 1) sum += way[now];
			continue;
		}
		if (now + 1 <= 100000) put(now + 1, now);
		if (now * 2 <= 100000) put(2 * now, now);
		if (now - 1 >= 0) put(now - 1, now);
	}
	cout << arr[end]-1<<endl<<sum;
}