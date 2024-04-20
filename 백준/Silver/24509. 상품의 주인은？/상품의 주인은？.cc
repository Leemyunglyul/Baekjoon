#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

priority_queue<pair<int, int>> q1;
priority_queue<pair<int, int>> q2;
priority_queue<pair<int, int>> q3;
priority_queue<pair<int, int>> q4;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int a1, a2, a3, a4;
    int n, i, j, a, b, c, d, x;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x >> a >> b >> c >> d;
        q1.push({ a, -x });
        q2.push({ b, -x });
        q3.push({ c, -x });
        q4.push({ d, -x });
    }
    a1 = -q1.top().second;
    if (q2.top().second == -a1) q2.pop();
    a2 = -q2.top().second;
    if (q3.top().second == -a1) q3.pop();
    if (q3.top().second == -a2) q3.pop();
    a3 = -q3.top().second;
    if (q4.top().second == -a1) q4.pop();
    if (q4.top().second == -a2) q4.pop();
    if (q4.top().second == -a3) q4.pop();
    a4 = -q4.top().second;
    cout << a1 << " " << a2 << " " << a3 << " " << a4;

    return 0;
}