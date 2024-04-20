#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <map>

using namespace std;

bool visited[12];
int arr[12][12];
int nextt[12];
int anw = 987654321;
int print[12];
int n, m;

void bit_dp(int num, int pre, int sum) {
    int i;
    if (num==n) {
        if (arr[pre][1] == 0) return;
        sum = max(sum, arr[pre][1]);
        if (sum < anw) {
            anw = sum;
            nextt[pre] = 1;
            for (i = 1; i <= n; i++) {
                print[i] = nextt[i];
            }
        }
        return;
    }
    int temp = sum;
    for (i = 1; i <= n; i++) {
        if (visited[i] || arr[pre][i] == 0) continue;
        nextt[pre] = i;
        visited[i] = true;
        temp = max(sum, arr[pre][i]);
        bit_dp(num+1, i, temp);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int i, j, x, y, d;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        arr[x][y]= d;
    }
    fill_n(&visited[0], 12,false);
    visited[1] = true;
    bit_dp(1, 1, 0);
    //cout << (1 << (n + 1)) - 2<<"//" << endl;
    if (anw == 987654321) {
        cout << "-1";
        return 0;
    }
    cout << anw << "\n";
    cout << "1 ";
    int s = print[1];
    while (s != 1) {
        cout << s << " ";
        s = print[s];
    }

    return 0;
}