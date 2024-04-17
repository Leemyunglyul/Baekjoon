#include <iostream>
#include <cmath>
#include <set>

using namespace std;

bool arr[10];

bool check(int x) {
    if (x == 0) {
        return arr[0];
    }
    while (x > 0) {
        int temp = x % 10;
        if (!arr[temp]) return false;
        x = x / 10;
    }
    return true;
}

int count(int x) {
    int num = 0;
    if (x == 0) return 1;
    while (x > 0) {
        int temp = x % 10;
        x=x/10;
        num++;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, i, x, anw;
    cin >> m >> n;
    fill_n(&arr[0], 10, true);
    for (i = 1; i <= n; i++) {
        cin >> x;
        arr[x] = false;
    }
    anw = abs(m - 100);
    for (i = 0; i <= 1000000; i++) {
        if (check(i)) {
           // cout << i << endl;
            anw = min(anw, abs(m - i)+count(i));
        }
    }
    cout << anw;
    return 0;
}