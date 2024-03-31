#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[200100][2][2] = {0};
int track[200100];
bool go[200100][2][2];
ll len[200100];
ll b1, b2;

void check(string x, string y, int n) {
    //윗줄 출발
    int i, j, pos, leng;
    leng = x.size();
    if (x[0] == '#') {
        go[n][0][1] = false;
        go[n][0][0] = false;
    }
    if (y[0] == '#') {
        go[n][1][1] = false;
        go[n][1][0] = false;
    }
    if (x.back() == '#') {
        go[n][0][0] = false;
        go[n][1][0] = false;
    }
    if (y.back() == '#') {
        go[n][0][1] = false;
        go[n][1][1] = false;
    }
    for (i = 0; i < leng; i++) {
        if (x[i] == y[i] && y[i] == '#');
        else if (i < leng - 1 && x[i] == y[i + 1] && y[i + 1] == '#');
        else if (i < leng - 1 && x[i + 1] == y[i] && y[i] == '#');
        else continue;
        go[n][0][1] = false;
        go[n][0][0] = false;
        go[n][1][1] = false;
        go[n][1][0] = false;
        return;
    }
    ll sum;
    if(go[n][0][0]){
        for (i = 1, pos=0, sum=0; i < leng; i++) {
            if (pos == 0) {
                if (x[i] == '#') {
                    sum++;
                    pos = 1;
                }
            }
            else {
                if (y[i] == '#') {
                    sum++;
                    pos = 0;
                }
            }
        }
        if (pos == 1) {
            sum++;
        }
        arr[n][0][0] = sum;
    }
    if (go[n][1][1]) {
        for (i = 1, pos = 1, sum = 0; i < leng; i++) {
            if (pos == 0) {
                if (x[i] == '#') {
                    sum++;
                    pos = 1;
                }
            }
            else {
                if (y[i] == '#') {
                    sum++;
                    pos = 0;
                }
            }
        }
        if (pos == 0) {
            sum++;
        }
        arr[n][1][1] = sum;
    }
    if (go[n][0][1]) {
        for (i = 1, pos = 0, sum = 0; i < leng; i++) {
            if (pos == 0) {
                if (x[i] == '#') {
                    sum++;
                    pos = 1;
                }
            }
            else {
                if (y[i] == '#') {
                    sum++;
                    pos = 0;
                }
            }
        }
        if (pos == 0) {
            sum++;
        }
        arr[n][0][1] = sum;
    }
    if (go[n][1][0]) {
        for (i = 1, pos = 1, sum = 0; i < leng; i++) {
            if (pos == 0) {
                if (x[i] == '#') {
                    sum++;
                    pos = 1;
                }
            }
            else {
                if (y[i] == '#') {
                    sum++;
                    pos = 0;
                }
            }
        }
        if (pos == 1) {
            sum++;
        }
        arr[n][1][0] = sum;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll i, j, n, k;
    ll big = 987654321987;
    string x, y;
    cin >> n >> k;
    for (i = 1; i <= k; i++) {
        cin >> track[i];
    }
    fill_n(&go[0][0][0], 200100 * 2 * 2, true);
    for (i = 1; i <= n; i++) {
        cin >> x >> y;
        check(x, y, i);
        len[i] = x.size();
        //cout << arr[i][0][0] << endl;
        //cout << arr[i][0][1] << endl;
        //cout << arr[i][1][1] << endl;
        //cout << arr[i][1][0] << endl;
    }
    bool x1 = true;
    bool x2 = true;
    ll s1 = 0; ll s2 = 0;
    for (j = 1; j <= k; j++) {
        long long t1 = big;
        long long t2 = big;
        i = track[j];
        // cout << "&&&&&&&&&&&&\n";
        // cout << arr[i][0][0] << endl;
         //cout << arr[i][0][1] << endl;
         //cout << arr[i][1][1] << endl;
         //cout << arr[i][1][0] << endl;
         //cout << "&&&&&&&&&&&&\n\n";
        if (x1 && go[i][0][0]) {
            t1 = s1 + arr[i][0][0];
            if (x2 && go[i][1][0]) t1 = min(s2 + arr[i][1][0], t1);
        }
        else {
            if (x2 && go[i][1][0]) t1 = s2 + arr[i][1][0];
        }
        if (x1 && go[i][0][1]) {
            t2 = s1 + arr[i][0][1];
            if (x2 && go[i][1][1]) t2 = min(s2 + arr[i][1][1], t2);
        }
        else {
            if (x2 && go[i][1][1]) t2 = s2 + arr[i][1][1];
        }
        if (t1 == big) x1 = false;
        else {
            s1 = t1+len[i];
            x1 = true;
        }
        if (t2 == big) x2 = false;
        else {
            s2 = t2 + len[i];
            x2 = true;
        }
        //cout << j << "번째\n";
        //cout << "0번째 : " << x1 << "//sum"<<s1 << endl;
        //cout << "1번째 : " << x2 << "//sum" << s2 << endl;
        if (!x1 && !x2) {
            cout << "-1";
            return 0;
        }
    }
    if (x1 && x2) cout << min(s1, s2) - 1;
    else if (x1) cout << s1 - 1;
    else cout << s2 - 1;
}