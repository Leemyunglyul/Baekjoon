#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

priority_queue<long long> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long m, d, n, i, now, x, num, temp, dis, least;
    cin >> m >> d >> n;
    for (now = 0, i = 0, num=0, least=0; i < n; i++) {
        cin >> x;
        if (abs(least - (m-d)) > abs(x - (m-d)) && x>=m-d) {
            least = x;
        }
        pq.push(x);
    }
    while (!pq.empty() && now < d) {
        if (least == pq.top()) {
            pq.pop();
            continue;
        }
        x = pq.top();
        pq.pop();
        dis = d - now;
        x -= dis;
        if (x <= 0) {
            if ((least - dis) + now >= m) {
                cout << num + 1;
                return 0;
            }
            cout << "0";
            return 0;
        }
        now += x;
        num++;
    }
    if (now <m && least + d < m) {
        cout << "0";
    }
    else {
        if (now >= m) cout << num;
        else cout << num+1;
    }
}