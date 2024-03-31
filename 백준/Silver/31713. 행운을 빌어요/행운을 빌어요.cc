#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[3][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, test, x, y, mint, maxt, sum;
    cin >> test;
    while (test--) {
        cin >> x >> y;
        mint = 3 * x;
        maxt = 4 * x;
        sum = 0;
        if (y >= mint && y <= maxt) {
            cout << "0\n";
        }
        else if (y < mint) {
            cout << mint - y << "\n";
        }
        else if (y > maxt) {
            while (4 * x < y) {
                x++;
                sum++;
            }
            mint = 3 * x;
            maxt = 4 * x;
            if (y >= mint && y <= maxt) {
                cout << sum<<"\n";
            }
            else if (y < mint) {
                cout << mint - y+sum << "\n";
            }
        }
    }
}