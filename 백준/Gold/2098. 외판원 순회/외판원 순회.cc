#include <iostream>
#include<cmath>
#include<cstring>

#define INF 987654321

using namespace std;

int n, anw;
int map[16][16];
int cost[16][1 << 16];

int dfs(int cur_node, int cur_bit) {
    if (cur_bit == anw) {//모든 곳을 방문했을 때
        if (map[cur_node][0] == 0) return INF;//출발 지점으로 못 갈 때
        else return map[cur_node][0];//출발 지점으로 갈 수 있을 때
    }

    //이미 탐색했을 때
    if (cost[cur_node][cur_bit] != -1) return cost[cur_node][cur_bit];
    //아닐 때
    cost[cur_node][cur_bit] = INF;
    for (int i = 0; i < n; i++) {
        //i로 갈 수 없을 때
        if (map[cur_node][i] == 0) continue;
        //이미 들른 곳일 경우
        if ((cur_bit & (1 << i)) == (1 << i)) continue;

        //cur_node->출발지점 vs cur_node->i>출발지점
        cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit], map[cur_node][i] + dfs(i, cur_bit | 1 << i));
        
    }
    return cost[cur_node][cur_bit];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    anw = (1 << n) - 1;//모든 곳을 방문했을 때
    memset(cost, -1, sizeof(cost));//초기화
    cout << dfs(0, 1);
}
