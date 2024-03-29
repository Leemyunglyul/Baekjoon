#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <cmath>
#define ll long long

using namespace std;

long long int dp[100100];
vector<pair<long long int, long long int>> edge[100100];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
long long int arr[100100];
long long int big = 987654321987654321;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int s, d, w, i, j, n, m, k;
    cin >> n >> m >> k;
    fill_n(&dp[0], 100100, big);
    for (i = 0; i < m; i++) {
        cin >> s >> d >> w;
        edge[s].push_back({ d, w });
        edge[d].push_back({ s, w });
    }
    int anw = -1;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] *= (k - 1);
        if (arr[i] > 0) anw = 1;
    }
    if (anw == -1) {
        cout << "-1";
        return 0;
    }
    dp[1] = 0;
    pq.push({ dp[1], 1 });
    while (!pq.empty()) {
        long long int cur = pq.top().second;
        long long int cost = pq.top().first;
        pq.pop();

        for (i = 0; i < edge[cur].size(); i++) {
            long long int nextt = edge[cur][i].first;
            long long int costt = edge[cur][i].second;
            if (dp[nextt] > costt + cost) {
                dp[nextt] = costt + cost;
                pq.push({ dp[nextt], nextt });
            }
        }
    }
    if (dp[n] == big) {
        cout << "-1";
        return 0;
    }
    for (i = 1; i <= n; i++) {
        if (arr[i] < 0) dp[i] = big;
        else {
            dp[i] += arr[i];
            pq.push({ dp[i], i });
        }
    }
    while (!pq.empty()) {
        long long int cur = pq.top().second;
        long long int cost = pq.top().first;
        pq.pop();
        for (i = 0; i < edge[cur].size(); i++) {
            long long int nextt = edge[cur][i].first;
            long long int costt = edge[cur][i].second;
            if (dp[nextt] > costt + cost) {
                dp[nextt] = costt + cost;
                pq.push({ dp[nextt], nextt });
            }
        }
    }
    cout << dp[n];
}