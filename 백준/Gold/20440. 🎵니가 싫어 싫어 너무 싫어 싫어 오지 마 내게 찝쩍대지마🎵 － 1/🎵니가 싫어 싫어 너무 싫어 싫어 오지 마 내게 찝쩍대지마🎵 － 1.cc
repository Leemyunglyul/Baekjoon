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

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    int n, i, j, x, y;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x >> y;
        pq.push({ x, y });
    }
    int m = 0;
    int ts = 0; int te = 0;
    while (!pq.empty()) {
        int s = pq.top().first;
        int e = pq.top().second;
        pq.pop();

        if (q.empty()) {
            m = 1;
            ts = s;
            te = e;
            q.push(e);
            continue;
        }
        if (q.top() <= s) q.pop();

        q.push(e);
        if (m < q.size()) {
            m = q.size();
            ts = s;
            te = q.top();
        }
        else if (m == q.size() && s == te) {
            te = q.top();
        }
    }
    cout << m << endl << ts << " " << te;

    return 0;
}