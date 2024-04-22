#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

int n, m, k, t;
bool odd[1001000];
bool even[1001000];
queue<int> q;

void even_bfs() {
    int j;
    int x = q.size();
    while (x--) {
        int r = q.front();
        q.pop();
        if (r > 0 && !even[r - 1]) {
            q.push(r - 1);
            even[r - 1] = true;
        }
        if (r+1<=500000 && !even[r + 1]) {
            q.push(r + 1);
            even[r + 1] = true;
        }
        if (r>0 &&2*r<=500000 && !even[2*r]) {
            q.push(r*2);
            even[2*r] = true;
           // cout << 2 * r << endl;
        }
    }
}


void odd_bfs() {
    int j;
    int x = q.size();
    while (x--) {
        int r = q.front();
        q.pop();
        if (r > 0 && !odd[r - 1]) {
            q.push(r - 1);
            odd[r - 1] = true;
        }
        if (r + 1 <= 500000 && !odd[r + 1]) {
            q.push(r + 1);
            odd[r + 1] = true;
        }
        if (r>0 && 2 * r <= 500000 && !odd[2 * r]) {
            q.push(r * 2);
            odd[2 * r] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    if (n == m) {
        cout << "0";
        return 0;
    }
    int i, j, r, c;
    fill_n(&odd[0], 1001000, false);
    fill_n(&even[0], 1001000, false);
    even[n] = true;
    q.push(n);
    t = 0;
    while(1) {
        t++;
        m += t;
        if (m > 500000) {
            t = -1;
            break;
        }
        if (t % 2 == 1) {
            odd_bfs();
            if (odd[m]) break;
        }
        else {
            even_bfs();
            if (even[m]) break;
        }
    }
    cout << t;


    return 0;
}