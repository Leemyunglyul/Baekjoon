#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int arr[110][110] = { 0 };
int row , col, r, c, k;

int sort1(int Row) {
	int i;
	map<int, int> list;
	map<int, int>::iterator it;

	for (i = 1; i <= col; i++) {
		if (arr[Row][i] == 0) continue;
		if (list.find(arr[Row][i]) != list.end()) {
			list[arr[Row][i]]++;
		}
		else list.insert({ arr[Row][i], 1 });
		arr[Row][i] = 0;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	for (it = list.begin(); it != list.end(); it++)pq.push({ it->second, it->first });

	int pre = 1;
	int len = pq.size()*2;
	//cout << len << endl;

	while (!pq.empty() && pre+1<=100) {
		int x2 = pq.top().first;
		int x1 = pq.top().second;
		pq.pop();

		arr[Row][pre++] = x1;
		arr[Row][pre++] = x2;
	}
	return len;
}

int sort2(int Col) {
	int i;
	map<int, int> list;
	map<int, int>::iterator it;

	for (i = 1; i <= row; i++) {
		if (arr[i][Col] == 0) continue;
		if (list.find(arr[i][Col]) != list.end()) {
			list[arr[i][Col]]++;
		}
		else list.insert({ arr[i][Col], 1 });
		arr[i][Col] = 0;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	for (it = list.begin(); it != list.end(); it++) pq.push({it->second, it->first});

	int pre = 1;
	int len = pq.size()*2;

	while (!pq.empty() && pre + 1 <= 100) {
		int x2 = pq.top().first;
		int x1 = pq.top().second;
		pq.pop();

		arr[pre++][Col] = x1;
		arr[pre++][Col] = x2;
	}
	return len;
}


void print() {
	int i, j;
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int op() {
	int t = 0;
	int i, j;
	int xx = 0;
	while (t<=100) {
		xx = 0;
		if (arr[r][c] == k) return t;
		if (row >= col) {
			for (i = 1; i <= row; i++) xx = max(xx, sort1(i));
			col = xx;
		}
		else {
			for (i = 1; i <= col; i++) xx = max(xx, sort2(i));
			row = xx;
		}
		
		t++;
		//cout << t << "번째" << endl;
		//print();
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> k;
	int i, j;
	row = 3;
	col = 3;
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	cout << op();
}