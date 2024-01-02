#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };
int result[100001];
int cnt = 0;

void bfs(int r) {
	queue<int> q;
	q.push(r); // 큐에 노드를 집어넣는다
	visited[r] = 1; // 처음 방문한 곳 표시
	cnt++; // 처음 방문한 곳 카운트 + 1
	result[r] = cnt; // 처음으로 방문 cnt == 1
	while (!q.empty()) {
		int inq = q.front(); // 큐에 첫번째 원소 저장

		q.pop(); // 제거

		for (int i = 0; i < graph[inq].size(); i++) { // 노드에 연결된 크기만큼 반복
			int temp = graph[inq][i]; // 
			if (!visited[temp]) { // 노드에 연결된 노드가 방문하지 않은 곳이면
				cnt++;
				result[temp] = cnt;
				q.push(temp); // 큐에 넣고
				visited[temp] = 1; // 방문처리
			}
		}
	}
}
int main() {
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b); // (1,4) (1,2) (2,3) (2,4) (3,4)
		graph[b].push_back(a); // (4,1) (2,1) (3,2) (4,2) (4,3)	
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	bfs(r);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}

}