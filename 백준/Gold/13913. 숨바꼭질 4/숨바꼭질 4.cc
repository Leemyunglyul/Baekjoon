#include<iostream>
#include<math.h>
#include<stack>
#include<queue>

using namespace std;

int arr[100100] = { 0 };
int pre[100100] = { 0 };
queue<int> pos;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testn, i, j, start, end, now, sum;
	cin >> start >> end;
	pos.push(start);
	arr[start] = 1;
	sum = 0;
	if (start == end) {
		cout << "0\n"<<start;
		return 0;
	}
	arr[end] = 100100;
	while (!pos.empty()) {
		now = pos.front();
		pos.pop();
		if (now * 2 == end || now+1==end || now-1==end) {
			arr[end] = arr[now];
			pre[end] = now;
			break;
		}
		if (now * 2 <= 100000 && arr[now * 2] == 0) {
			pos.push(2 * now);
			arr[now * 2] = arr[now]+1;
			pre[now * 2] = now;
		}
		if (now + 1 <= 100000 && arr[now + 1] == 0) {
			pos.push(now + 1);
			arr[now + 1] = arr[now] + 1;
			pre[now + 1] = now;
		}
		if (now - 1 >= 0 && arr[now - 1] == 0) {
			pos.push(now - 1);
			arr[now - 1] = arr[now] + 1;
			pre[now - 1] = now;
		}
	}
	int go = end;
	cout << arr[end]<<endl<<start;
	stack<int> st;
	while (go != start) {
		st.push(go);
		go = pre[go];
	}
	while (!st.empty()) {
		cout << " " << st.top();
		st.pop();
	}
	
}