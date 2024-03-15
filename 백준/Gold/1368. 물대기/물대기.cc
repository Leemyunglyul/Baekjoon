#include <iostream>
#include<cmath>
#include<queue>
#include<tuple>
#include<algorithm>
#include<vector>

using namespace std;

int vertex;
int w[310];
int dp[310][310];
int parent[310];
vector<pair<int, pair<int, int>>> v;


int find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}
bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> vertex;
    long long int x, y, i, sum, j, k, d;
    for (i = 1, sum=0; i <= vertex; i++) {
        cin >> w[i];
        v.push_back({ w[i], {0, i}});
    }
    for (i = 1; i <= vertex; i++) {
        for (j = 1; j <= vertex; j++) {
            cin >> dp[i][j];
        }
    }
    for (i = 1; i <= vertex; i++) {
        for (j = i+1; j <= vertex; j++) {
            v.push_back({ dp[i][j], {i, j} });
        }
    }
    for (j = 0; j <= vertex; j++) {
        parent[j] = j;
    }
    sort(v.begin(), v.end());
    for (k = 0,sum=0; k <v.size(); k++) {
        x = v[k].second.first;
        y = v[k].second.second;
        d = v[k].first;
        if (!sameparent(x, y)) {
            sum += d;
            uni(x, y);
        }
    }
    cout << sum;
}
