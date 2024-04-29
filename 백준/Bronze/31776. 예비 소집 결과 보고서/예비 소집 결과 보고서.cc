#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, i, j, x, y, z, sum;
    cin >> n;
    sum = 0;
    while (n--) {
        cin >> x >> y >> z;
        if (x == -1) {
            continue;
        }
        else {
            if (y == -1) {
                if (z == -1) {
                    sum++;
                }
            }
            else {
                if (x <= y) {
                    if (z == -1) {
                        sum++;
                    }
                    else if (y <= z) {
                        sum++;
                    }
                }
            }
        }
    }
    cout << sum;

    return 0;
}