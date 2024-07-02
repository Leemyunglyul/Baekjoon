#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <map>
#include <set>

using namespace std;

int arr[100] = { 0 };
int check[36] = { 0 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long x, y, k, i, j;
    int num = 0;
    cin >> x >> k;
    for (i = 0; i <= 31; i++) {
        y = 1 << i;
        if (x & y) arr[i] = 1;
        if (k & y) check[i] = 1;
        //cout << i << "번째" << " " << arr[i] << " " << check[i] << endl;
       // cout << (x & y) << " " << (k & y) << endl;
    }
    i = 0; j = 0; x = 0;
    while (1) {
        if (i <= 31) {
            if (arr[i] == 1);
            else {
                if (check[j] == 1) {
                    x += (long long)1 << i;
                }
                j++;
            }
        }
        else {
            if (check[j] == 1) {
                x += (long long)1 << i;
            }
            j++;
        }
        if (j > 31) break;
       // cout << i << "번재 " << x << endl;
        i++;
    }
    cout << x;
}