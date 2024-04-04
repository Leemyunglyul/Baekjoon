#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, sum;
    cin >> x;
    sum = 0;
    while (x > 0) {
        if (x & 1) sum++;
        x = x >> 1;
    }
    cout << sum;
}