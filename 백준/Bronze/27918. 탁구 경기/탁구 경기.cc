#include <iostream>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int p1 = 0;
    int p2 = 0;
    int n, i;
    char x;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x;
        if (abs(p1 - p2) >= 2) continue;
        if (x == 'D') p1++;
        else p2++;
    }
    cout << p1 << ":" << p2;
}
