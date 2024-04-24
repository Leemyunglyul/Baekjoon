#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
#include <set>

using namespace std;

int arr[5100][2];
int big = 987654321;
vector<int> con;
vector<pair<int,int>> edge[5100];
priority_queue<tuple<int,int,int>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, j, x, y, d, p, q;
    cin >> n >> m;

    fill_n(&arr[0][0], 5100*2, big);
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        edge[x].push_back({ y, d });
        edge[y].push_back({ x, d });
    }
    cin >> p >> q;
    for (i = 1; i <= p; i++) {
        cin >> x;
        pq.push({ -0,x,x });
        arr[x][0] = 0;
        arr[x][1] = x;
    }
    for (i = 1; i <= q; i++) {
        cin >> y;
        con.push_back(y);
    }
   while (!pq.empty()) {
        int now = get<1>(pq.top());
        int cost = -get<0>(pq.top());
        int s=get<2>(pq.top());
        pq.pop();
        if (arr[now][0] != cost || arr[now][1]!=s) continue;

        for (j = 0; j < edge[now].size(); j++) {
            int nextt = edge[now][j].first;
            int costt = edge[now][j].second;
            if (arr[nextt][0] > cost + costt 
               ||(arr[nextt][0]==cost+costt && arr[nextt][1]>s)) {
                arr[nextt][0] = cost + costt;
                arr[nextt][1] = s;
                pq.push({ -arr[nextt][0], nextt, s });
            }
        }
    }
    int anw = 0;
    int dd = big;
    for (i = 0; i < con.size(); i++) {
        if (dd > arr[con[i]][0]) {
            dd = arr[con[i]][0];
            anw= arr[con[i]][1];
        }
        else if (dd == arr[con[i]][0] && anw>arr[con[i]][1]) {
            dd = arr[con[i]][0];
            anw = arr[con[i]][1];
        }
    }
    cout << anw;
    return 0;
}