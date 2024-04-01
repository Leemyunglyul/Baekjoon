#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
long long fox[100010];
long long wolf[100010][2];
vector<pair<int, int>> edge[100010];
priority_queue<pair<int, int>> pq;
priority_queue<tuple<long long, int, bool>> pq2;
int n, m;
long long big = 987654321987;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    long long i, j, s,d, w;
    for (i = 0; i < m; i++) {
        cin >> s >> d >> w;
        edge[s].push_back({ d, 2*w });
        edge[d].push_back({ s, 2*w });
    }
    fill_n(&fox[0], n + 5, big);
    fill_n(&wolf[0][0], (n + 3)*2, big);
    //여우
    fox[1] = 0;
    pq.push({ fox[1], 1 });
    while (!pq.empty()) {
        long long cur = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        
        if(fox[cur]!=cost) continue;

        for (i = 0; i < edge[cur].size(); i++) {
            long long nextt = edge[cur][i].first;
            long long costt = edge[cur][i].second;

            if (fox[nextt] > cost + costt) {
                fox[nextt] = cost + costt;
                pq.push({ -fox[nextt], nextt });
            }
        }
    }
    //늑대
    pq2.push({ 0, 1, 1});
    while (!pq2.empty()) {
        long long cur = get<1>(pq2.top());
        long long cost = -get<0>(pq2.top());
        bool speed = get<2>(pq2.top());
        pq2.pop();
        if (cur!=1 && wolf[cur][!speed] != cost) continue;

        for (i = 0; i < edge[cur].size(); i++) {
            long long nextt = edge[cur][i].first;
            long long costt = edge[cur][i].second;
            if (speed) costt /= 2;
            else costt *= 2;

            if (wolf[nextt][speed] > cost + costt) {
                wolf[nextt][speed] = cost + costt;
                pq2.push({ -wolf[nextt][speed], nextt, !speed});
                //cout << speed << endl;
            }
        }
    }
    int sum = 0;
    for (i = 2; i <= n; i++) {
        if ( fox[i] < wolf[i][0] && fox[i]<wolf[i][1]) sum++;
        //cout << i << "번째" << endl;
        //cout << double(fox[i]) << " " << double(wolf[i][0]) <<"+"<< double(wolf[i][1]) << endl;
    }
    cout << sum;

}