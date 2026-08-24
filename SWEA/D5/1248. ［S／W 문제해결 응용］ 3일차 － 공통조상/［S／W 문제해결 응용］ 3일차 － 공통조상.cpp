#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef pair<int, int> p;
 
vector<int> adj[10001];
int n, parent[10001], level[10001];
 
int lca(int a, int b) {
    //a를 더 level이 높은 정점으로 맞춘다.
    if (level[a] < level[b]) swap(a, b);
 
    //두 정점의 level을 같게 만들기
    while (level[a] != level[b]) {
        a = parent[a];
    }
 
    //가리키는 정점이 같아질 때까지 거슬러 올라가기
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
 
    return a;
}
 
void set_tree(int node, int pnode) {
    //DFS로 트리 구성
    parent[node] = pnode;
    level[node] = level[pnode] + 1;
 
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (child == pnode) continue;
 
        set_tree(child, node);
    }
}

int subtree_size(int node) {
    int size = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (child == parent[node]) continue;

        size += subtree_size(child);
    }
    return size;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);


	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
       
        int v, e, f, s, a, b;
        cin >> v >> e >> f >> s;
        for (int i = 0; i <= v; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        set_tree(1, 0);

        int l = lca(f, s);
        cout << "#" << test_case << " " << l << " " << subtree_size(l) << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}