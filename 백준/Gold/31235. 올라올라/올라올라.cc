#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, x, big, ind, mind;
    cin >> n;
    cin >> big;
    ind = 1;
    for (i = 2, mind=1; i <= n; i++) {
        cin >> x;
        if (big <= x) {
            mind = max(ind, mind);
            ind = 1;
            big = x;
        }
        else {
            ind++;
        }
    }
    mind = max(ind, mind);
    cout << mind;

}
