#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;

priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;

int food[200010];
ll kk;
int mint;
int n;

int solve() {
    int remain = n;
    int before = 0;

    while (!pq.empty()) {
        int now = pq.top().first;

        ll bar = 1LL * (now - before) * remain;

        if (bar > kk) {
            vector<int> rest;

            while (!pq.empty()) {
                rest.push_back(pq.top().second);
                pq.pop();
            }

            sort(rest.begin(), rest.end());

            return rest[kk % remain];
        }

        kk -= bar;
        before = now;

        while (!pq.empty() && pq.top().first == now) {
            pq.pop();
            remain--;
        }
    }

    return -1;
}

int solution(vector<int> food_times, long long k) {
    kk = k;
    n = food_times.size();
    mint = 987654321;

    while (!pq.empty()) {
        pq.pop();
    }

    for (int i = 0; i < n; i++) {
        food[i + 1] = food_times[i];
        pq.push({food[i + 1], i + 1});
        mint = min(food[i + 1], mint);
    }

    return solve();
}