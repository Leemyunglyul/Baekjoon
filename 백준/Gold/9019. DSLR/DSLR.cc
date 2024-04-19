#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int s, e;
int pre[10010];
queue<int> q;

int dd(int x) {
    int anw = 2 * x;
    if (anw > 9999) {
        return anw % 10000;
    }
    else return anw;
}

int subs(int x) {
    if (x == 0) return 9999;
    else return x - 1;
}

int left(int x) {
    int d1 = x / 1000;
    int d2 = (x % 1000) / 100;
    int d3 = (x % 100) / 10;
    int d4 = x % 10;

    return 1000 * d2 + 100 * d3 + 10 * d4 + d1;
}

int right(int x) {
    int d1 = x / 1000;
    int d2 = (x % 1000) / 100;
    int d3 = (x % 100) / 10;
    int d4 = x % 10;

    return 1000 * d4 + 100 * d1 + 10 * d2 + d3;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, x, y, i;
    cin >> testn;
    while (testn--) {
        cin >> s >> e;
        fill_n(&pre[0], 10010, -1);
        q.push(s);
        pre[s] = s;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (t == e) break;

            x = dd(t);
            if (pre[x] == -1) {
                pre[x] = t;
                q.push(x);
            }
            x = subs(t);
            if (pre[x] == -1) {
                pre[x] = t;
                q.push(x);
            }
            x = left(t);
            if (pre[x] == -1) {
                pre[x] = t;
                q.push(x);
            }
            x = right(t);
            if (pre[x] == -1) {
                pre[x] = t;
                q.push(x);
            }
        }
        while (!q.empty()) q.pop();
        x = e;
        vector<char> v;
        while (x != s) {
            y = pre[x];
            if (dd(y) == x) {
                v.push_back('D');
            }
            else if (subs(y) == x) {
                v.push_back('S');
            }
            else if (left(y) == x) {
                v.push_back('L');
            }
            else if (right(y) == x) {
                v.push_back('R');
            }
            x = y;
        }
        for (i = v.size()-1; i >= 0; i--) {
            cout << v[i];
        }
        cout << "\n";
    }
}