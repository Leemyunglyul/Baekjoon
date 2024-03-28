#include <iostream>
#include <cmath>

using namespace std;

long long check(int x) {
    long long ini = 10000000000;
    while (!(x >= ini / 10 && x < ini)) {
        ini /= 10;
    }
    return ini;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long testn, n, i, x;
    cin >> testn;
    while (testn--) {
        cin >> x;
        n = check(x);
        if (x >= n / 2) {
            x = n / 2;
        }
        cout << (n - 1) * x - x * x << "\n";
    }
}