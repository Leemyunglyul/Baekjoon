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

int sum[500100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testn, x, y, s, e;
    cin >> testn;
    s = 1; e = 1;
    while (testn--) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            sum[e] = sum[e - 1] + y;
            e++;
        }
        else {
            int siz = e - s;
            int mid = s + (siz / 2) - 1;
            int s1 = sum[mid] - sum[s - 1];
            int s2 = sum[e - 1] - sum[mid];
            if (s1 > s2) {
                cout << s2 << "\n";
                e = mid + 1;
            }
            else {
                cout << s1 << "\n";
                s = mid + 1;
            }
        }
    }
    for (int i = s; i < e; i++) {
        cout << sum[i] - sum[i - 1] << " ";
    }
    

    return 0;
}